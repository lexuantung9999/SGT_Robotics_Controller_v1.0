#ifndef BOARD_CONFIG_V1_0_H
#define BOARD_CONFIG_V1_0_H

#include <Arduino.h>

// =====================================================
// Board Information
// =====================================================
#define BOARD_NAME                  "ControlBoard"
#define BOARD_VERSION_MAJOR         1
#define BOARD_VERSION_MINOR         0

// =====================================================
// DC Motor Ports
// Each motor port uses 2 pins: A / B
// =====================================================
#define M1_PIN_A                   17
#define M1_PIN_B                   18

#define M2_PIN_A                   15
#define M2_PIN_B                   16

#define M3_PIN_A                   8
#define M3_PIN_B                   9

#define M4_PIN_A                   10
#define M4_PIN_B                   11

#define M5_PIN_A                   12
#define M5_PIN_B                   13

#define M6_PIN_A                   14
#define M6_PIN_B                   21

#define MOTOR_COUNT 6
#define MOTOR_PWM_FREQ             5000

static const uint8_t MOTOR_PIN_A[MOTOR_COUNT] = {
    M1_PIN_A, M2_PIN_A, M3_PIN_A, M4_PIN_A, M5_PIN_A, M6_PIN_A
};

static const uint8_t MOTOR_PIN_B[MOTOR_COUNT] = {
    M1_PIN_B, M2_PIN_B, M3_PIN_B, M4_PIN_B, M5_PIN_B, M6_PIN_B
};

// =====================================================
// IMU Interface (I2C Bus 1)
// =====================================================
#define IMU_I2C_SDA                35
#define IMU_I2C_SCL                36

// =====================================================
// PCA9685 Servo Driver (I2C Bus 2)
// =====================================================
#define SERVO_I2C_SDA              1
#define SERVO_I2C_SCL              2

#define SERVO_CH0                  0
#define SERVO_CH1                  1
#define SERVO_CH2                  2
#define SERVO_CH3                  3
#define SERVO_CH4                  4
#define SERVO_CH5                  5
#define SERVO_CH6                  6
#define SERVO_CH7                  7

#define SERVO_CHANNEL_MAX          8

// =====================================================
// RS485 UART Interface
// =====================================================
#define RS485_TXD                  37
#define RS485_RXD                  38

// =====================================================
// Digital GPIO Input Ports
// =====================================================
#define GPIO_PORT_1                39
#define GPIO_PORT_2                40
#define GPIO_PORT_3                47
#define GPIO_PORT_4                48

// =====================================================
// Encoder Ports
// Each encoder uses 2 channels: A / B
// =====================================================
#define ENCODER_1_A                4
#define ENCODER_1_B                5

#define ENCODER_2_A                6
#define ENCODER_2_B                7

#endif