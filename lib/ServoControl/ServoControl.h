#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define PCA_ADDRESS 0x41
#define USE_PCA9685_SERVO_DRIVER 0

class ServoControl {
private:

#if USE_PCA9685_SERVO_DRIVER
    Adafruit_PWMServoDriver pwm;
#else
    uint8_t servoPins[16];
#endif

    uint8_t maxChannel;
    uint16_t minPulse;
    uint16_t maxPulse;

public:
    ServoControl();

    // Initialize servo driver / PWM channels
    void begin(uint16_t frequency = 50);

#if !USE_PCA9685_SERVO_DRIVER
    // Attach GPIO pin to channel (for direct PWM mode)
    void attachPin(uint8_t channel, uint8_t pin);
#endif

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