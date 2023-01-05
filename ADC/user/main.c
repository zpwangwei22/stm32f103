#include"head.h"

float adc_val;
char buff[16];
const float R0 = 10000;
const float T_Kelvin_0 = 273.15;
const float stA = 0.001022197;
const float stB = 0.000253179;
const float stC = -5.87992e-11;
float Rt, T_Celsius, Tm;






int main()
{
    my_usart_init();
    delay_init();
    adc_init();
    lcd_user_config();
    lcd_show_init();

    while(1)
    {
        USART_SendString(USART1, "ADC Result: \n\r");
        delay(1000);
//        USART_SendData(USART1, get_ADCValue());
        adc_val = 3.3 * (float)get_ADC_average(5)/(1<<12);

        Rt = R0 * (3.3 - adc_val)/adc_val;
        Tm = 1/(stA + stB*log(Rt) + stC*pow(log(Rt), 3));
        T_Celsius = Tm - T_Kelvin_0;
        sprintf(buff, "TMP: %.3f", T_Celsius);
        USART_SendString(USART1, buff);
        USART_SendString(USART1, "\n\r");
        send_str2_lcd(0, 0, buff);
        delay(1000);
        memset(buff, 0, sizeof(buff));
        send_cmd2_lcd(0x01);
    }
}
