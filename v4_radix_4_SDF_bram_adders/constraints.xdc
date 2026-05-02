create_clock -period 3.00 -name sys_clk [get_ports clock]

set_property PACKAGE_PIN Y9 [get_ports clock]
set_property IOSTANDARD LVCMOS33 [get_ports clock]

set_property PACKAGE_PIN P16 [get_ports reset]
set_property IOSTANDARD LVCMOS18 [get_ports reset]

# Define the Input Delay for input_en
# Assuming a 2.5ns clock period (400MHz)
#set_input_delay -clock [get_clocks sys_clk] -max 1.500 [get_ports input_en]
#set_input_delay -clock [get_clocks sys_clk] -min 0.500 [get_ports input_en]
#set_input_delay -clock [get_clocks sys_clk] -max 1.500 [get_ports input_real_*]
#set_input_delay -clock [get_clocks sys_clk] -min 0.500 [get_ports input_real_*]

## Constrain the reset pin
#set_input_delay -clock [get_clocks sys_clk] -max 1.500 [get_ports reset]
#set_input_delay -clock [get_clocks sys_clk] -min 0.500 [get_ports reset]

## Constrain all REAL output buses and the output enable
#set_output_delay -clock [get_clocks sys_clk] -max 1.000 [get_ports output_real_*]
#set_output_delay -clock [get_clocks sys_clk] -min -0.500 [get_ports output_real_*]
#set_output_delay -clock [get_clocks sys_clk] -max 1.000 [get_ports output_en]
#set_output_delay -clock [get_clocks sys_clk] -min -0.500 [get_ports output_en]

