#include <Arduino.h>
#include <Wire.h>

#include "BoardConfig_V1_0.h"
#include "MotorControl.h"
#include "ServoControl.h"

MotorControl motor;
ServoControl servo;

TwoWire I2C_SERVO = TwoWire(1);

void scanI2C() {
    Serial.println("Scanning I2C bus...");

    uint8_t found = 0;

    for (uint8_t addr = 1; addr < 127; addr++) {
        Wire.beginTransmission(addr);

        if (Wire.endTransmission() == 0) {
            Serial.print("Found device at 0x");
            if (addr < 16) Serial.print("0");
            Serial.println(addr, HEX);

            found++;
        }
    }

    if (found == 0) {
        Serial.println("No I2C device found.");
    } else {
        Serial.println("Scan complete.");
    }
}

void setup() {
    Serial.begin(115200);

    // Motor init
    motor.config(MOTOR_PIN_A, MOTOR_PIN_B, MOTOR_COUNT);
    motor.begin(MOTOR_PWM_FREQ);

    // Initialize default I2C bus on custom pins
    Wire.begin(SERVO_I2C_SDA, SERVO_I2C_SCL);

    delay(100);

    scanI2C();

    
    servo.setChannelCount(SERVO_CHANNEL_MAX);
    servo.begin();
}

void loop() {
    // Run all motors forward
    motor.runAll(50);
    // Servo: 0° -> 30°
    servo.writeAngle(0, 0);
    servo.writeAngle(1, 0);
    delay(3000);

    motor.stopAll();
    servo.writeAngle(0, 90);
    servo.writeAngle(1, 90);
    delay(3000);

    // Return to 0°
    motor.runAll(-50);
    servo.writeAngle(0, 0);
    servo.writeAngle(1, 0);
    delay(3000);

    // Move back to 30°
    motor.stopAll();
    servo.writeAngle(0, 90);
    servo.writeAngle(1, 90);
    delay(3000);
}