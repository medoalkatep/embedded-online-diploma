#include "uart.h"

#define UART0DR *((volatile unsigned int * const)((unsigned int *) 0x101f1000))

void Uart_send (unsigned char *P)
{
	while( *P != '\0')
	{
         UART0DR = (unsigned int)(*P) ;
         P++ ;
	}
}