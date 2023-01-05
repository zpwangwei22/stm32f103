#include"head.h"



int main()
{
    short Accel_Data[3] = {0};
    short Gyro_Data[3] = {0};

    delay_init();
    my_usart_init();
    I2C_GPIO_Init();
    mpu6050_config();
    while(1)
    {   printf("test\r\n");
        printf("MPU6050ID: %X\r\n", mpu6050_readID());
        mpu6050_read_accel(Accel_Data);
        printf("Accel-Output: x = %8d, y = %8d, z = %8d\r\n", (int)Accel_Data[0], (int)Accel_Data[1], (int)Accel_Data[2]);
        mpu6050_read_gyro(Gyro_Data);
        printf("Gyro-Output: x = %8d, y = %8d, z = %8d\r\n", (int)Gyro_Data[0], (int)Gyro_Data[1], (int)Gyro_Data[2]);
        delay_s(5);   
    }
}
