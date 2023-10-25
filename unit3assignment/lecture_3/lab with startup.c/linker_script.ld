/* linker_script_cortex_m3.ld
ENG: Mohamed Osman
*/

MEMORY
{
flash(RX) : ORIGIN = 0X08000000, LENGTH = 128K
sram(RWX) : ORIGIN = 0X20000000, LENGTH = 20K	

}

SECTIONS
{
	.text :
	{
	_S_text = . ;
		*(.vectors*)
		*(.text*)
		*(.rodate)
	_E_text = . ;	
	}> flash
	.date :
	{
	_S_data = . ;
        *(.data)
	_E_data = . ; 
	. = ALIGN(4) ;   
	}> sram AT> flash
	.bss :
	{
	_S_bss = . ;
        *(.bss)
	_E_bss = . ;
	. = ALIGN(4) ;
	. = . + 0x1000 ;
	_stack_top = . ;
	}> sram


}