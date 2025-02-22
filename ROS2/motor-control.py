import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from geometry_msgs.msg import Twist
import serial
import time
import math

class MotorControlNode(Node):
    def __init__(self):
        super().__init__('motor_control_node')

        self.serial_port = '/dev/serial/by-id/usb-1a86_USB_Single_Serial_5767007507-if00'
        self.baud_rate = 115200
        self.wheel_radius = 0.0625
        self.wheel_base = 0.42
        self.ticks_per_revolution = 695  

        try:
            self.serial_conn = serial.Serial(self.serial_port, self.baud_rate, timeout=1)
            self.get_logger().info(f"Connected to {self.serial_port} at {self.baud_rate} baud.")
        except Exception as e:
            self.get_logger().error(f"Error opening serial port: {str(e)}")
            raise

        # Reset encoders to ensure motors are stopped at startup
        self.reset_encoders()
        time.sleep(0.1)  # Give ESP32 time to process reset

        self.encoder_pub = self.create_publisher(JointState, 'joint_states', 10)
        self.create_subscription(Twist, 'cmd_vel', self.cmd_vel_callback, 10)
        self.create_timer(0.05, self.read_encoder_data)

        self.prev_left_ticks = 0
        self.prev_right_ticks = 0
        self.prev_time = time.time()

        self.last_linear_x = 0  # Store last sent linear velocity
        self.last_angular_z = 0  # Store last sent angular velocity

    def reset_encoders(self):
        """Send a reset signal to ESP32 to stop motors."""
        try:
            self.serial_conn.write(b"RESET\n")
            self.get_logger().info("Sent RESET signal to ESP32.")
        except Exception as e:
            self.get_logger().error(f"Failed to send RESET signal: {str(e)}")

    def cmd_vel_callback(self, msg):
        """Process incoming velocity commands and send to ESP32."""
        linear_x = int(msg.linear.x * 255)
        angular_z = int(msg.angular.z * 255)

        # Avoid sending redundant commands if the speed has not changed
        if linear_x == self.last_linear_x and angular_z == self.last_angular_z:
            return  # Skip sending duplicate commands

        # Store the new velocities to compare next time
        self.last_linear_x = linear_x
        self.last_angular_z = angular_z

        command = f"linear:{linear_x} angular:{angular_z}\n"
        
        try:
            self.serial_conn.write(command.encode())
            self.get_logger().info(f"Sent command: {command.strip()}")
        except Exception as e:
            self.get_logger().error(f"Error sending command: {str(e)}")

    def read_encoder_data(self):
        """Read encoder values from ESP32 and publish as joint states."""
        if self.serial_conn.in_waiting > 0:
            try:
                line = self.serial_conn.readline().decode(errors='ignore').strip()

                if line.startswith("ENC"):
                    _, left_ticks, right_ticks = line.split()
                    left_ticks = float(left_ticks)
                    right_ticks = float(right_ticks)

                    current_time = time.time()
                    dt = current_time - self.prev_time
                    self.prev_time = current_time

                    left_distance = 2 * math.pi * self.wheel_radius * (left_ticks - self.prev_left_ticks) / self.ticks_per_revolution
                    right_distance = 2 * math.pi * self.wheel_radius * (right_ticks - self.prev_right_ticks) / self.ticks_per_revolution

                    self.prev_left_ticks = left_ticks
                    self.prev_right_ticks = right_ticks

                    v = (left_distance + right_distance) / (2 * dt)
                    omega = (right_distance - left_distance) / (self.wheel_base * dt)

                    joint_msg = JointState()
                    joint_msg.header.stamp = self.get_clock().now().to_msg()
                    joint_msg.name = ['left_wheel_joint', 'right_wheel_joint']
                    joint_msg.position = [left_ticks, right_ticks]
                    joint_msg.velocity = [v - omega * self.wheel_base / 2, v + omega * self.wheel_base / 2]
                    self.encoder_pub.publish(joint_msg)
            except Exception as e:
                self.get_logger().error(f"Error processing encoder data: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = MotorControlNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

