#include"lcd_1602.h"


void lcd_user_config()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStruct.GPIO_Pin =  GPIO_Pin_0|GPIO_Pin_2|\
                                GPIO_Pin_3|GPIO_Pin_4|\
                                GPIO_Pin_5|GPIO_Pin_6|\
                                GPIO_Pin_7;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    EN_L;
}

void lcd_show_init()
{
    send_cmd2_lcd(0x33);
    send_cmd2_lcd(0x32);
    send_cmd2_lcd(0x28);
    send_cmd2_lcd(0x0c);
    send_cmd2_lcd(0x06);
    send_cmd2_lcd(0x01);
}

void send_cmd2_lcd(uint8_t cmd)
{
    GPIO_Write(GPIOA, cmd);
    RS_L;
    RW_L;
    EN_H;
    delay(1);
    EN_L;
    delay(1);

    GPIO_Write(GPIOA, cmd<<4);
    RS_L;
    RW_L;
    EN_H;
    delay(1);
    EN_L;
    delay(1);
}

void send_data2_lcd(uint8_t data)
{
    GPIO_Write(GPIOA, data);
    RS_H;
    RW_L;
    EN_H;
    delay(1);
    EN_L;
    delay(1);

    GPIO_Write(GPIOA, data<<4);
    RS_H;
    RW_L;
    EN_H;
    delay(1);
    EN_L;
    delay(1);
}

void lcd_set_cur(uint8_t x, uint8_t y)
{
    uint8_t addr;
    if(0 == y)
    {
        addr = 0x00 + x;
    }
    else
    {
        addr = 0x40 + x;
    }
    send_cmd2_lcd(addr | 0x80);
}

void send_str2_lcd(uint8_t x, uint8_t y, char *str)
{
    lcd_set_cur(x, y);
    while(*str != '\0')
    {
        send_data2_lcd(*str++);
    }
}






