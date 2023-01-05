#ifndef __SYS_H
#define __SYS_H

//GPIOB_BASE 0X4001 0C00
//GPIOB_ODR = 0X40010C00 + 0X0C
//PB6 = (40010C0C - 40000000)*32 + 6*4 = 0X42218198
//PB7 = .... = 0X4221819C
//PB8 = 0X422181A0
//PB9 = 0X422181A4

#define PB6 (*(unsigned int*)0x42218198)
#define PB7 (*(unsigned int*)0x4221819c)
#define PB8 (*(unsigned int*)0x422181a0)
#define PB9 (*(unsigned int*)0x422181a4)





#endif







