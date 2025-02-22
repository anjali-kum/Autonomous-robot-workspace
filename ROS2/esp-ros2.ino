#include <Wire.h>
#include <PID_v1.h>
#include <Arduino.h>

// Motor Pin Definitions
#define DIR_RIG 12
#define PWM_RIG 13
#define DIR_LEF 27
#define PWM_LEF 14

// Encoder Pin Definitions
#define ENC_A_RIG 35
#define ENC_B_RIG 34
#define ENC_A_LEF 32
#define ENC_B_LEF 33

// Control Loop Timing
#define LOOPTIME 100  // Looptime in milliseconds

// Encoder Counts
volatile long count_rig = 0, count_lef = 0;
double speed_act_left = 0, speed_cmd_left = 0, speed_req_left = 0;
double speed_act_right = 0, speed_cmd_right = 0, speed_req_right = 0;

// Robot Parameters
const double radius = 0.0625;
const double wheelbase = 0.32;
const double max_speed = 0.03599;
const double speed_pwm = 0.00148;
const double min_speed_cmd = 0.02962;

// PWM Values
int PWM_leftMotor = 0;
int PWM_rightMotor = 0;

// PID Parameters
const double PID_left_param[] = {0.24, 0, 1};
const double PID_right_param[] = {0.24, 0, 1};
PID PID_leftMotor(&speed_act_left, &speed_cmd_left, &speed_req_left,
                  PID_left_param[0], PID_left_param[1], PID_left_param[2], DIRECT);
PID PID_rightMotor(&speed_act_right, &speed_cmd_right, &speed_req_right,
                   PID_right_param[0], PID_right_param[1], PID_right_param[2], DIRECT);

void IRAM_ATTR enc_a_rig() {
    count_rig += (digitalRead(ENC_B_RIG) == digitalRead(ENC_A_RIG)) ? -1 : 1;
}

void IRAM_ATTR enc_b_rig() {
    count_rig += (digitalRead(ENC_B_RIG) != digitalRead(ENC_A_RIG)) ? -1 : 1;
}

void IRAM_ATTR enc_a_lef() {
    count_lef += (digitalRead(ENC_B_LEF) == digitalRead(ENC_A_LEF)) ? -1 : 1;
}

void IRAM_ATTR enc_b_lef() {
    count_lef += (digitalRead(ENC_B_LEF) != digitalRead(ENC_A_LEF)) ? -1 : 1;
}

void setup() {
    Serial.begin(115200);

    pinMode(PWM_RIG, OUTPUT);
    pinMode(DIR_RIG, OUTPUT);
    pinMode(PWM_LEF, OUTPUT);
    pinMode(DIR_LEF, OUTPUT);

    pinMode(ENC_A_RIG, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENC_A_RIG), enc_a_rig, CHANGE);
    pinMode(ENC_B_RIG, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENC_B_RIG), enc_b_rig, CHANGE);

    pinMode(ENC_A_LEF, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENC_A_LEF), enc_a_lef, CHANGE);
    pinMode(ENC_B_LEF, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(ENC_B_LEF), enc_b_lef, CHANGE);

    PID_leftMotor.SetMode(AUTOMATIC);
    PID_rightMotor.SetMode(AUTOMATIC);
}

void loop() {
    static unsigned long lastMilli = 0;
    if ((millis() - lastMilli) >= LOOPTIME) {
        lastMilli = millis();

        // Compute actual speed
        speed_act_left = (count_lef / 2800.0) * 2 * PI * radius * (1000.0 / LOOPTIME);
        speed_act_right = (count_rig / 2800.0) * 2 * PI * radius * (1000.0 / LOOPTIME);
        count_lef = 0;
        count_rig = 0;

        // Run PID computations
        PID_leftMotor.Compute();
        PID_rightMotor.Compute();

        // Calculate PWM values
        PWM_leftMotor = constrain(((speed_req_left + (speed_req_left >= 0 ? 1 : -1) * min_speed_cmd) / speed_pwm) + (speed_cmd_left / speed_pwm), -255, 255);
        PWM_rightMotor = constrain(((speed_req_right + (speed_req_right >= 0 ? 1 : -1) * min_speed_cmd) / speed_pwm) + (speed_cmd_right / speed_pwm), -255, 255);

        // Apply motor controls
        analogWrite(PWM_LEF, abs(PWM_leftMotor));
        digitalWrite(DIR_LEF, PWM_leftMotor > 0 ? HIGH : LOW);

        analogWrite(PWM_RIG, abs(PWM_rightMotor));
        digitalWrite(DIR_RIG, PWM_rightMotor > 0 ? HIGH : LOW);

        // Send encoder data
        Serial.print("ENC ");
        Serial.print(speed_act_left);
        Serial.print(" ");
        Serial.println(speed_act_right);
    }

    // Process incoming commands
    if (Serial.available()) {
        String cmd = Serial.readStringUntil('\n');
        cmd.trim();

        if (cmd.equals("RESET")) {
            count_lef = 0;
            count_rig = 0;
        } else if (cmd.startsWith("linear:") || cmd.startsWith("angular:")) {
            process_cmd_vel(cmd);
        }
    }
}

void process_cmd_vel(String command) {
    int linear_pos = command.indexOf("linear:");
    int angular_pos = command.indexOf("angular:");

    if (linear_pos != -1 && angular_pos != -1) {
        double linear_x = command.substring(linear_pos + 7, command.indexOf(' ', linear_pos)).toDouble();
        double angular_z = command.substring(angular_pos + 8).toDouble();

        speed_req_left = linear_x - angular_z * (wheelbase / 2);
        speed_req_right = linear_x + angular_z * (wheelbase / 2);
    }
}

