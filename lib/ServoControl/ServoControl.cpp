#include "ServoControl.h"

ServoControl::ServoControl()
    : pwm(PCA_ADDRESS) {
    maxChannel = 8;

    // Default pulse range for common servos
    minPulse = 1000; //ms
    maxPulse = 2000; //ms
}

void ServoControl::begin(uint16_t frequency) {
    pwm.begin();
    pwm.setPWMFreq(frequency);

    delay(10);
}

void ServoControl::writeAngle(uint8_t channel, float angle) {
    if (channel >= maxChannel) return;

    angle = constrain(angle, 0, 180);

    // Map angle to pulse width in microseconds
    uint16_t pulse_us = map((int)angle, 0, 180, 500, 2500);

    pwm.writeMicroseconds(channel, pulse_us);
}

void ServoControl::stop(uint8_t channel) {
    if (channel >= maxChannel) return;

    pwm.setPWM(channel, 0, 0);
}

void ServoControl::setPulseRange(uint16_t minVal, uint16_t maxVal) {
    minPulse = minVal;
    maxPulse = maxVal;
}

void ServoControl::setChannelCount(uint8_t channels) {
    maxChannel = channels;
}