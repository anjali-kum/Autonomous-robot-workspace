#include <Wire.h>
#include <LedControl.h>
#include <ArduinoJson.h>

// Define motor pins
#define DIR1 5
#define PWM1 6
#define DIR2 7
#define PWM2 8

// Define I2C address and character variable
char g = 'e';  // Initialize to 'e' for stop

// Define LED control pins and setup
int DIN = 2;
int CS = 3;
int CLK = 4;
LedControl lc = LedControl(DIN, CLK, CS, 8); // Set the number of devices here

unsigned long currentTime;
unsigned long lastUpdateTime = 0;
const long eyesDelay = 500;  // Delay for eyes animation
const long emptyDelay = 500; // Delay for empty state

// Pattern definitions
byte eyesPatterns[8][8] = {
    {0x00,0x00,0xC0,0xF0,0xF8,0xF8,0xFC,0xFC},
    {0x00,0x00,0x03,0x0F,0x1F,0x1F,0x33,0x31},
    {0x00,0x00,0xC0,0xF0,0xF8,0xF8,0xCC,0x8C},
    {0x00,0x00,0x03,0x0F,0x1F,0x1F,0x3F,0x3F},
    {0x00,0x00,0xC0,0xF0,0xF8,0xF8,0xFC,0xFC},
    {0x00,0x00,0x03,0x0F,0x1F,0x1F,0x33,0x39},
    {0x00,0x00,0xC0,0xF0,0xF8,0xF8,0xCC,0x9C},
    {0x00,0x00,0x03,0x0F,0x1F,0x1F,0x3F,0x3F}
};

byte emptyPattern[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

void setup() {
    // Motor setup
    pinMode(DIR1, OUTPUT);
    pinMode(PWM1, OUTPUT);
    pinMode(DIR2, OUTPUT);
    pinMode(PWM2, OUTPUT);

    Serial.begin(9600);

    // Initialize I2C communications as a slave with address 8
    Wire.begin(8);
    Wire.onReceive(receiveEvent);  // Register receive event
    Wire.onRequest(requestEvent);  // Register request event

    // Initialize LED display
    for (int i = 0; i < 8; i++) {
        lc.shutdown(i, false);
        lc.setIntensity(i, 5);
        lc.clearDisplay(i);
    }
}

void loop() {
    // Handle motor direction based on the value of g
    if (g == 'a') {
        forward();
        Serial.println("Forward");
    } else if (g == 'b') {
        backward();
        Serial.println("Backward");
    } else if (g == 'c') {
        right();
        Serial.println("Right");
    } else if (g == 'd') {
        left();
        Serial.println("Left");
    } else if (g == 'e') {
        dc_stop();
        Serial.println("Stop");
    }

    // Handle LED display animations
    currentTime = millis();
    if (currentTime - lastUpdateTime >= eyesDelay && (currentTime - lastUpdateTime) < (eyesDelay + emptyDelay)) {
        showEyes();
    } else if (currentTime - lastUpdateTime >= (eyesDelay + emptyDelay)) {
        showEmpty();
        lastUpdateTime = currentTime; // Reset lastUpdateTime after displaying empty state
    }
}

void forward() {
    analogWrite(PWM1, 120);
    analogWrite(PWM2, 120);
    digitalWrite(DIR1, HIGH);
    digitalWrite(DIR2, HIGH);
}

void backward() {
    analogWrite(PWM1, 120);
    analogWrite(PWM2, 120);
    digitalWrite(DIR1, LOW);
    digitalWrite(DIR2, LOW);
}

void left() {
    analogWrite(PWM1, 60);
    analogWrite(PWM2, 60);
    digitalWrite(DIR1, HIGH);  // low
    digitalWrite(DIR2, LOW); // high
}

void right() {
    analogWrite(PWM1, 60);
    analogWrite(PWM2, 60);
    digitalWrite(DIR1, LOW);  // low
    digitalWrite(DIR2, HIGH); // high
}

void dc_stop() {
    analogWrite(PWM1, 0);
    analogWrite(PWM2, 0);
    digitalWrite(DIR1, HIGH);
    digitalWrite(DIR2, HIGH);
}

// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
    while (Wire.available()) {
        g = Wire.read();  // Receive byte as a character
    }
}

// Function that executes whenever data is requested from master
void requestEvent() {
    Wire.write("Hello NodeMCU");  // Send string on request
}

void showEyes() {
    for (int i = 0; i < 8; i++) {
        for (int row = 0; row < 8; row++) {
            lc.setRow(i, row, eyesPatterns[i][row]);
        }
    }
}

void showEmpty() {
    for (int i = 0; i < 8; i++) {
        for (int row = 0; row < 8; row++) {
            lc.setRow(i, row, emptyPattern[row]);
        }
    }
}
