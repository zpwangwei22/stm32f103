#include "led.h"



void led_init()
{
	GPIO_InitTypeDef LED1, LED2, LED3, LED4;
	LED1.GPIO_Pin =		GPIO_Pin_6;
	LED1.GPIO_Speed =	GPIO_Speed_50MHz;
	LED1.GPIO_Mode =	GPIO_Mode_Out_PP ;
	LED2.GPIO_Pin =		GPIO_Pin_7;
	LED2.GPIO_Speed =	GPIO_Speed_50MHz;
	LED2.GPIO_Mode =	GPIO_Mode_Out_PP ;
	LED3.GPIO_Pin =		GPIO_Pin_8;
	LED3.GPIO_Speed =	GPIO_Speed_50MHz;
	LED3.GPIO_Mode =	GPIO_Mode_Out_PP ;
	LED4.GPIO_Pin =		GPIO_Pin_9;
	LED4.GPIO_Speed =	GPIO_Speed_50MHz;
	LED4.GPIO_Mode =	GPIO_Mode_Out_PP ;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_Init(GPIOB, &LED1);
	GPIO_Init(GPIOB, &LED2);
	GPIO_Init(GPIOB, &LED3);
	GPIO_Init(GPIOB, &LED4);
}

void led_on()
{
	GPIO_SetBits(GPIOB, GPIO_Pin_6|
						GPIO_Pin_7|
						GPIO_Pin_8|
						GPIO_Pin_9);
}

void led_off()
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_6|
						GPIO_Pin_7|
						GPIO_Pin_8|
						GPIO_Pin_9);
}
/*
void led_right()
{
	led_off();
	delay(100);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);
	delay(50);
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
	delay(50);
	GPIO_SetBits(GPIOB,GPIO_Pin_8);
	delay(50);
	GPIO_SetBits(GPIOB,GPIO_Pin_9);
	delay(50);
}

void led_left()
{
	led_off();
	delay(100);
	GPIO_SetBits(GPIOB,GPIO_Pin_9);
	delay(50);
	GPIO_SetBits(GPIOB,GPIO_Pin_8);
	delay(50);
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
	delay(50);
	GPIO_SetBits(GPIOB,GPIO_Pin_6);
	delay(50);
}

void led_warning()
{
	PB6 = 0;
	PB7 = 0;
	PB8 = 0;
	PB9 = 0;
	delay(200);

	PB6 = 1;
	PB7 = 1;
	PB8 = 1;
	PB9 = 1;
	delay(200);
}

*/





