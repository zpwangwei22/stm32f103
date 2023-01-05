#ifndef __TIM2_H
#define __TIM2_H

#include "stm32f10x.h"

void tim2_init(uint16_t arr, uint16_t psc);
void NVIC_init();
void tim2_delay(uint16_t ms);

extern uint16_t volatile my_ticks;





#endif
