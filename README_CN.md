# Xilinx Zynq 7000 系列开发板AX7Z020、AX7Z020B  
## 开发板介绍
### 开发板简介
开发板的整个结构，继承了我们一贯的核心板+扩展板的模式来设计的。核心板和扩展板
之间使用高速板间连接器连接。
核心板主要由 XC7Z020 + 2 个 DDR3 + QSPI FLASH 的最小系统构成，承担 ZYNQ 系
统的高速数据处理和存储的功能， ZYNQ7020 和两片 DDR3 之间的数据位宽为 32 位，两片
DDR3 容量高达 1GB。ZYNQ7020 采用 Xilinx 公司的 Zynq7000 系列的芯片，型号为
XC7Z020-2CLG400I。ZYNQ7020 芯片可分成处理器系统部分 Processor System（PS）和
可编程逻辑部分 Programmable Logic（PL）。
底板为核心板扩展了丰富的外围接口，其中包含 1 路千兆以太网接口、1 路 USB2.0 HOST
接口、1 路 HDMI 输出接口、1 路 SD Card 接口、1 路 UART USB 接口、1 路 SD 卡接口、1
路 MIPI 接口、2 路 CAN 总线接口、2 路 RS485 总线接口、2 路 AD 输入接口、2 路 40 针的
扩展口和一些按键 LED。
### 关键特性
  1. ZYNQ7000 核心板，由 XC7Z020+1GB DDR3 + 256Mb QSPI FLASH 组成，另外有 33.333333MHz 晶振提供时钟提供给 PS 系统。 
  2. 2 路 CAN 总线接口，选用 TI 公司的 SN65HVD232 芯片。   
  3. 2 路 485 通信接口，选用 MAXIM 公司的 MAX3485 芯片。 
  4. 1 路 10/100M/1000M 以太网 RJ45 接口，用于和电脑或其它网络设备进行以太网数据交换。网络接口芯片采用景略半导体公司的 JL2121 工业级 GPHY 芯片。   
  5. 一路高速 USB2.0 HOST 接口, 可用于开发板连接鼠标、键盘和 U 盘等 USB 外设;   
  6. 1 路 Uart 转 USB 接口，用于和电脑通信，方便用户调试。串口芯片采用 Silicon Labs CP2102GM 的 USB-UAR 芯片, USB 接口采用 MINI USB 接口。 
  7. 1 路 Micro SD 卡座，用于存储操作系统镜像和文件系统。  
  8. 2 路 AD 模拟输入接口，可用于模拟信号的输入和电压转换，SMA 接口形式。模拟信号电压输入范围为 0~10V（不要输入超过这个范围的电压）
  9. 一路 HDMI 图像视频输出接口, 能实现 1080P 的视频图像传输； 
  10. 一片 IIC 接口的 EEPROM 24LC04;  
  11. 板载一片温度传感器芯片 LM75，用于检测板子周围环境的温度。
  12. 一路 MIPI 摄像头接口，可以连接黑金 MIPI 接口的 OV5640 摄像头(仅 AX7Z020 使用)。
  13. 1 个 JTAG 调试接口。 
  14. 2 个 40 针 2.54mm 间距的扩展口，可以外接黑金的各种模块（双目摄像头，TFT LCD 屏，高速 AD 模块等等）。扩展口包含 5V 电源 1 路，3.3V 电源 2 路，地 3 路，IO 口 34 路。  
  15. 7 个发光二极管 LED, 核心板上 6 个，底板上 1 个。核心板上 1 个电源指示灯；底板上有1 个电源指示灯，1 个 DONE 配置指示灯；4 个用户指示灯。   
  16. 4 个用户按键在底板上。


# AX7Z020、AX7Z020B 文档教程链接
https://ax7z020b-20231-v101.readthedocs.io/zh-cn/latest/7Z020B_S1_RSTdocument_CN/00_%E5%85%B3%E4%BA%8EALINX_CN.html

 注意：文档的末尾页脚处可以切换中英文语言

# AX7Z020、AX7Z020B 例程
## 例程描述
此项目为开发板出厂例程，支持板卡上的大部分外设。
## 开发环境及需求
* Vivado 2023.1
* AX7Z020、AX7Z020B开发板
## 创建Vivado工程
* 下载最新的ZIP包。
* 创建新的工程文件夹.
* 解压下载的ZIP包到此工程文件夹中。


有两种方法创建Vivado工程，如下所示：
### 利用Vivado tcl console创建Vivado工程
1. 打开Vivado软件并且利用**cd**命令进入"**auto_create_project**"目录，并回车
```
cd \<archive extracted location\>/vivado/auto_create_project
```
2. 输入 **source ./create_project.tcl** 并且回车
```
source ./create_project.tcl
```

### 利用bat创建Vivado工程
1. 在 "**auto_create_project**" 文件夹, 有个 "**create_project.bat**"文件, 右键以编辑模式打开，并且修改vivado路径为本主机vivado安装路径，保存并关闭。
```
CALL E:\XilinxVitis\Vivado\2023.1\bin\vivado.bat -mode batch -source create_project.tcl
PAUSE
```
2. 在Windows下双击bat文件即可。


更多信息, 请访问[ALINX网站](https://www.alinx.com)
