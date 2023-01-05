#include"head.h"
uint16_t volatile my_ticks;

int main()
{
    tim2_init(999, 71);
    NVIC_init();
    led_init();
    while(1)
    {
        led_on();
        tim2_delay(500);
        led_off();
        tim2_delay(500);
    }
}

void TIM2_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
        TIM_ClearFlag(TIM2, TIM_IT_Update);
        my_ticks++;
    }
}







