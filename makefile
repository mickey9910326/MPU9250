MASTER_MAKE = -f M128.make

ASA_MCU_COM = 5

ictest:
	make -f M128.make ictest.a
	cmd_ASA_loader.exe -p $(ASA_MCU_COM) -h hex/ictest.hex
	terminal -p $(ASA_MCU_COM)
