#include"soft_i2c.h"


void I2C_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStruct.GPIO_Pin = I2C_GPIO_SCL | I2C_GPIO_SDA;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_Init(I2C_GPIO_PORT, &GPIO_InitStruct);

}

void SDA_Mode_Output(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = I2C_GPIO_SDA;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_Init(I2C_GPIO_PORT, &GPIO_InitStruct);

}

void SDA_Mode_Input(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = I2C_GPIO_SDA;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(I2C_GPIO_PORT, &GPIO_InitStruct);

}

void Soft_I2C_GenerateStart(void)
{
    SDA_Mode_Output();
    SCL_H;
    SDA_H;
    delay_us(5);
    SDA_L;
    delay_us(5);
    SCL_L;
    delay_us(5);
}

void Soft_I2C_GenerateStop(void)
{
    SDA_Mode_Output();
    SCL_L;
    SDA_L;
    delay_us(5);
    SCL_H;
    delay_us(5);
    SDA_H;
    delay_us(5);
}

void Soft_I2C_GenerateACK(void)
{
    SDA_Mode_Output();
    SCL_L;
    SDA_L;
    delay_us(5);
    SCL_H;
    delay_us(5);
    SCL_L;
}

void Soft_I2C_GenerateNACK(void)
{
    SCL_L;
    SDA_Mode_Output();
    SDA_H;
    delay_us(5);
    SCL_H;
    delay_us(5);
    SCL_L;
}

uint8_t Soft_I2C_WaitACK()
{
    volatile uint8_t TimeWait = 0;
    SCL_H;
    SDA_Mode_Input();
    delay_us(4);
    while(SDA_READ)
    {
        TimeWait++;
        if(TimeWait > 250)
        {
//            I2C_GenerateStop();
            return 1;
        }
    }
    SCL_L;
    delay_us(5);
    return 0;
}

void Soft_I2C_SendData(uint8_t WriteData)
{
    SCL_L;
    delay_us(5);
    for(uint8_t i = 0; i < 8; i++)
    {
        SDA_Mode_Output();
        if((WriteData << i) & 0x80)
        {
            SDA_H;
        }
        else
            SDA_L;
        delay_us(5);
        SCL_H;
        delay_us(5);
        SCL_L;
        if(i == 7)
        {
            SDA_H;
        }
        delay_us(5);
    }

}

uint8_t Soft_I2C_ReceiveData(void)
{
    uint8_t tmp = 0;
    for(uint8_t i = 0; i < 8; i++)
    {
        SDA_Mode_Input();
        SCL_H;
        delay_us(5);
        tmp <<= 1;
        if(SDA_READ == 1)
            tmp |= 0x01;
        SCL_L;
        delay_us(5);
    }

    return tmp;
}


void Soft_I2C_Send7bitADDR(uint8_t Address, uint8_t Flag_Dir)
{
    Soft_I2C_SendData(Address | Flag_Dir);
}

uint8_t I2C_RegWrite(uint8_t slave_addr, uint8_t reg_addr, uint8_t data)
{
    volatile uint8_t Timeout = 0xff;
    Soft_I2C_GenerateStart();
    Soft_I2C_Send7bitADDR(slave_addr, I2C_FLAG_WRITE);
    while(Soft_I2C_WaitACK())
    {
        if((Timeout--) == 0)
        {
            printf("error:1\r\n");
            Soft_I2C_GenerateStop();
            return 1;
        }
    }
    Soft_I2C_SendData(reg_addr);
    Timeout = 0xff;
    while(Soft_I2C_WaitACK())
    {
        if((Timeout--) == 0)
        {
            printf("error:2\r\n");
            Soft_I2C_GenerateStop();
            return 1;
        }
    }
    Soft_I2C_SendData(data);
    Timeout = 0xff;
    while(Soft_I2C_WaitACK())
    {
        if((Timeout--) == 0)
        {
            printf("error:3\r\n");
            Soft_I2C_GenerateStop();
            return 1;
        }
    }
    Soft_I2C_GenerateStop();

    return 0;
}

uint8_t I2C_Burst_Read(uint8_t slave_addr, uint8_t reg_addr, uint8_t *pData, uint8_t num)
{
    Soft_I2C_GenerateStart();
    Soft_I2C_Send7bitADDR(slave_addr, I2C_FLAG_WRITE);
    volatile uint8_t Timeout = 0xff;
    while(Soft_I2C_WaitACK())
    {
        if((Timeout--) == 0)
        {
            printf("error: 4\r\n");
            Soft_I2C_GenerateStop();
            return 1;
        }
    }
    Soft_I2C_SendData(reg_addr);
    Timeout = 0xff;
    while(Soft_I2C_WaitACK())
    {
        if((Timeout--) == 0)
        {
            printf("error: 5\r\n");
            Soft_I2C_GenerateStop();
            return 1;
        }
    }

    Soft_I2C_GenerateStart();
    Soft_I2C_Send7bitADDR(slave_addr, I2C_FLAG_READ);
    Timeout = 0xff;
    while(Soft_I2C_WaitACK())
    {
        if((Timeout--) == 0)
        {
            printf("error: 6\r\n");
            Soft_I2C_GenerateStop();
            return 1;
        }
    }

    for(uint8_t i = 0; i < (num - 1); i++)
    {
        *pData = Soft_I2C_ReceiveData();
        Soft_I2C_GenerateACK();
        pData++;
    }
    *pData = Soft_I2C_ReceiveData();
    Soft_I2C_GenerateNACK();
    Soft_I2C_GenerateStop();
    
    return 0;
}






