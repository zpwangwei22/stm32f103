#ifndef __EXTI_H
#define __EXTI_H

#include"stm32f10x.h"
#include"delay.h"
#define KEY GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)

void exti_init();
uint8_t key_scan();

#endif







