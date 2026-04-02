#include "MotorControl.h"

MotorControl::MotorControl() {
    pinA = nullptr;
    pinB = nullptr;
    motorCount = 0;
    pwmFreq = 5000;
}

void MotorControl::config(const uint8_t* pinsA,
                          const uint8_t* pinsB,
                          uint8_t count) {
    pinA = pinsA;
    pinB = pinsB;
    motorCount = count;
}

void MotorControl::begin(uint32_t frequency) {
    pwmFreq = frequency;

    mcpwm_config_t pwm_config;
    pwm_config.frequency = pwmFreq;
    pwm_config.cmpr_a = 0;
    pwm_config.cmpr_b = 0;
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;

    for (uint8_t i = 0; i < motorCount; i++) {
        mcpwm_unit_t unit = (i < 3) ? MCPWM_UNIT_0 : MCPWM_UNIT_1;
        mcpwm_timer_t timer = (mcpwm_timer_t)(i % 3);

        mcpwm_io_signals_t signalA;
        mcpwm_io_signals_t signalB;

        // Explicit signal mapping for stable MCPWM channel assignment
        if (unit == MCPWM_UNIT_0) {
            switch (timer) {
                case MCPWM_TIMER_0:
                    signalA = MCPWM0A;
                    signalB = MCPWM0B;
                    break;

                case MCPWM_TIMER_1:
                    signalA = MCPWM1A;
                    signalB = MCPWM1B;
                    break;

                case MCPWM_TIMER_2:
                    signalA = MCPWM2A;
                    signalB = MCPWM2B;
                    break;

                default:
                    return;
            }
        } else {
            switch (timer) {
                case MCPWM_TIMER_0:
                    signalA = MCPWM0A;
                    signalB = MCPWM0B;
                    break;

                case MCPWM_TIMER_1:
                    signalA = MCPWM1A;
                    signalB = MCPWM1B;
                    break;

                case MCPWM_TIMER_2:
                    signalA = MCPWM2A;
                    signalB = MCPWM2B;
                    break;

                default:
                    return;
            }
        }

        mcpwm_gpio_init(unit, signalA, pinA[i]);
        mcpwm_gpio_init(unit, signalB, pinB[i]);

        mcpwm_init(unit, timer, &pwm_config);
    }
}

// speed: -100 to 100
void MotorControl::runMotor(uint8_t id, float speed) {
    if (id >= motorCount) return;

    speed = constrain(speed, -100, 100);
    float duty = abs(speed);

    mcpwm_unit_t unit = (id < 3) ? MCPWM_UNIT_0 : MCPWM_UNIT_1;
    mcpwm_timer_t timer = (mcpwm_timer_t)(id % 3);

    if (speed > 0) {
        mcpwm_set_duty(unit, timer, MCPWM_OPR_A, duty);
        mcpwm_set_duty(unit, timer, MCPWM_OPR_B, 0);
    }
    else if (speed < 0) {
        mcpwm_set_duty(unit, timer, MCPWM_OPR_A, 0);
        mcpwm_set_duty(unit, timer, MCPWM_OPR_B, duty);
    }
    else {
        mcpwm_set_duty(unit, timer, MCPWM_OPR_A, 0);
        mcpwm_set_duty(unit, timer, MCPWM_OPR_B, 0);
    }
}

// speed: -100 to 100
void MotorControl::runAll(float speed) {
    for (uint8_t i = 0; i < motorCount; i++) {
        runMotor(i, speed);
    }
}

void MotorControl::stopMotor(uint8_t id) {
    runMotor(id, 0);
}

void MotorControl::stopAll() {
    for (uint8_t i = 0; i < motorCount; i++) {
        stopMotor(i);
    }
}