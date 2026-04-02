#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>
#include "driver/mcpwm.h"

class MotorControl {
private:
    const uint8_t* pinA;
    const uint8_t* pinB;

    uint8_t motorCount;
    uint32_t pwmFreq;

public:
    MotorControl();

    void config(const uint8_t* pinsA,
                const uint8_t* pinsB,
                uint8_t count);

    void begin(uint32_t frequency);

    void runMotor(uint8_t id, float speed);
    void runAll(float speed);

    void stopMotor(uint8_t id);
    void stopAll();
};

#endif