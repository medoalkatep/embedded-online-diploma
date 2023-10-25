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
		*(.vectors*)
		*(.text*)
		*(.rodate)
	}> flash
	.date :
	{
        *(.data)
	}> flash
	.bss :
	{
        *(.bss)
	}> sram


}