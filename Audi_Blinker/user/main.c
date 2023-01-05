#include"head.h"


uint8_t Flag = 0;

int main()
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    led_init();
    delay_init();
    tim2_init(999,71);
    NVIC_init();
    exti_init();    

    while(1)
    {
        if(Flag == 0)
        {
            led_off();
        }
        if((Flag) == 1)
        {
            led_on();
        }
        if((Flag) == 2)
        {
            led_right();
        }
        if((Flag) == 3)
        {
            led_left();
        }
        if((Flag) == 4)
        {
            led_warning();
        }
    }

    
}

void EXTI9_5_IRQHandler(void)
{
    delay(10);
    EXTI_ClearITPendingBit(EXTI_Line5);
    if(key_scan() == 0)
    {
        Flag++;
    }
    if(Flag > 4)
    {
        Flag = 0;
    }
    
}







