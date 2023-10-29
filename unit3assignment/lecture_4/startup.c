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

// Booking 1024 B located by .bss through an un intialized array of int 256 element (256 * 4 = 1024)
static unsigned long Stack_top[256] ;
    
void (*const g_p_fn_Vectors[])()  __attribute__((section(".vectors"))) = 
{
   (void(*)()) ((unsigned long)Stack_top + sizeof(Stack_top))  ,
   &NMI_Handler   ,
   &H_fault_Handler
};

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