CC = iverilog
FLAGS = -g2012 -Wall -Winfloop
EXE = test.out
SRCS_unit = tb_stageunit.v butterfly.v delay_buffer.v stage_unit.v
stage_unit:
	$(CC) $(FLAGS) -o $(EXE) $(SRCS_unit)
	vvp $(EXE)
	surfer tb_stageunit.vcd
clean:
	rm -rf $(EXE)
	rm -rf *.vcd
