set_property PACKAGE_PIN K19 [get_ports dac_clk]
set_property PACKAGE_PIN M19 [get_ports {dac_data[0]}]
set_property PACKAGE_PIN G20 [get_ports {dac_data[1]}]
set_property PACKAGE_PIN G19 [get_ports {dac_data[2]}]
set_property PACKAGE_PIN C20 [get_ports {dac_data[3]}]
set_property PACKAGE_PIN B20 [get_ports {dac_data[4]}]
set_property PACKAGE_PIN A20 [get_ports {dac_data[5]}]
set_property PACKAGE_PIN B19 [get_ports {dac_data[6]}]
set_property PACKAGE_PIN J19 [get_ports {dac_data[7]}]

set_property IOSTANDARD LVCMOS33 [get_ports dac_clk]
set_property IOSTANDARD LVCMOS33 [get_ports {dac_data[*]}]

#KEY1
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_tri_io[0]}]
set_property PACKAGE_PIN M15 [get_ports {GPIO_tri_io[0]}]


