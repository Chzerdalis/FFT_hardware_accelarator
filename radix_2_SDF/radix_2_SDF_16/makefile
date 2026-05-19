CC = iverilog
FLAGS = -g2012 -Wall -Winfloop
EXE = test.out
SRCS_unit = butterfly.v delay_buffer.v stage_unit.v fft_16.v test_fft_16.v
top_16:
	$(CC) $(FLAGS) -o $(EXE) $(SRCS_unit)
	vvp $(EXE)
	surfer tb_top_fft_og.vcd
clean:
	rm -rf $(EXE)
	rm -rf *.vcd
