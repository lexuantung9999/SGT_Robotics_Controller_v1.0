#ifndef BOARD_CONFIG_V1_0_H
#define BOARD_CONFIG_V1_0_H

#include <Arduino.h>

// =====================================================
// Board Information
// =====================================================
#define BOARD_NAME                  "ControlBoardMini"
#define BOARD_VERSION_MAJOR         1
#define BOARD_VERSION_MINOR         0

// =====================================================
// DC Motor Ports
// Each motor port uses 2 pins: A / B
// =====================================================
#define M1_PIN_A                   15
#define M1_PIN_B                   16

#define M2_PIN_A                   17
#define M2_PIN_B                   18

#define M3_PIN_A                   8
#define M3_PIN_B                   9

#define M4_PIN_A                   10
#define M4_PIN_B                   11

#define MOTOR_COUNT                4
#define MOTOR_PWM_FREQ             5000

static const uint8_t MOTOR_PIN_A[MOTOR_COUNT] = {
    M1_PIN_A, M2_PIN_A, M3_PIN_A, M4_PIN_A
};

static const uint8_t MOTOR_PIN_B[MOTOR_COUNT] = {
    M1_PIN_B, M2_PIN_B, M3_PIN_B, M4_PIN_B
};

// =====================================================
// IMU Interface (I2C)
// =====================================================
#define IMU_I2C_SDA                35
#define IMU_I2C_SCL                36

// =====================================================
// Servo GPIO Ports
// Direct PWM output
// =====================================================
#define SERVO_1_PIN                37
#define SERVO_2_PIN                38
#define SERVO_3_PIN                39
#define SERVO_4_PIN                40
#define SERVO_5_PIN                41
#define SERVO_6_PIN                42

#define SERVO_COUNT                6

static const uint8_t SERVO_PINS[SERVO_COUNT] = {
    SERVO_1_PIN,
    SERVO_2_PIN,
    SERVO_3_PIN,
    SERVO_4_PIN,
    SERVO_5_PIN,
    SERVO_6_PIN
};

// =====================================================
// Digital GPIO Input Ports
// =====================================================
#define GPIO_INPUT_1               14
#define GPIO_INPUT_2               21
#define GPIO_INPUT_3               47
#define GPIO_INPUT_4               48

#define GPIO_INPUT_COUNT           4

static const uint8_t GPIO_INPUT_PINS[GPIO_INPUT_COUNT] = {
    GPIO_INPUT_1,
    GPIO_INPUT_2,
    GPIO_INPUT_3,
    GPIO_INPUT_4
};

// =====================================================
// Encoder Ports
// Each encoder uses 2 channels: A / B
// =====================================================
#define ENCODER_1_A                7
#define ENCODER_1_B                6

#define ENCODER_2_A                13
#define ENCODER_2_B                12

// =====================================================
// Onboard Devices
// =====================================================
#define LED_ONBOARD                4
#define USER_BUTTON                2

#endif