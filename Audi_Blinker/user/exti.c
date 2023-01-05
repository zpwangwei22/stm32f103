#include"exti.h"


void exti_init()
{
    GPIO_InitTypeDef KeyStruct;
    EXTI_InitTypeDef EXTI_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource5);

    KeyStruct.GPIO_Pin = GPIO_Pin_5;
    KeyStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOB, &KeyStruct);

    EXTI_InitStruct.EXTI_Line = EXTI_Line5;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStruct);

    NVIC_InitStruct.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
}

uint8_t key_scan()
{
    static uint8_t k = 1;
    if(k==1 && (KEY==0))
    {
        delay(20);
        k = 0;
        if(KEY == 0)
        {
            return 1;
        }
    }
    else if(KEY == 1)
    {
        k = 1;
    }
    return 0;
}







