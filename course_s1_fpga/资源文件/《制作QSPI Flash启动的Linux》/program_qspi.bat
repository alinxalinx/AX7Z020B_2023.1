set XIL_CSE_ZYNQ_DISPLAY_UBOOT_MESSAGES=1
call C:\Xilinx\SDK\2017.4\bin\program_flash -f BOOT.bin  -fsbl fsbl.elf  -offset 0 -flash_type qspi_single  -blank_check -verify
pause
