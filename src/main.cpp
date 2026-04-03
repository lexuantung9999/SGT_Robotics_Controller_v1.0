#include <Arduino.h>

#include "BoardConfig_mini.h"
#include "MotorControl.h"
#include "ServoControl.h"

MotorControl motor;
ServoControl servo;

void setup()
{
    Serial.begin(115200);

    // Motor init
    motor.config(MOTOR_PIN_A, MOTOR_PIN_B, MOTOR_COUNT);
    motor.begin(MOTOR_PWM_FREQ);

    // Servo init
    servo.setChannelCount(6);
    servo.begin();

    Serial.println("Mini Controller Board initialized.");
}

void loop()
{
    // Forward
    motor.runAll(50);

    servo.writeAngle(0, 0);
    servo.writeAngle(1, 0);

    Serial.println("Running forward at 50%, servos at 0 deg");
    delay(3000);

    // Stop + 90 degree
    motor.stopAll();

    servo.writeAngle(0, 90);
    servo.writeAngle(1, 90);

    Serial.println("Motors stopped, servos at 90 deg");
    delay(3000);

    // Backward
    motor.runAll(-50);

    servo.writeAngle(0, 0);
    servo.writeAngle(1, 0);

    Serial.println("Running backward at 50%, servos at 0 deg");
    delay(3000);

    // Stop
    motor.stopAll();

    servo.writeAngle(0, 90);
    servo.writeAngle(1, 90);

    Serial.println("Motors stopped, servos at 90 deg");
    delay(3000);
}