/* Startup.c
ENG: Mohamed Osman
*/

#include"stdint.h"

void Reset_Handler ()  ;
extern int main() ;
void Default_Handler ()
{
	Reset_Handler() ;
}
void NMI_Handler ()          __attribute__((weak , alias("Default_Handler"))) ; 
void H_fault_Handler ()      __attribute__((weak , alias("Default_Handler"))) ;
void Bus_Handler ()          __attribute__((weak , alias("Default_Handler"))) ;
void Usage_fault_Handler ()  __attribute__((weak , alias("Default_Handler"))) ;
extern unsigned int _stack_top ;

uint32_t vectors[] __attribute__((section(".vectors"))) = {
(uint32_t) &_stack_top  ,
(uint32_t) &Reset_Handler  ,
(uint32_t) &NMI_Handler   ,
(uint32_t) &H_fault_Handler ,
(uint32_t) &Bus_Handler    ,
(uint32_t) &Usage_fault_Handler
} ;
extern unsigned int _E_text ;
extern unsigned int _S_data ;
extern unsigned int _E_data ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;

void Reset_Handler ()
{
	// copying the data from FLASH to RAM 
	unsigned int data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data ;
	unsigned char* p_src = (unsigned char*)&_E_text ;
	unsigned char* p_dst = (unsigned char*)&_S_data ;
	for(int i = 0 ; i < data_size ; i++)
	{
		*((unsigned char*)(p_dst++)) = *((unsigned char*)(p_src++)) ;
	}
	// init the bss section in RAM = 0
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	p_dst = (unsigned char*)&_S_bss ;
	for(int i = 0 ; i < bss_size ; i++)
	{
		*((unsigned char*)(p_dst++)) = (unsigned char)0 ;
	}
     // jump main 
     main() ;
}