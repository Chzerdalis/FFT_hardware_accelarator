For next times:
1)I must test the new buffer and the new butterfly.
2)Create the other buffers and test them. --------------------
3)Complete the unit and test stage by stage 
4)Test the hole unit 
5)Create python scripts that create input siganls and their outputs in the correct format
6)Check for bigger number of sumples

7)Start new optimazations such us data width reduction


1) new multipliers, multipliless.
2) Bigger test samples (PSNR)
3) making pipeling equal in all stages
4) Test on better Fpga to reach higher frequencies
5) Maybe use Brams for buffers
6) Find pipelined DSP multipliers
7) Reduce datawidth more


DPIR-1#1 Warning
Asynchronous driver check  
DSP fft_inst/gen_stages[0].stage_inst/b4/mul_m0i_1 input pin fft_inst/gen_stages[0].stage_inst/b4/mul_m0i_1/A[0] is connected to registers with an asynchronous reset. This is preventing the possibility of merging these registers in to the DSP Block since the DSP block registers only possess synchronous reset capability.  It is suggested to recode or change these registers to remove the reset or use a synchronous reset to get the best optimization for performance, power and area.
Related violations: <none> 

fixxed with asychronous reset

Small multiplier  
Detected multiplier at fft_inst/gen_stages[3].stage_inst/mul_m2r_reg_1_reg_i_25 of size 6x2, it is implemented as LUTs due to its small size. To force the multiplier onto a DSP block, use the USE_DSP48 attribute.

Missing input or output delay  
An input delay is missing on input_en relative to clock(s) sys_clk
Related violations: <none>

SYNTH-6#1 Warning
Timing of a block RAM might be sub-optimal  
The timing for the instance fft_inst/gen_stages[3].stage_inst/gen_input_logic.butterfly_op_counter_reg_rep, implemented as a block RAM, might be sub-optimal as no output register was merged into the block
Related violations: <none>

Artix-7 AC701 Evaluation Platform (xc7a200tfbg676-2)

Ti egine shmera
Έφτιαξα only real top module, Βρήκα καλ´τερη fpga, εβγαλα το asyn reset και δοθλεψαν pipeliens στα dsps, έβαλα no bram στα twiddle του stage[3], βρήκα bottlenecks στο routing των dsps και στο delay buffer0, Zedboard 4ns, Artix 3,5ns και τέλος πρέπει να τεστάρω την αλλάγη απο multiplication σε shift με add σε behavioral.
