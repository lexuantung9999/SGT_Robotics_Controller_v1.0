#include <Arduino.h>
#include "BoardConfig_V1_0.h"
#include "MotorControl.h"

MotorControl motor;

void setup() {
    Serial.begin(115200);

    motor.config(
        MOTOR_PIN_A,
        MOTOR_PIN_B,
        MOTOR_COUNT
    );

    motor.begin(MOTOR_PWM_FREQ);
}

void loop() {
    // turnCW 3s
    motor.runAll(60);
    delay(3000);

    // Stop 1s
    motor.stopAll();
    delay(1000);

    // turnCCW 3s
    motor.runAll(-60);
    delay(3000);

    // Stop 1s
    motor.stopAll();
    delay(1000);
}