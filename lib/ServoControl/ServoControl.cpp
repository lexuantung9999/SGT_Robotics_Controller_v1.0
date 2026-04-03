#include "ServoControl.h"

ServoControl::ServoControl()
#if USE_PCA9685_SERVO_DRIVER
    : pwm(PCA_ADDRESS)
#endif
{
#if USE_PCA9685_SERVO_DRIVER
    maxChannel = 8;
#else
    maxChannel = 6;
#endif

    // Default pulse range for common servos
    minPulse = 1000; // us
    maxPulse = 2000; // us

#if !USE_PCA9685_SERVO_DRIVER
    for (uint8_t i = 0; i < 16; i++) {
        servoPins[i] = 255; // invalid pin
    }
#endif
}

void ServoControl::begin(uint16_t frequency)
{
#if USE_PCA9685_SERVO_DRIVER

    pwm.begin();
    pwm.setPWMFreq(frequency);

#else

    for (uint8_t ch = 0; ch < maxChannel; ch++) {
        ledcSetup(ch, frequency, 16);
    }

#endif

    delay(10);
}

void ServoControl::attachPin(uint8_t channel, uint8_t pin)
{
#if !USE_PCA9685_SERVO_DRIVER
    if (channel >= 16) return;

    servoPins[channel] = pin;
    ledcAttachPin(pin, channel);
#endif
}

void ServoControl::writeAngle(uint8_t channel, float angle)
{
    if (channel >= maxChannel) return;

    angle = constrain(angle, 0, 180);

    uint16_t pulse_us = map(
        (int)angle,
        0,
        180,
        minPulse,
        maxPulse
    );

#if USE_PCA9685_SERVO_DRIVER

    pwm.writeMicroseconds(channel, pulse_us);

#else

    uint32_t duty = map(
        pulse_us,
        0,
        20000,   // 20 ms period at 50 Hz
        0,
        65535
    );

    ledcWrite(channel, duty);

#endif
}

void ServoControl::stop(uint8_t channel)
{
    if (channel >= maxChannel) return;

#if USE_PCA9685_SERVO_DRIVER

    pwm.setPWM(channel, 0, 0);

#else

    ledcWrite(channel, 0);

#endif
}

void ServoControl::setPulseRange(uint16_t minVal, uint16_t maxVal)
{
    minPulse = minVal;
    maxPulse = maxVal;
}

void ServoControl::setChannelCount(uint8_t channels)
{
    maxChannel = channels;
}