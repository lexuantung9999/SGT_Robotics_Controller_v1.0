#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define PCA_ADDRESS 0x41

class ServoControl {
private:
    Adafruit_PWMServoDriver pwm;

    uint8_t maxChannel;
    uint16_t minPulse;
    uint16_t maxPulse;

public:
    ServoControl();

    // Initialize PCA9685
    void begin(uint16_t frequency = 50);

    // Set servo angle
    void writeAngle(uint8_t channel, float angle);

    // Disable PWM output
    void stop(uint8_t channel);

    // Update pulse range
    void setPulseRange(uint16_t minVal, uint16_t maxVal);

    // Set total channel count
    void setChannelCount(uint8_t channels);
};

#endif