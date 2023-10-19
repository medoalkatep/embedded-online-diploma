#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth:Mohamed Osman" ;


void main(void)
{
	Uart_send(string_buffer) ; 

}
