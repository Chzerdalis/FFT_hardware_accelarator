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
tb_second_stage:
	$(CC) $(FLAGS) -o $(EXE) tb_second_stage.v second_stage.v memory_second_stage.v butterfly.v
	vvp $(EXE)
	surfer tb_second_stage.vcd
tb_third_stage:
	$(CC) $(FLAGS) -o $(EXE) tb_third_stage.v third_stage_fsm.v memory_third_stage.v fsm_control_unit.v
	vvp $(EXE)
	surfer -s surfer_file/opa tb_third_stage.vcd
tb_fsm_control_unit:
	$(CC) $(FLAGS) -o $(EXE) tb_fsm_control_unit.v fsm_control_unit.v
	vvp $(EXE)
	surfer -s surfer_file/fsm_tb tb_fsm_control_unit.vcd
clean:
	rm -rf $(EXE)
	rm -rf *.vcd
