/* linker_script_cortex_m4.ld
ENG: Mohamed Osman
*/

MEMORY
{
flash(RX) : ORIGIN = 0X00000000, LENGTH = 512M
sram(RWX) : ORIGIN = 0X20000000, LENGTH = 512M	

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
	}> sram


}