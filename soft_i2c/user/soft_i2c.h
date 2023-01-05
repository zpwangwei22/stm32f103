#ifndef __SOFT_I2C_H
#define __SOFT_I2C_H

#include"stm32f10x.h"
#include"delay.h"
#include"my_usart.h"

#define     I2C_GPIO_PORT       GPIOB
#define     I2C_GPIO_SCL        GPIO_Pin_10
#define     I2C_GPIO_SDA        GPIO_Pin_11

#define     SCL_H       GPIO_SetBits(GPIOB, GPIO_Pin_10)
#define     SCL_L       GPIO_ResetBits(GPIOB, GPIO_Pin_10)

#define     SDA_H       GPIO_SetBits(GPIOB, GPIO_Pin_11)
#define     SDA_L       GPIO_ResetBits(GPIOB, GPIO_Pin_11)
#define     SDA_READ    GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)

#define     I2C_FLAG_READ       ((uint8_t)0x01)
#define     I2C_FLAG_WRITE      ((uint8_t)0x00)


void I2C_GPIO_Init(void);
void SDA_Mode_Output(void);
void SDA_Mode_Input(void);
void Soft_I2C_GenerateStart(void);
void Soft_I2C_GenerateStop(void);
void Soft_I2C_GenerateACK(void);
void Soft_I2C_GenerateNACK(void);
uint8_t Soft_I2C_WaitACK();
void Soft_I2C_SendData(uint8_t WriteData);
uint8_t Soft_I2C_ReceiveData(void);
void Soft_I2C_Send7bitADDR(uint8_t Address, uint8_t Flag_Dir);
uint8_t I2C_RegWrite(uint8_t slave_addr, uint8_t reg_addr, uint8_t data);
uint8_t I2C_Burst_Read(uint8_t slave_addr, uint8_t reg_addr, uint8_t *pData, uint8_t num);





#endif







