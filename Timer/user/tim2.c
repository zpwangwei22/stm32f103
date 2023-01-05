#include"tim2.h"



void tim2_init(uint16_t arr, uint16_t psc)
{
    TIM_TimeBaseInitTypeDef TIM_Struct;
    TIM_Struct.TIM_Prescaler = psc;
    TIM_Struct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_Struct.TIM_Period = arr;
    TIM_Struct.TIM_ClockDivision = TIM_CKD_DIV1;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    TIM_TimeBaseInit(TIM2, &TIM_Struct);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
//    NVIC_EnableIRQ(TIM2_IRQn);
//    TIM_Cmd(TIM2, ENALBLE);
    
}

void NVIC_init()
{
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
    
}

void tim2_delay(uint16_t ms)
{
    TIM_Cmd(TIM2, ENABLE);
    my_ticks = 0;
    while(my_ticks < ms)
        __NOP();
    TIM_Cmd(TIM2, DISABLE);
}











