#@copyright : Mohamed Osman
CC=arm-none-eabi
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
ASSRC= $(wildcard *.s)
ASOBJ= $(ASSRC:.s=.o)
project_name=unit3-lap4_cortexM4
all: $(project_name).bin
	@echo "=========== Done Building ================="
	

%.o: %.s
	$(CC)-as.exe $(CFLAGS)  $< -o $@
%.o: %.c
	$(CC)-gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)-ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map
	cp $(project_name).elf $(project_name).axf
	
$(project_name).bin: $(project_name).elf
	$(CC)-objcopy.exe -O binary $< $@


clean:
	rm *.elf *.bin
	@echo "================ Removed executable files =========================="
clean_all:
	rm *.o *.elf *.bin *.map
	@echo "===================== Removed Everything ================================"