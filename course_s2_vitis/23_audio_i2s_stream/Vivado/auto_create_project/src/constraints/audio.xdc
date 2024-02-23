set_property PACKAGE_PIN M18 [get_ports wm8731_i2c_scl_io]
set_property PACKAGE_PIN M17 [get_ports wm8731_i2c_sda_io]
set_property PACKAGE_PIN K19 [get_ports {wm8731_dacdat[0]}]
set_property PACKAGE_PIN J19 [get_ports {wm8731_bclk[0]}]
set_property PACKAGE_PIN B19 [get_ports {wm8731_adcdat[0]}]
set_property PACKAGE_PIN A20 [get_ports {wm8731_daclrc[0]}]
set_property PACKAGE_PIN B20 [get_ports {wm8731_adclrc[0]}]

set_property IOSTANDARD LVCMOS33 [get_ports wm8731_i2c_scl_io]
set_property IOSTANDARD LVCMOS33 [get_ports wm8731_i2c_sda_io]
set_property IOSTANDARD LVCMOS33 [get_ports {wm8731_dacdat[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {wm8731_bclk[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {wm8731_adcdat[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {wm8731_daclrc[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {wm8731_adclrc[0]}]
#play led
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_tri_io[1]}]
set_property PACKAGE_PIN J14 [get_ports {GPIO_tri_io[1]}]
#record led
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_tri_io[2]}]
set_property PACKAGE_PIN K14 [get_ports {GPIO_tri_io[2]}]
#key
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_tri_io[0]}]
set_property PACKAGE_PIN M15 [get_ports {GPIO_tri_io[0]}]
