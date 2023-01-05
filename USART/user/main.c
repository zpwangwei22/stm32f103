#include "head.h"

int main()
{
    my_usart_init();
    
    while(1)
    {
     
        printf("Hello World\n\r");
        delay(500);
        printf("USART is so cool\n\r");
        delay(500);
        printf("printf is working well!\n\r");

        delay(500);
    }
}
