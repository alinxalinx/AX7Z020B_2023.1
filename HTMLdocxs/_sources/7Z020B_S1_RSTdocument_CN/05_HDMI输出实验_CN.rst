HDMI输出实验
==============

**实验Vivado工程为“hdmi_output_test”。**

**本章内容主要由FPGA工程师负责实现。**

前面我们介绍了led闪灯实验，只是为了了解Vivado的基本开发流程，本章这个实验相对LED闪灯实验复杂点，做一个HDMI输出的彩条，这也是我们后面学习显示、视频处理的基础。实验还不涉及到PS系统，从实验设计可以看出如果要非常好的使用ZYNQ芯片，需要良好的FPGA基础知识。

硬件介绍
--------

开发板没有使用HDMI编码芯片，而是将FPGA的3.3V差分IO直接连接到HDMI连接器，
FPGA完成24位RGB编码输出TMDS差分信号。

.. image:: images/05_media/image1.png
    
在做HDMI显示之前，我们需要思考一个问题，产生HDMI图像数据需要哪些要素，如果各位了解过图像的时序应该清楚，无非是图像的像素时钟，图像时序，以及图像数据。当然不同的分辨率时钟和时序也是不同的，具体的可以网上搜索各种分辨率的时序参数。在此不再赘述。本实验仅提供了720p的时序参数（color_bar.v文件中）。

.. image:: images/05_media/image2.png
    
Vivado工程建立
--------------

1) 新建一个名为“hdmi_output_test”的工程

添加HDMI 编码器IP核
~~~~~~~~~~~~~~~~~~~

VGA的数据很多人都比较清楚，为RGB数据，而HDMI为TMDS差分信号，RGB数据在FPGA比较容易操作，那么我们需要做的就是把RGB数据转成HDMI的TMDS差分信号，因此采用了RGB
to DVI的IP（DVI与HDMI都是TMDS信号）。

2) 复制repo文件夹（这个文件夹可以到给的例程工程中找到）到工程目录，这个文件夹里包含了HDMI编码器的IP，是别的厂家提供

.. image:: images/05_media/image3.png
    
3) 点击“IP
   Catalog”，默认这些IP和都是Xilinx提供，现在我们要添加第三方IP，或者我们自己做的IP

.. image:: images/05_media/image4.png
    
4) 右键“Add Repository...”

.. image:: images/05_media/image5.png
    
5) 路径选择刚才复制的repo文件夹

.. image:: images/05_media/image6.png
    
6) 添加IP成功提示添加了多少个IP

.. image:: images/05_media/image7.png
    
7) 找到“RGB to DVI Video Encoder(Source)”，双击

.. image:: images/05_media/image8.png
    
8) 弹出下面窗口，“Component
   Name”元件名保持不变，其他参数也不用改，点击“OK”

.. image:: images/05_media/image9.png
    
9) 弹出一个“Generate Output Products”窗口，其中“Number of
   jobs”指线程数量，越高越快

.. image:: images/05_media/image10.png
    
10) 可以看到一个名为rgb2dvi_0

.. image:: images/05_media/image11.png
    
添加像素时钟PLL模块
~~~~~~~~~~~~~~~~~~~

为了驱动HDMI编码器，需要提供像素时钟和5倍像素时钟，5倍像素时钟用于10:1串行化。

11) 在“IP Catlog”窗口搜索关键字“clock”，双击“Clocking Wizard”

.. image:: images/05_media/image12.png
    
12) 这次给元件起个名字，在“Component
    Name”中填写“video_clock”，“clk_in1”填写50，这里50Mhz和开发板PL端晶振频率一致。

.. image:: images/05_media/image13.png
    
13) 输出时钟“clk_out1”用于视频像素时钟，这里填写74.25，这是1280x720@60分辨率的像素时钟，每一种分辨率的像素时钟都不同，需要非常了解视频标准才能知道每一种视频分辨率的像素时钟，“clk_out2”用于编码器串行化，像素时钟的5倍，这里填写371.25，然后点击“OK”生成IP。

.. image:: images/05_media/image14.png
    
添加彩条发生模块
~~~~~~~~~~~~~~~~

14) 彩条发生模块是一段Verilog代码，用于产生视频时序和水平方向的8个彩条，FPGA不是本开发学习重点，不再详细讲解代码，可以到给的例程中复制现有代码。

.. image:: images/05_media/image15.png
    
添加顶层模块
~~~~~~~~~~~~

15) top模块例化了彩条发生模块，HDMI编码模块，和像素时钟生成模块，代码参考例程给的工程。

.. image:: images/05_media/image16.png
    
添加XDC约束文件
---------------

添加以下的xdc约束文件到项目中，在约束文件里添加了时钟和HDMI相关的管脚。

.. image:: images/05_media/image17.png
    
::

 set_property PACKAGE_PIN U18 [get_ports {sys_clk}]
 set_property IOSTANDARD LVCMOS33 [get_ports {sys_clk}]
 create_clock -period 20.000 -waveform {0.000 10.000} [get_ports sys_clk]
 set_property IOSTANDARD TMDS_33 [get_ports TMDS_clk_n]
 set_property PACKAGE_PIN U13 [get_ports TMDS_clk_p]
 set_property IOSTANDARD TMDS_33 [get_ports TMDS_clk_p]
 set_property IOSTANDARD TMDS_33 [get_ports {TMDS_data_n[0]}]
 set_property PACKAGE_PIN W14 [get_ports {TMDS_data_p[0]}]
 set_property IOSTANDARD TMDS_33 [get_ports {TMDS_data_p[0]}]
 set_property IOSTANDARD TMDS_33 [get_ports {TMDS_data_n[1]}]
 set_property PACKAGE_PIN Y18 [get_ports {TMDS_data_p[1]}]
 set_property IOSTANDARD TMDS_33 [get_ports {TMDS_data_p[1]}]
 set_property IOSTANDARD TMDS_33 [get_ports {TMDS_data_n[2]}]
 set_property PACKAGE_PIN Y16 [get_ports {TMDS_data_p[2]}]
 set_property IOSTANDARD TMDS_33 [get_ports {TMDS_data_p[2]}]
 set_property PACKAGE_PIN V16 [get_ports hdmi_oen]
 set_property IOSTANDARD LVCMOS33 [get_ports hdmi_oen]

下载调试
--------

保存工程并编译生成bit文件，连接HDMI接口到HDMI显示器，需要注意，这里使用1280x720@60Hz，请确保自己的显示器支持这个分辨率。

.. image:: images/05_media/image18.png
    
下载后显示器显示如下图像

.. image:: images/05_media/image19.png
    
实验总结
--------

本实验初步接触到视频显示，涉及到视频知识，这不是zynq学习的重点，所以没有详细介绍，但zynq在视频处理领域用途广泛，需要学习者有良好的基础知识。实验中仅仅使用PL来驱动HDMI芯片，初步学习了第三方自定IP的用法，后面我们会学习如何自定义IP。
