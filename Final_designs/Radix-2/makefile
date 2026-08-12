CC = iverilog
FLAGS = -g2012 -Wall -Winfloop
EXE = test.out
SRCS_unit = butterfly.v delay_buffer.v stage_unit.v
stage_unit:
	$(CC) $(FLAGS) -o $(EXE) $(SRCS_unit)
	vvp $(EXE)
	surfer tb_stageunit.vcd
fft_top:
	$(CC) $(FLAGS) -o $(EXE) $(SRCS_unit) tb_top_radix_2.v fft_radix_2_top.v
	vvp $(EXE)
	surfer tb_radix2_top.vcd
clean:
	rm -rf $(EXE)
	rm -rf *.vcd
