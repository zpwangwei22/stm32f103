#include"mpu6050.h"

void mpu6050_config(void)
{
    delay(100);
    I2C_RegWrite(MPU6050_ADDR, PWR_MGMT_1, 0x00);
    I2C_RegWrite(MPU6050_ADDR, SMPLRT_DIV, 0x07);
    I2C_RegWrite(MPU6050_ADDR, CONFIG, 0x06);
    I2C_RegWrite(MPU6050_ADDR, GYRO_CONFIG, 0x18);
    I2C_RegWrite(MPU6050_ADDR, ACCEL_CONFIG, 0x00);
    delay(100);

}

uint8_t mpu6050_readID()
{   uint8_t tmp;
    I2C_Burst_Read(MPU6050_ADDR, WHO_AM_I, &tmp, 1);
    return tmp;
}
/*
uint8_t mpu6050_read_accel_xH()
{
    return i2c_byte_read(MPU6050_ADDR, 0x3b); 
}
uint8_t mpu6050_read_accel_xL()
{
    return i2c_byte_read(MPU6050_ADDR, 0x3c); 
}
uint8_t mpu6050_read_accel_zH()
{
    return i2c_byte_read(MPU6050_ADDR, 0x3f); 
}
uint8_t mpu6050_read_accel_zL()
{
    return i2c_byte_read(MPU6050_ADDR, 0x40); 
}

*/

void mpu6050_read_accel(short *pData)
{
    uint8_t Buff[6] = {0};
    I2C_Burst_Read(MPU6050_ADDR, ACCEL_XOUT_H, Buff, 6);
    pData[0] = (Buff[0] << 8) | Buff[1];
    pData[1] = (Buff[2] << 8) | Buff[3];
    pData[2] = (Buff[4] << 8) | Buff[5];
}

void mpu6050_read_gyro(short *pData)
{
    uint8_t Buff[6] = {0};
    I2C_Burst_Read(MPU6050_ADDR, GYRO_XOUT_H, Buff, 6);
    pData[0] = (Buff[0] << 8) | Buff[1];
    pData[1] = (Buff[2] << 8) | Buff[3];
    pData[2] = (Buff[4] << 8) | Buff[5];
}


