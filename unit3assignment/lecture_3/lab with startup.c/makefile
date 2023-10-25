#@copyright : Mohamed Osman
CC=arm-none-eabi
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
ASSRC= $(wildcard *.s)
ASOBJ= $(ASSRC:.s=.o)
project_name=learn_in_depth_cortex_m3
all: $(project_name).bin
	@echo "=========== Done Building ================="
	

%.o: %.s
	$(CC)-as.exe $(CFLAGS)  $< -o $@
%.o: %.c
	$(CC)-gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)-ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map

$(project_name).bin: $(project_name).elf
	$(CC)-objcopy.exe -O binary $< $@


clean:
	rm *.elf *.bin
	@echo "================ Removed executable files =========================="
clean_all:
	rm *.o *.elf *.bin *.map
	@echo "===================== Removed Everything ================================"