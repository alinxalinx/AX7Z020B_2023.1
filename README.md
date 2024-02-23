# Xilinx Zynq 7000 series development boards AX7Z020, AX7Z020B
## Development board introduction
### Development board introduction
The entire structure of the development board is designed based on our consistent core board + expansion board model. Core board and expansion board
are connected using high-speed inter-board connectors.
The core board is mainly composed of XC7Z020 + 2 DDR3 + QSPI FLASH minimum system, responsible for the ZYNQ system
The high-speed data processing and storage function of the system. The data bit width between ZYNQ7020 and two DDR3 chips is 32 bits.
DDR3 capacity up to 1GB. ZYNQ7020 uses Xilinx’s Zynq7000 series of chips, model number is
XC7Z020-2CLG400I. The ZYNQ7020 chip can be divided into the processor system part Processor System (PS) and
Programmable Logic (PL).
The baseboard extends the core board with a wealth of peripheral interfaces, including 1 Gigabit Ethernet interface and 1 USB2.0 HOST
interface, 1 HDMI output interface, 1 SD Card interface, 1 UART USB interface, 1 SD card interface, 1
2-way MIPI interface, 2-way CAN bus interface, 2-way RS485 bus interface, 2-way AD input interface, 2-way 40-pin
Expansion port and some button LEDs.
### Key Features
1. ZYNQ7000 core board consists of XC7Z020+1GB DDR3 + 256Mb QSPI FLASH, and a 33.333333MHz crystal oscillator provides the clock to the PS system.
2. For the 2-way CAN bus interface, the SN65HVD232 chip of TI Company is selected.
3. For the 2-way 485 communication interface, the MAX3485 chip of MAXIM Company is selected.
4. 1 channel 10/100M/1000M Ethernet RJ45 interface, used for Ethernet data exchange with computers or other network devices. The network interface chip uses JL2121 industrial-grade GPHY chip from Jinglue Semiconductor Company.
5. One high-speed USB2.0 HOST interface, which can be used to connect the development board to USB peripherals such as mouse, keyboard, and U disk;
6. 1-way Uart to USB interface, used to communicate with the computer to facilitate user debugging. The serial port chip uses the USB-UAR chip of Silicon Labs CP2102GM, and the USB interface uses the MINI USB interface.
7. 1-way Micro SD card holder for storing operating system images and file systems.
8. 2 AD analog input interfaces, which can be used for analog signal input and voltage conversion, SMA interface form. The analog signal voltage input range is 0~10V (do not input voltage exceeding this range).
9. One HDMI image video output interface, capable of 1080P video image transmission;
10. A piece of EEPROM 24LC04 with IIC interface;
11. There is a temperature sensor chip LM75 on the board, which is used to detect the temperature of the environment around the board.
12. One MIPI camera interface, which can be connected to the OV5640 camera with black gold MIPI interface (only used by AX7Z020).
13. 1 JTAG debugging interface.
14. Two 40-pin 2.54mm pitch expansion ports can be used to connect various black gold modules (binocular cameras, TFT LCD screens, high-speed AD modules, etc.). The expansion port includes 1 channel of 5V power supply, 2 channels of 3.3V power supply, 3 channels of ground, and 34 channels of IO port.
15. 7 light-emitting diodes LED, 6 on the core board and 1 on the base board. There is 1 power indicator light on the core board; 1 power indicator light, 1 DONE configuration indicator light; and 4 user indicator lights on the base board.
16. 4 user buttons on the base panel.


# AX7Z020, AX7Z020B document tutorial link

 Note: You can switch between Chinese and English languages at the footer at the end of the document

# AX7Z020,AX7Z020B routine
## Routine description
This project is the factory routine of the development board and supports most peripherals on the board.
## Development environment and requirements
* Vivado 2023.1
* AX7Z020/AX7Z020B development board
## Create Vivado project
* Download the latest ZIP package.
* Create a new project folder.
* Unzip the downloaded ZIP package into this project folder.


There are two ways to create a Vivado project, as follows:
### Use Vivado tcl console to create a Vivado project
1. Open the Vivado software and use the **cd** command to enter the "**auto_create_project**" directory and press Enter
```
cd \<archive extracted location\>/vivado/auto_create_project
```
2. Enter **source ./create_project.tcl** and press Enter
```
source ./create_project.tcl
```

### Use bat to create a Vivado project
1. In the "**auto_create_project**" folder, there is a "**create_project.bat**" file, right-click to open it in edit mode, and modify the vivado path to the vivado installation path of this host, save and close.
```
CALL E:\XilinxVitis\Vivado\2023.1\bin\vivado.bat -mode batch -source create_project.tcl
PAUSE
```
2. Double-click the bat file under Windows.


For more information, please visit [ALINX website](https://www.alinx.com)