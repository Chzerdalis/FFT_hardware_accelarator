CC = iverilog
FLAGS = -g2012 -Wall -Winfloop
EXE = test.out
test_butterfly = butterfly.v tb_butterfly.v
stage_unit:
	$(CC) $(FLAGS) -o $(EXE) $(test_butterfly)
	vvp $(EXE)
	surfer tb_butterfly.vcd
memory_stage_1:
	$(CC) $(FLAGS) -o $(EXE) tb_memory_first_stage.v memory_first_stage.v
	vvp $(EXE)
	surfer memory_simulation.vcd
tb_first_stage:
	$(CC) $(FLAGS) -o $(EXE) tb_first_stage.v first_stage.v memory_first_stage.v butterfly.v
	vvp $(EXE)
	surfer tb_first_stage.vcd
clean:
	rm -rf $(EXE)
	rm -rf *.vcd
