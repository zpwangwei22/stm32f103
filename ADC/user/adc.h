#ifndef __ADC_H
#define __ADC_H

#include"stm32f10x.h"
#include"delay.h"

void adc_init(void);
uint16_t get_ADCValue();
uint16_t get_ADC_average(uint8_t times); 

#endif








