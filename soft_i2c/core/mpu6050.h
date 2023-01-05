#ifndef __MPU6050_H
#define __MPU6050_H

#include"i2c.h"
#include"delay.h"


#define     PWR_MGMT_1      0x6b
#define     SMPLRT_DIV      0x19
#define     CONFIG          0x1a
#define     GYRO_CONFIG     0x1b
#define     ACCEL_CONFIG    0x1c

#define     WHO_AM_I        0x75

#define     ACCEL_XOUT_H    0x3b
#define     GYRO_XOUT_H     0x43
#define     TEMP_OUT_H      0x41

#define     MPU6050_ADDR    (0x68<<1)


void mpu6050_config(void);
uint8_t mpu6050_readID();
void mpu6050_read_accel(uint16_t *pData);
void mpu6050_read_gyro(uint16_t *pData);

uint8_t mpu6050_read_accel_xH();
uint8_t mpu6050_read_accel_xL();
uint8_t mpu6050_read_accel_zH();
uint8_t mpu6050_read_accel_zL();




#endif

