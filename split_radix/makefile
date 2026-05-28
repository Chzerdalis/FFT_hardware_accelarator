CC = iverilog
FLAGS = -g2012 -Wall -Winfloop
EXE = test.out
test_butterfly = butterfly.v tb_butterfly.v
test_memory_first_stage = memory_first_stage.v tb_memory_first_stage.v 
test_memory_second_stage = memory_second_stage.v tb_memory_second_stage.v
stage_unit:
	$(CC) $(FLAGS) -o $(EXE) $(test_butterfly)
	vvp $(EXE)
	surfer tb_butterfly.vcd
memory_first_stage:
	$(CC) $(FLAGS) -o $(EXE) $(test_memory_first_stage)
	vvp $(EXE)
	surfer memory_simulation.vcd
tb_first_stage:
	$(CC) $(FLAGS) -o $(EXE) tb_first_stage.v first_stage.v memory_first_stage.v butterfly.v
	vvp $(EXE)
	surfer tb_first_stage.vcd
memory_second_stage:
	$(CC) $(FLAGS) -o $(EXE) $(test_memory_second_stage)
	vvp $(EXE)
	surfer memory_simulation.vcd
clean:
	rm -rf $(EXE)
	rm -rf *.vcd
