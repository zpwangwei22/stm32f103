#include"delay.h"


void delay_init()
{
	 SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);

}

void delay(u32 nms)
{
	u32 tmp;
	SysTick->LOAD = nms * 9000;
	SysTick->VAL = 0x00;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	do
	{
		tmp = SysTick->CTRL;
	}while((tmp&SysTick_CTRL_ENABLE_Msk) && !(tmp & SysTick_CTRL_COUNTFLAG_Msk));
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL = 0x00;

}
