// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_radix2_top__Syms.h"


VL_ATTR_COLD void Vtb_radix2_top___024root__trace_init_sub__TOP__0(Vtb_radix2_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_radix2_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+928,0,"Num_of_samples",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+929,0,"MAX_FILE_SAMPLES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"input_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"input_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+137,0,"input_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+138,0,"input_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+139,0,"input_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+197,0,"output_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+198,0,"output_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+199,0,"output_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+200,0,"output_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+201,0,"output_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+1,0,"total_samples_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+202,0,"output_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+2,0,"in_file_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+140,0,"out_file_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+3,0,"scan_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+4,0,"t_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+5,0,"t_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+141,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+203,0,"k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+204,0,"frame_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+205,0,"window_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+206,0,"write_offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+207,0,"print_offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+928,0,"Num_of_samples",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"input_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"input_real_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+137,0,"input_real_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+138,0,"input_imag_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+139,0,"input_imag_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+197,0,"output_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+198,0,"output_real_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+199,0,"output_real_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+200,0,"output_imag_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+201,0,"output_imag_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+930,0,"STAGE_NUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("input_real_stage_0", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+156+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("input_real_stage_1", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+164+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("input_imag_stage_0", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+172+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("input_imag_stage_1", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+180+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("stage_output_real_0", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+208+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("stage_output_real_1", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+216+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("stage_output_imag_0", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+224+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("stage_output_imag_1", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+232+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("enable_stage", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 9; ++i) {
        tracep->declBit(c+188+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->pushPrefix("gen_stages[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("stage_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+931,0,"STAGE_NUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+928,0,"Num_of_samples",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"input_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"input_real_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+137,0,"input_real_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+138,0,"input_imag_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+139,0,"input_imag_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+240,0,"output_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+241,0,"output_real_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+242,0,"output_real_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+243,0,"output_imag_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+244,0,"output_imag_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+932,0,"stage_num_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+933,0,"Num_of_samples_flash",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+934,0,"Stride",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+933,0,"shift_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+931,0,"Depth_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+935,0,"Depth_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+931,0,"twiddle_array_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+931,0,"twiddle_array_size_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+936,0,"stride_segment_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, -1,0);
    tracep->declBus(c+937,0,"butterfly_op_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, -1,0);
    tracep->declBus(c+938,0,"flush_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+939,0,"butterfly_op_counter_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+940,0,"twiddle_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+136,0,"x0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+138,0,"x0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+245,0,"y0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+246,0,"y0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+137,0,"x1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+139,0,"x1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+247,0,"y1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+248,0,"y1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+941,0,"delay_in_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+942,0,"delay_in_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+943,0,"delay_out_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+944,0,"delay_out_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+945,0,"delay_in_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+946,0,"delay_in_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+947,0,"delay_out_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+948,0,"delay_out_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+135,0,"start_butterfly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+249,0,"butterfly_out_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+7,0,"wi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->pushPrefix("w_real", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 1; ++i) {
        tracep->declBus(c+8+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 12,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("w_imag", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 1; ++i) {
        tracep->declBus(c+9+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 12,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("b0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"ar",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+138,0,"ai",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+137,0,"br",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+139,0,"bi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+6,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+7,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+245,0,"out1r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+246,0,"out1i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+247,0,"out2r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+248,0,"out2i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+249,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+250,0,"mr_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+252,0,"mi_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+951,0,"mr_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+952,0,"mi_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+254,0,"ar_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+255,0,"ai_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+256,0,"ar_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+257,0,"ai_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+258,0,"ar_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+259,0,"ai_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+260,0,"ar_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+261,0,"ai_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+953,0,"ar_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+954,0,"ai_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+262,0,"valid_pipe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u_cmul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"xr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+139,0,"xi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+6,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+7,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+250,0,"yr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+252,0,"yi",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+263,0,"xr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+264,0,"xi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+265,0,"wr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+266,0,"wi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+267,0,"real_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+269,0,"imag_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+271,0,"xi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+272,0,"wr_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+273,0,"wi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+274,0,"real_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+276,0,"imag_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+278,0,"real_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+280,0,"imag_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_stages[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("stage_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+934,0,"STAGE_NUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+928,0,"Num_of_samples",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+240,0,"input_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+241,0,"input_real_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+242,0,"input_real_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+243,0,"input_imag_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+244,0,"input_imag_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+282,0,"output_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+283,0,"output_real_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+284,0,"output_real_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+285,0,"output_imag_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+286,0,"output_imag_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+935,0,"stage_num_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+933,0,"Num_of_samples_flash",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+955,0,"Stride",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+956,0,"shift_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+934,0,"Depth_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+931,0,"Depth_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+934,0,"twiddle_array_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+934,0,"twiddle_array_size_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+287,0,"stride_segment_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+288,0,"butterfly_op_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+289,0,"flush_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+290,0,"butterfly_op_counter_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+291,0,"twiddle_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+292,0,"x0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+293,0,"x0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+294,0,"y0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+295,0,"y0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+296,0,"x1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+297,0,"x1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+298,0,"y1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+299,0,"y1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+300,0,"delay_in_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+301,0,"delay_in_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+302,0,"delay_out_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+303,0,"delay_out_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+242,0,"delay_in_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+244,0,"delay_in_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+304,0,"delay_out_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+305,0,"delay_out_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+290,0,"start_butterfly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+306,0,"butterfly_out_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+142,0,"wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+143,0,"wi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->pushPrefix("w_real", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+10+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 12,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("w_imag", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+12+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 12,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("b0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+290,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+292,0,"ar",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+293,0,"ai",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+296,0,"br",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+297,0,"bi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+142,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+143,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+294,0,"out1r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+295,0,"out1i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+298,0,"out2r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+299,0,"out2i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+306,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+307,0,"mr_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+309,0,"mi_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+957,0,"mr_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+958,0,"mi_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+311,0,"ar_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+312,0,"ai_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+313,0,"ar_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+314,0,"ai_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+315,0,"ar_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+316,0,"ai_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+317,0,"ar_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+318,0,"ai_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+959,0,"ar_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+960,0,"ai_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+319,0,"valid_pipe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u_cmul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+296,0,"xr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+297,0,"xi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+142,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+143,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+307,0,"yr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+309,0,"yi",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+320,0,"xr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+321,0,"xi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+322,0,"wr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+323,0,"wi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+324,0,"real_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+326,0,"imag_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+328,0,"xi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+329,0,"wr_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+330,0,"wi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+331,0,"real_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+333,0,"imag_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+335,0,"real_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+337,0,"imag_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_delay_buffers", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("db0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+931,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+300,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+301,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+302,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+303,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("buf_re", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 1; ++i) {
        tracep->declBus(c+339+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("buf_im", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 1; ++i) {
        tracep->declBus(c+340+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("db1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+934,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+242,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+244,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+304,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+305,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("buf_re", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+341+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("buf_im", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+343+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_input_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+961,0,"HALF_STRIDE_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_stages[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("stage_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+962,0,"STAGE_NUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+928,0,"Num_of_samples",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+282,0,"input_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+283,0,"input_real_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+284,0,"input_real_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+285,0,"input_imag_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+286,0,"input_imag_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+345,0,"output_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+346,0,"output_real_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+347,0,"output_real_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+348,0,"output_imag_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+349,0,"output_imag_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+931,0,"stage_num_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+933,0,"Num_of_samples_flash",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+930,0,"Stride",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+963,0,"shift_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+955,0,"Depth_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+934,0,"Depth_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+955,0,"twiddle_array_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+955,0,"twiddle_array_size_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+350,0,"stride_segment_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+351,0,"butterfly_op_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+352,0,"flush_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+353,0,"butterfly_op_counter_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+354,0,"twiddle_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+355,0,"x0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+356,0,"x0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+357,0,"y0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+358,0,"y0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+359,0,"x1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+360,0,"x1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+361,0,"y1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+362,0,"y1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+363,0,"delay_in_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+364,0,"delay_in_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+365,0,"delay_out_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+366,0,"delay_out_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+284,0,"delay_in_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+286,0,"delay_in_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+367,0,"delay_out_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+368,0,"delay_out_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+353,0,"start_butterfly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+369,0,"butterfly_out_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+145,0,"wi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->pushPrefix("w_real", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+14+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 12,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("w_imag", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+18+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 12,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("b0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+353,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+355,0,"ar",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+356,0,"ai",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+359,0,"br",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+360,0,"bi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+144,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+145,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+357,0,"out1r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+358,0,"out1i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+361,0,"out2r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+362,0,"out2i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+369,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+370,0,"mr_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+372,0,"mi_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+964,0,"mr_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+965,0,"mi_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+374,0,"ar_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+375,0,"ai_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+376,0,"ar_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+377,0,"ai_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+378,0,"ar_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+379,0,"ai_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+380,0,"ar_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+381,0,"ai_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+966,0,"ar_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+967,0,"ai_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+382,0,"valid_pipe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u_cmul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+359,0,"xr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+360,0,"xi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+144,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+145,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+370,0,"yr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+372,0,"yi",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+383,0,"xr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+384,0,"xi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+385,0,"wr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+386,0,"wi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+387,0,"real_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+389,0,"imag_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+391,0,"xi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+392,0,"wr_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+393,0,"wi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+394,0,"real_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+396,0,"imag_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+398,0,"real_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+400,0,"imag_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_delay_buffers", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("db0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+934,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+363,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+364,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+365,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+366,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("buf_re", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+402+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("buf_im", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+404+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("db1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+955,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+284,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+286,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+367,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+368,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("buf_re", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+406+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("buf_im", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+410+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_input_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+968,0,"HALF_STRIDE_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_stages[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("stage_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+955,0,"STAGE_NUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+928,0,"Num_of_samples",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+345,0,"input_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+346,0,"input_real_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+347,0,"input_real_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+348,0,"input_imag_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+349,0,"input_imag_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+414,0,"output_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+415,0,"output_real_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+416,0,"output_real_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+417,0,"output_imag_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+418,0,"output_imag_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+934,0,"stage_num_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+933,0,"Num_of_samples_flash",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+969,0,"Stride",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+955,0,"shift_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+930,0,"Depth_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+955,0,"Depth_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+930,0,"twiddle_array_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+930,0,"twiddle_array_size_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+419,0,"stride_segment_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+420,0,"butterfly_op_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+421,0,"flush_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+422,0,"butterfly_op_counter_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+423,0,"twiddle_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+424,0,"x0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+425,0,"x0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+426,0,"y0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+427,0,"y0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+428,0,"x1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+429,0,"x1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+430,0,"y1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+431,0,"y1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+432,0,"delay_in_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+433,0,"delay_in_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+434,0,"delay_out_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+435,0,"delay_out_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+347,0,"delay_in_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+349,0,"delay_in_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+436,0,"delay_out_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+437,0,"delay_out_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+422,0,"start_butterfly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+438,0,"butterfly_out_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+146,0,"wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+147,0,"wi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->pushPrefix("w_real", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+22+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 12,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("w_imag", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+30+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 12,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("b0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+422,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+424,0,"ar",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+425,0,"ai",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+428,0,"br",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+429,0,"bi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+146,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+147,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+426,0,"out1r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+427,0,"out1i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+430,0,"out2r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+431,0,"out2i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+438,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+439,0,"mr_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+441,0,"mi_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+970,0,"mr_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+971,0,"mi_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+443,0,"ar_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+444,0,"ai_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+445,0,"ar_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+446,0,"ai_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+447,0,"ar_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+448,0,"ai_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+449,0,"ar_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+450,0,"ai_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+972,0,"ar_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+973,0,"ai_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+451,0,"valid_pipe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u_cmul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+428,0,"xr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+429,0,"xi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+146,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+147,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+439,0,"yr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+441,0,"yi",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+452,0,"xr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+453,0,"xi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+454,0,"wr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+455,0,"wi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+456,0,"real_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+458,0,"imag_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+460,0,"xi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+461,0,"wr_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+462,0,"wi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+463,0,"real_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+465,0,"imag_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+467,0,"real_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+469,0,"imag_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_delay_buffers", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("db0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+955,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+432,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+433,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+434,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+435,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("buf_re", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+471+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("buf_im", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+475+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("db1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+930,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+347,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+349,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+436,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+437,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("buf_re", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+479+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("buf_im", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+487+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_input_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+974,0,"HALF_STRIDE_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_stages[4]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("stage_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+963,0,"STAGE_NUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+928,0,"Num_of_samples",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+414,0,"input_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+415,0,"input_real_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+416,0,"input_real_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+417,0,"input_imag_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+418,0,"input_imag_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+495,0,"output_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+496,0,"output_real_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+497,0,"output_real_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+498,0,"output_imag_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+499,0,"output_imag_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+962,0,"stage_num_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+933,0,"Num_of_samples_flash",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+975,0,"Stride",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+962,0,"shift_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+969,0,"Depth_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+930,0,"Depth_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+969,0,"twiddle_array_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+969,0,"twiddle_array_size_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+500,0,"stride_segment_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+501,0,"butterfly_op_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+502,0,"flush_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+503,0,"butterfly_op_counter_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+504,0,"twiddle_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+505,0,"x0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+506,0,"x0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+507,0,"y0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+508,0,"y0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+509,0,"x1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+510,0,"x1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+511,0,"y1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+512,0,"y1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+513,0,"delay_in_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+514,0,"delay_in_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+515,0,"delay_out_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+516,0,"delay_out_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+416,0,"delay_in_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+418,0,"delay_in_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+517,0,"delay_out_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+518,0,"delay_out_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+503,0,"start_butterfly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+519,0,"butterfly_out_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+148,0,"wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+149,0,"wi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->pushPrefix("w_real", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+38+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 12,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("w_imag", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+54+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 12,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("b0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+503,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+505,0,"ar",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+506,0,"ai",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+509,0,"br",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+510,0,"bi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+148,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+149,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+507,0,"out1r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+508,0,"out1i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+511,0,"out2r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+512,0,"out2i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+519,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+520,0,"mr_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+522,0,"mi_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+976,0,"mr_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+977,0,"mi_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+524,0,"ar_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+525,0,"ai_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+526,0,"ar_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+527,0,"ai_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+528,0,"ar_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+529,0,"ai_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+530,0,"ar_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+531,0,"ai_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+978,0,"ar_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+979,0,"ai_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+532,0,"valid_pipe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u_cmul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+509,0,"xr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+510,0,"xi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+148,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+149,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+520,0,"yr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+522,0,"yi",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+533,0,"xr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+534,0,"xi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+535,0,"wr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+536,0,"wi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+537,0,"real_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+539,0,"imag_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+541,0,"xi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+542,0,"wr_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+543,0,"wi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+544,0,"real_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+546,0,"imag_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+548,0,"real_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+550,0,"imag_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_delay_buffers", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("db0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+930,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+513,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+514,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+515,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+516,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("buf_re", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+552+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("buf_im", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+560+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("db1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+969,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+416,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+418,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+517,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+518,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("buf_re", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+568+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("buf_im", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+584+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_input_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+980,0,"HALF_STRIDE_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_stages[5]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("stage_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+956,0,"STAGE_NUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+928,0,"Num_of_samples",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+495,0,"input_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+496,0,"input_real_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+497,0,"input_real_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+498,0,"input_imag_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+499,0,"input_imag_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+600,0,"output_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+601,0,"output_real_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+602,0,"output_real_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+603,0,"output_imag_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+604,0,"output_imag_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+955,0,"stage_num_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+933,0,"Num_of_samples_flash",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+981,0,"Stride",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+934,0,"shift_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+975,0,"Depth_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+969,0,"Depth_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+975,0,"twiddle_array_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+975,0,"twiddle_array_size_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+605,0,"stride_segment_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+606,0,"butterfly_op_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+607,0,"flush_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+608,0,"butterfly_op_counter_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+609,0,"twiddle_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+610,0,"x0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+611,0,"x0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+612,0,"y0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+613,0,"y0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+614,0,"x1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+615,0,"x1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+616,0,"y1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+617,0,"y1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+618,0,"delay_in_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+619,0,"delay_in_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+620,0,"delay_out_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+621,0,"delay_out_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+497,0,"delay_in_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+499,0,"delay_in_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+622,0,"delay_out_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+623,0,"delay_out_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+608,0,"start_butterfly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+624,0,"butterfly_out_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+150,0,"wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+151,0,"wi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->pushPrefix("w_real", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+70+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 12,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("w_imag", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+102+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 12,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("b0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+608,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+610,0,"ar",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+611,0,"ai",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+614,0,"br",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+615,0,"bi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+150,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+151,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+612,0,"out1r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+613,0,"out1i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+616,0,"out2r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+617,0,"out2i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+624,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+625,0,"mr_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+627,0,"mi_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+982,0,"mr_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+983,0,"mi_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+629,0,"ar_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+630,0,"ai_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+631,0,"ar_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+632,0,"ai_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+633,0,"ar_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+634,0,"ai_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+635,0,"ar_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+636,0,"ai_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+984,0,"ar_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+985,0,"ai_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+637,0,"valid_pipe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u_cmul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+614,0,"xr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+615,0,"xi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+150,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+151,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+625,0,"yr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+627,0,"yi",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+638,0,"xr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+639,0,"xi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+640,0,"wr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+641,0,"wi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+642,0,"real_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+644,0,"imag_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+646,0,"xi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+647,0,"wr_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+648,0,"wi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+649,0,"real_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+651,0,"imag_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+653,0,"real_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+655,0,"imag_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_delay_buffers", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("db0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+969,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+618,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+619,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+620,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+621,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("buf_re", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+657+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("buf_im", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+673+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("db1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+975,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+497,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+499,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+622,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+623,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("buf_re", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+689+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("buf_im", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+721+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_input_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+986,0,"HALF_STRIDE_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_stages[6]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("stage_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+933,0,"STAGE_NUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+928,0,"Num_of_samples",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+600,0,"input_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+601,0,"input_real_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+602,0,"input_real_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+603,0,"input_imag_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+604,0,"input_imag_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+753,0,"output_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+754,0,"output_real_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+755,0,"output_real_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+756,0,"output_imag_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+757,0,"output_imag_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+963,0,"stage_num_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+933,0,"Num_of_samples_flash",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+987,0,"Stride",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+931,0,"shift_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+981,0,"Depth_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+975,0,"Depth_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+981,0,"twiddle_array_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+981,0,"twiddle_array_size_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+758,0,"stride_segment_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+759,0,"butterfly_op_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+760,0,"flush_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+761,0,"butterfly_op_counter_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+762,0,"twiddle_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+763,0,"x0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+764,0,"x0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+765,0,"y0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+766,0,"y0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+767,0,"x1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+768,0,"x1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+769,0,"y1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+770,0,"y1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+771,0,"delay_in_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+772,0,"delay_in_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+773,0,"delay_out_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+774,0,"delay_out_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+602,0,"delay_in_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+604,0,"delay_in_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+775,0,"delay_out_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+776,0,"delay_out_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+761,0,"start_butterfly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+777,0,"butterfly_out_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+152,0,"wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+153,0,"wi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->pushPrefix("b0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+761,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+763,0,"ar",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+764,0,"ai",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+767,0,"br",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+768,0,"bi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+152,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+153,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+765,0,"out1r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+766,0,"out1i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+769,0,"out2r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+770,0,"out2i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+777,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+778,0,"mr_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+780,0,"mi_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+988,0,"mr_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+989,0,"mi_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+782,0,"ar_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+783,0,"ai_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+784,0,"ar_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+785,0,"ai_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+786,0,"ar_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+787,0,"ai_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+788,0,"ar_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+789,0,"ai_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+990,0,"ar_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+991,0,"ai_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+790,0,"valid_pipe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u_cmul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+767,0,"xr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+768,0,"xi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+152,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+153,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+778,0,"yr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+780,0,"yi",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+791,0,"xr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+792,0,"xi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+793,0,"wr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+794,0,"wi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+795,0,"real_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+797,0,"imag_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+799,0,"xi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+800,0,"wr_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+801,0,"wi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+802,0,"real_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+804,0,"imag_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+806,0,"real_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+808,0,"imag_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_delay_buffers", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("db0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+975,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+771,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+772,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+773,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+774,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->pushPrefix("buf_re", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+810+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("buf_im", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+842+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 25,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("db1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+981,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+602,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+604,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+775,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+776,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_input_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+992,0,"HALF_STRIDE_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_stages[7]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("stage_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+930,0,"STAGE_NUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+928,0,"Num_of_samples",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+753,0,"input_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+754,0,"input_real_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+755,0,"input_real_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+756,0,"input_imag_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+757,0,"input_imag_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+197,0,"output_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+198,0,"output_real_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+199,0,"output_real_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+200,0,"output_imag_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+201,0,"output_imag_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+956,0,"stage_num_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+933,0,"Num_of_samples_flash",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+928,0,"Stride",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+935,0,"shift_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+987,0,"Depth_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+981,0,"Depth_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+987,0,"twiddle_array_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+987,0,"twiddle_array_size_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+874,0,"stride_segment_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+875,0,"butterfly_op_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+876,0,"flush_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+877,0,"butterfly_op_counter_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+878,0,"twiddle_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+879,0,"x0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+880,0,"x0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+881,0,"y0_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+882,0,"y0_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+883,0,"x1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+884,0,"x1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+885,0,"y1_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+886,0,"y1_im",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+887,0,"delay_in_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+888,0,"delay_in_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+889,0,"delay_out_real_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+890,0,"delay_out_imag_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+755,0,"delay_in_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+757,0,"delay_in_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+891,0,"delay_out_real_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+892,0,"delay_out_imag_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+877,0,"start_butterfly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+893,0,"butterfly_out_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+154,0,"wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+155,0,"wi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->pushPrefix("b0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+877,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+879,0,"ar",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+880,0,"ai",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+883,0,"br",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+884,0,"bi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+154,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+155,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+881,0,"out1r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+882,0,"out1i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+885,0,"out2r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+886,0,"out2i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBit(c+893,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+894,0,"mr_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+896,0,"mi_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+993,0,"mr_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+994,0,"mi_s_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+898,0,"ar_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+899,0,"ai_d0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+900,0,"ar_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+901,0,"ai_d1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+902,0,"ar_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+903,0,"ai_d2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+904,0,"ar_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+905,0,"ai_d3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+995,0,"ar_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+996,0,"ai_d4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+906,0,"valid_pipe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("u_cmul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+949,0,"TW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+950,0,"PROD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+883,0,"xr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+884,0,"xi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+154,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+155,0,"wi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+894,0,"yr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+896,0,"yi",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+907,0,"xr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+908,0,"xi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+909,0,"wr_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+910,0,"wi_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+911,0,"real_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+913,0,"imag_prod_a_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+915,0,"xi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+916,0,"wr_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+917,0,"wi_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declQuad(c+918,0,"real_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+920,0,"imag_prod_a_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+922,0,"real_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+924,0,"imag_prod_b_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_delay_buffers", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("db0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+981,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+887,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+888,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+889,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+890,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->popPrefix();
    tracep->pushPrefix("db1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+987,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+927,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+926,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+755,0,"input_real",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+757,0,"input_imag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+891,0,"out_real",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->declBus(c+892,0,"out_imag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_input_logic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+997,0,"HALF_STRIDE_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_radix2_top___024root__trace_init_top(Vtb_radix2_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root__trace_init_top\n"); );
    // Body
    Vtb_radix2_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_radix2_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_radix2_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_radix2_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_radix2_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_radix2_top___024root__trace_register(Vtb_radix2_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtb_radix2_top___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_radix2_top___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_radix2_top___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_radix2_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_radix2_top___024root__trace_const_0_sub_0(Vtb_radix2_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_radix2_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root__trace_const_0\n"); );
    // Init
    Vtb_radix2_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_radix2_top___024root*>(voidSelf);
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_radix2_top___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_radix2_top___024root__trace_const_0_sub_0(Vtb_radix2_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+927,(0x1aU),32);
    bufp->fullIData(oldp+928,(0x100U),32);
    bufp->fullIData(oldp+929,(0x4e8U),32);
    bufp->fullIData(oldp+930,(8U),32);
    bufp->fullIData(oldp+931,(1U),32);
    bufp->fullIData(oldp+932,(0xffffffffU),32);
    bufp->fullIData(oldp+933,(7U),32);
    bufp->fullIData(oldp+934,(2U),32);
    bufp->fullIData(oldp+935,(0U),32);
    bufp->fullCData(oldp+936,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__stride_segment_counter),2);
    bufp->fullCData(oldp+937,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__butterfly_op_counter),2);
    bufp->fullCData(oldp+938,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__flush_counter),7);
    bufp->fullBit(oldp+939,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
    bufp->fullCData(oldp+940,(0U),8);
    bufp->fullIData(oldp+941,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__delay_in_real_0),26);
    bufp->fullIData(oldp+942,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__delay_in_imag_0),26);
    bufp->fullIData(oldp+943,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__delay_out_real_0),26);
    bufp->fullIData(oldp+944,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__delay_out_imag_0),26);
    bufp->fullIData(oldp+945,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__delay_in_real_1),26);
    bufp->fullIData(oldp+946,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__delay_in_imag_1),26);
    bufp->fullIData(oldp+947,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__delay_out_real_1),26);
    bufp->fullIData(oldp+948,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__delay_out_imag_1),26);
    bufp->fullIData(oldp+949,(0xdU),32);
    bufp->fullIData(oldp+950,(0x27U),32);
    bufp->fullIData(oldp+951,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__mr_s_reg),26);
    bufp->fullIData(oldp+952,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__mi_s_reg),26);
    bufp->fullIData(oldp+953,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ar_d4),26);
    bufp->fullIData(oldp+954,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ai_d4),26);
    bufp->fullIData(oldp+955,(4U),32);
    bufp->fullIData(oldp+956,(6U),32);
    bufp->fullIData(oldp+957,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__mr_s_reg),26);
    bufp->fullIData(oldp+958,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__mi_s_reg),26);
    bufp->fullIData(oldp+959,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ar_d4),26);
    bufp->fullIData(oldp+960,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ai_d4),26);
    bufp->fullBit(oldp+961,(0U));
    bufp->fullIData(oldp+962,(3U),32);
    bufp->fullIData(oldp+963,(5U),32);
    bufp->fullIData(oldp+964,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__mr_s_reg),26);
    bufp->fullIData(oldp+965,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__mi_s_reg),26);
    bufp->fullIData(oldp+966,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ar_d4),26);
    bufp->fullIData(oldp+967,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ai_d4),26);
    bufp->fullCData(oldp+968,(1U),2);
    bufp->fullIData(oldp+969,(0x10U),32);
    bufp->fullIData(oldp+970,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__mr_s_reg),26);
    bufp->fullIData(oldp+971,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__mi_s_reg),26);
    bufp->fullIData(oldp+972,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ar_d4),26);
    bufp->fullIData(oldp+973,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ai_d4),26);
    bufp->fullCData(oldp+974,(3U),3);
    bufp->fullIData(oldp+975,(0x20U),32);
    bufp->fullIData(oldp+976,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__mr_s_reg),26);
    bufp->fullIData(oldp+977,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__mi_s_reg),26);
    bufp->fullIData(oldp+978,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ar_d4),26);
    bufp->fullIData(oldp+979,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ai_d4),26);
    bufp->fullCData(oldp+980,(7U),4);
    bufp->fullIData(oldp+981,(0x40U),32);
    bufp->fullIData(oldp+982,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__mr_s_reg),26);
    bufp->fullIData(oldp+983,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__mi_s_reg),26);
    bufp->fullIData(oldp+984,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ar_d4),26);
    bufp->fullIData(oldp+985,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ai_d4),26);
    bufp->fullCData(oldp+986,(0xfU),5);
    bufp->fullIData(oldp+987,(0x80U),32);
    bufp->fullIData(oldp+988,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__mr_s_reg),26);
    bufp->fullIData(oldp+989,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__mi_s_reg),26);
    bufp->fullIData(oldp+990,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ar_d4),26);
    bufp->fullIData(oldp+991,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ai_d4),26);
    bufp->fullCData(oldp+992,(0x1fU),6);
    bufp->fullIData(oldp+993,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__mr_s_reg),26);
    bufp->fullIData(oldp+994,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__mi_s_reg),26);
    bufp->fullIData(oldp+995,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ar_d4),26);
    bufp->fullIData(oldp+996,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ai_d4),26);
    bufp->fullCData(oldp+997,(0x3fU),7);
}

VL_ATTR_COLD void Vtb_radix2_top___024root__trace_full_0_sub_0(Vtb_radix2_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_radix2_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root__trace_full_0\n"); );
    // Init
    Vtb_radix2_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_radix2_top___024root*>(voidSelf);
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_radix2_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_radix2_top___024root__trace_full_0_sub_0(Vtb_radix2_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->tb_radix2_top__DOT__total_samples_read),32);
    bufp->fullIData(oldp+2,(vlSelf->tb_radix2_top__DOT__in_file_id),32);
    bufp->fullIData(oldp+3,(vlSelf->tb_radix2_top__DOT__scan_count),32);
    bufp->fullIData(oldp+4,(vlSelf->tb_radix2_top__DOT__t_i),32);
    bufp->fullIData(oldp+5,(vlSelf->tb_radix2_top__DOT__t_r),32);
    bufp->fullSData(oldp+6,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_real
                            [0U]),13);
    bufp->fullSData(oldp+7,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_imag
                            [0U]),13);
    bufp->fullSData(oldp+8,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_real[0]),13);
    bufp->fullSData(oldp+9,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_imag[0]),13);
    bufp->fullSData(oldp+10,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_real[0]),13);
    bufp->fullSData(oldp+11,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_real[1]),13);
    bufp->fullSData(oldp+12,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_imag[0]),13);
    bufp->fullSData(oldp+13,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_imag[1]),13);
    bufp->fullSData(oldp+14,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real[0]),13);
    bufp->fullSData(oldp+15,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real[1]),13);
    bufp->fullSData(oldp+16,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real[2]),13);
    bufp->fullSData(oldp+17,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real[3]),13);
    bufp->fullSData(oldp+18,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag[0]),13);
    bufp->fullSData(oldp+19,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag[1]),13);
    bufp->fullSData(oldp+20,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag[2]),13);
    bufp->fullSData(oldp+21,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag[3]),13);
    bufp->fullSData(oldp+22,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[0]),13);
    bufp->fullSData(oldp+23,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[1]),13);
    bufp->fullSData(oldp+24,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[2]),13);
    bufp->fullSData(oldp+25,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[3]),13);
    bufp->fullSData(oldp+26,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[4]),13);
    bufp->fullSData(oldp+27,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[5]),13);
    bufp->fullSData(oldp+28,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[6]),13);
    bufp->fullSData(oldp+29,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[7]),13);
    bufp->fullSData(oldp+30,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[0]),13);
    bufp->fullSData(oldp+31,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[1]),13);
    bufp->fullSData(oldp+32,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[2]),13);
    bufp->fullSData(oldp+33,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[3]),13);
    bufp->fullSData(oldp+34,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[4]),13);
    bufp->fullSData(oldp+35,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[5]),13);
    bufp->fullSData(oldp+36,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[6]),13);
    bufp->fullSData(oldp+37,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[7]),13);
    bufp->fullSData(oldp+38,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[0]),13);
    bufp->fullSData(oldp+39,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[1]),13);
    bufp->fullSData(oldp+40,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[2]),13);
    bufp->fullSData(oldp+41,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[3]),13);
    bufp->fullSData(oldp+42,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[4]),13);
    bufp->fullSData(oldp+43,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[5]),13);
    bufp->fullSData(oldp+44,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[6]),13);
    bufp->fullSData(oldp+45,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[7]),13);
    bufp->fullSData(oldp+46,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[8]),13);
    bufp->fullSData(oldp+47,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[9]),13);
    bufp->fullSData(oldp+48,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[10]),13);
    bufp->fullSData(oldp+49,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[11]),13);
    bufp->fullSData(oldp+50,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[12]),13);
    bufp->fullSData(oldp+51,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[13]),13);
    bufp->fullSData(oldp+52,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[14]),13);
    bufp->fullSData(oldp+53,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[15]),13);
    bufp->fullSData(oldp+54,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[0]),13);
    bufp->fullSData(oldp+55,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[1]),13);
    bufp->fullSData(oldp+56,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[2]),13);
    bufp->fullSData(oldp+57,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[3]),13);
    bufp->fullSData(oldp+58,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[4]),13);
    bufp->fullSData(oldp+59,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[5]),13);
    bufp->fullSData(oldp+60,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[6]),13);
    bufp->fullSData(oldp+61,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[7]),13);
    bufp->fullSData(oldp+62,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[8]),13);
    bufp->fullSData(oldp+63,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[9]),13);
    bufp->fullSData(oldp+64,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[10]),13);
    bufp->fullSData(oldp+65,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[11]),13);
    bufp->fullSData(oldp+66,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[12]),13);
    bufp->fullSData(oldp+67,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[13]),13);
    bufp->fullSData(oldp+68,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[14]),13);
    bufp->fullSData(oldp+69,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[15]),13);
    bufp->fullSData(oldp+70,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[0]),13);
    bufp->fullSData(oldp+71,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[1]),13);
    bufp->fullSData(oldp+72,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[2]),13);
    bufp->fullSData(oldp+73,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[3]),13);
    bufp->fullSData(oldp+74,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[4]),13);
    bufp->fullSData(oldp+75,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[5]),13);
    bufp->fullSData(oldp+76,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[6]),13);
    bufp->fullSData(oldp+77,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[7]),13);
    bufp->fullSData(oldp+78,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[8]),13);
    bufp->fullSData(oldp+79,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[9]),13);
    bufp->fullSData(oldp+80,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[10]),13);
    bufp->fullSData(oldp+81,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[11]),13);
    bufp->fullSData(oldp+82,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[12]),13);
    bufp->fullSData(oldp+83,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[13]),13);
    bufp->fullSData(oldp+84,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[14]),13);
    bufp->fullSData(oldp+85,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[15]),13);
    bufp->fullSData(oldp+86,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[16]),13);
    bufp->fullSData(oldp+87,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[17]),13);
    bufp->fullSData(oldp+88,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[18]),13);
    bufp->fullSData(oldp+89,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[19]),13);
    bufp->fullSData(oldp+90,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[20]),13);
    bufp->fullSData(oldp+91,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[21]),13);
    bufp->fullSData(oldp+92,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[22]),13);
    bufp->fullSData(oldp+93,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[23]),13);
    bufp->fullSData(oldp+94,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[24]),13);
    bufp->fullSData(oldp+95,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[25]),13);
    bufp->fullSData(oldp+96,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[26]),13);
    bufp->fullSData(oldp+97,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[27]),13);
    bufp->fullSData(oldp+98,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[28]),13);
    bufp->fullSData(oldp+99,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[29]),13);
    bufp->fullSData(oldp+100,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[30]),13);
    bufp->fullSData(oldp+101,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[31]),13);
    bufp->fullSData(oldp+102,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[0]),13);
    bufp->fullSData(oldp+103,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[1]),13);
    bufp->fullSData(oldp+104,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[2]),13);
    bufp->fullSData(oldp+105,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[3]),13);
    bufp->fullSData(oldp+106,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[4]),13);
    bufp->fullSData(oldp+107,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[5]),13);
    bufp->fullSData(oldp+108,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[6]),13);
    bufp->fullSData(oldp+109,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[7]),13);
    bufp->fullSData(oldp+110,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[8]),13);
    bufp->fullSData(oldp+111,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[9]),13);
    bufp->fullSData(oldp+112,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[10]),13);
    bufp->fullSData(oldp+113,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[11]),13);
    bufp->fullSData(oldp+114,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[12]),13);
    bufp->fullSData(oldp+115,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[13]),13);
    bufp->fullSData(oldp+116,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[14]),13);
    bufp->fullSData(oldp+117,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[15]),13);
    bufp->fullSData(oldp+118,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[16]),13);
    bufp->fullSData(oldp+119,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[17]),13);
    bufp->fullSData(oldp+120,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[18]),13);
    bufp->fullSData(oldp+121,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[19]),13);
    bufp->fullSData(oldp+122,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[20]),13);
    bufp->fullSData(oldp+123,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[21]),13);
    bufp->fullSData(oldp+124,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[22]),13);
    bufp->fullSData(oldp+125,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[23]),13);
    bufp->fullSData(oldp+126,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[24]),13);
    bufp->fullSData(oldp+127,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[25]),13);
    bufp->fullSData(oldp+128,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[26]),13);
    bufp->fullSData(oldp+129,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[27]),13);
    bufp->fullSData(oldp+130,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[28]),13);
    bufp->fullSData(oldp+131,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[29]),13);
    bufp->fullSData(oldp+132,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[30]),13);
    bufp->fullSData(oldp+133,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[31]),13);
    bufp->fullBit(oldp+134,(vlSelf->tb_radix2_top__DOT__reset));
    bufp->fullBit(oldp+135,(vlSelf->tb_radix2_top__DOT__input_en));
    bufp->fullIData(oldp+136,(vlSelf->tb_radix2_top__DOT__input_real_0),26);
    bufp->fullIData(oldp+137,(vlSelf->tb_radix2_top__DOT__input_real_1),26);
    bufp->fullIData(oldp+138,(vlSelf->tb_radix2_top__DOT__input_imag_0),26);
    bufp->fullIData(oldp+139,(vlSelf->tb_radix2_top__DOT__input_imag_1),26);
    bufp->fullIData(oldp+140,(vlSelf->tb_radix2_top__DOT__out_file_id),32);
    bufp->fullIData(oldp+141,(vlSelf->tb_radix2_top__DOT__i),32);
    bufp->fullSData(oldp+142,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_real
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullSData(oldp+143,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_imag
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullSData(oldp+144,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullSData(oldp+145,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullSData(oldp+146,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullSData(oldp+147,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullSData(oldp+148,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullSData(oldp+149,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullSData(oldp+150,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullSData(oldp+151,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullSData(oldp+152,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__w_real
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullSData(oldp+153,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__w_imag
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullSData(oldp+154,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__w_real
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullSData(oldp+155,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__w_imag
                              [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    bufp->fullIData(oldp+156,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[0]),26);
    bufp->fullIData(oldp+157,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[1]),26);
    bufp->fullIData(oldp+158,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[2]),26);
    bufp->fullIData(oldp+159,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[3]),26);
    bufp->fullIData(oldp+160,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[4]),26);
    bufp->fullIData(oldp+161,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[5]),26);
    bufp->fullIData(oldp+162,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[6]),26);
    bufp->fullIData(oldp+163,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[7]),26);
    bufp->fullIData(oldp+164,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[0]),26);
    bufp->fullIData(oldp+165,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[1]),26);
    bufp->fullIData(oldp+166,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[2]),26);
    bufp->fullIData(oldp+167,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[3]),26);
    bufp->fullIData(oldp+168,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[4]),26);
    bufp->fullIData(oldp+169,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[5]),26);
    bufp->fullIData(oldp+170,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[6]),26);
    bufp->fullIData(oldp+171,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[7]),26);
    bufp->fullIData(oldp+172,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[0]),26);
    bufp->fullIData(oldp+173,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[1]),26);
    bufp->fullIData(oldp+174,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[2]),26);
    bufp->fullIData(oldp+175,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[3]),26);
    bufp->fullIData(oldp+176,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[4]),26);
    bufp->fullIData(oldp+177,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[5]),26);
    bufp->fullIData(oldp+178,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[6]),26);
    bufp->fullIData(oldp+179,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[7]),26);
    bufp->fullIData(oldp+180,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[0]),26);
    bufp->fullIData(oldp+181,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[1]),26);
    bufp->fullIData(oldp+182,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[2]),26);
    bufp->fullIData(oldp+183,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[3]),26);
    bufp->fullIData(oldp+184,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[4]),26);
    bufp->fullIData(oldp+185,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[5]),26);
    bufp->fullIData(oldp+186,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[6]),26);
    bufp->fullIData(oldp+187,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[7]),26);
    bufp->fullBit(oldp+188,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[0]));
    bufp->fullBit(oldp+189,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[1]));
    bufp->fullBit(oldp+190,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[2]));
    bufp->fullBit(oldp+191,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[3]));
    bufp->fullBit(oldp+192,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[4]));
    bufp->fullBit(oldp+193,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[5]));
    bufp->fullBit(oldp+194,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[6]));
    bufp->fullBit(oldp+195,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[7]));
    bufp->fullBit(oldp+196,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[8]));
    bufp->fullBit(oldp+197,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_en));
    bufp->fullIData(oldp+198,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_real_0),26);
    bufp->fullIData(oldp+199,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_real_1),26);
    bufp->fullIData(oldp+200,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_imag_0),26);
    bufp->fullIData(oldp+201,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_imag_1),26);
    bufp->fullIData(oldp+202,(vlSelf->tb_radix2_top__DOT__output_count),32);
    bufp->fullIData(oldp+203,(vlSelf->tb_radix2_top__DOT__k),32);
    bufp->fullBit(oldp+204,(vlSelf->tb_radix2_top__DOT__frame_ready));
    bufp->fullIData(oldp+205,(vlSelf->tb_radix2_top__DOT__window_count),32);
    bufp->fullIData(oldp+206,(vlSelf->tb_radix2_top__DOT__write_offset),32);
    bufp->fullIData(oldp+207,(vlSelf->tb_radix2_top__DOT__print_offset),32);
    bufp->fullIData(oldp+208,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[0]),26);
    bufp->fullIData(oldp+209,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[1]),26);
    bufp->fullIData(oldp+210,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[2]),26);
    bufp->fullIData(oldp+211,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[3]),26);
    bufp->fullIData(oldp+212,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[4]),26);
    bufp->fullIData(oldp+213,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[5]),26);
    bufp->fullIData(oldp+214,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[6]),26);
    bufp->fullIData(oldp+215,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[7]),26);
    bufp->fullIData(oldp+216,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[0]),26);
    bufp->fullIData(oldp+217,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[1]),26);
    bufp->fullIData(oldp+218,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[2]),26);
    bufp->fullIData(oldp+219,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[3]),26);
    bufp->fullIData(oldp+220,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[4]),26);
    bufp->fullIData(oldp+221,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[5]),26);
    bufp->fullIData(oldp+222,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[6]),26);
    bufp->fullIData(oldp+223,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[7]),26);
    bufp->fullIData(oldp+224,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[0]),26);
    bufp->fullIData(oldp+225,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[1]),26);
    bufp->fullIData(oldp+226,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[2]),26);
    bufp->fullIData(oldp+227,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[3]),26);
    bufp->fullIData(oldp+228,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[4]),26);
    bufp->fullIData(oldp+229,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[5]),26);
    bufp->fullIData(oldp+230,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[6]),26);
    bufp->fullIData(oldp+231,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[7]),26);
    bufp->fullIData(oldp+232,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[0]),26);
    bufp->fullIData(oldp+233,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[1]),26);
    bufp->fullIData(oldp+234,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[2]),26);
    bufp->fullIData(oldp+235,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[3]),26);
    bufp->fullIData(oldp+236,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[4]),26);
    bufp->fullIData(oldp+237,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[5]),26);
    bufp->fullIData(oldp+238,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[6]),26);
    bufp->fullIData(oldp+239,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[7]),26);
    bufp->fullBit(oldp+240,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_en));
    bufp->fullIData(oldp+241,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_0),26);
    bufp->fullIData(oldp+242,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_1),26);
    bufp->fullIData(oldp+243,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_0),26);
    bufp->fullIData(oldp+244,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_1),26);
    bufp->fullIData(oldp+245,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y0_re),26);
    bufp->fullIData(oldp+246,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y0_im),26);
    bufp->fullIData(oldp+247,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y1_re),26);
    bufp->fullIData(oldp+248,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y1_im),26);
    bufp->fullBit(oldp+249,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__butterfly_out_ready));
    bufp->fullQData(oldp+250,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
    bufp->fullQData(oldp+252,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
    bufp->fullIData(oldp+254,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
    bufp->fullIData(oldp+255,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
    bufp->fullIData(oldp+256,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
    bufp->fullIData(oldp+257,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
    bufp->fullIData(oldp+258,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
    bufp->fullIData(oldp+259,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
    bufp->fullIData(oldp+260,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
    bufp->fullIData(oldp+261,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
    bufp->fullCData(oldp+262,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
    bufp->fullIData(oldp+263,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
    bufp->fullIData(oldp+264,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
    bufp->fullSData(oldp+265,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
    bufp->fullSData(oldp+266,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
    bufp->fullQData(oldp+267,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
    bufp->fullQData(oldp+269,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
    bufp->fullIData(oldp+271,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
    bufp->fullSData(oldp+272,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
    bufp->fullSData(oldp+273,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
    bufp->fullQData(oldp+274,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
    bufp->fullQData(oldp+276,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
    bufp->fullQData(oldp+278,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
    bufp->fullQData(oldp+280,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
    bufp->fullBit(oldp+282,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_en));
    bufp->fullIData(oldp+283,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_0),26);
    bufp->fullIData(oldp+284,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_1),26);
    bufp->fullIData(oldp+285,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_0),26);
    bufp->fullIData(oldp+286,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_1),26);
    bufp->fullBit(oldp+287,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter));
    bufp->fullBit(oldp+288,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter));
    bufp->fullCData(oldp+289,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter),7);
    bufp->fullBit(oldp+290,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
    bufp->fullCData(oldp+291,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
    bufp->fullIData(oldp+292,(((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter)
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                               [1U] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [0U])),26);
    bufp->fullIData(oldp+293,(((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter)
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                               [1U] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [0U])),26);
    bufp->fullIData(oldp+294,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y0_re),26);
    bufp->fullIData(oldp+295,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y0_im),26);
    bufp->fullIData(oldp+296,(((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter)
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [0U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+297,(((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter)
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [0U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+298,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y1_re),26);
    bufp->fullIData(oldp+299,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y1_im),26);
    bufp->fullIData(oldp+300,(((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter)
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+301,(((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter)
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+302,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                              [0U]),26);
    bufp->fullIData(oldp+303,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                              [0U]),26);
    bufp->fullIData(oldp+304,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                              [1U]),26);
    bufp->fullIData(oldp+305,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                              [1U]),26);
    bufp->fullBit(oldp+306,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_out_ready));
    bufp->fullQData(oldp+307,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
    bufp->fullQData(oldp+309,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
    bufp->fullIData(oldp+311,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
    bufp->fullIData(oldp+312,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
    bufp->fullIData(oldp+313,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
    bufp->fullIData(oldp+314,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
    bufp->fullIData(oldp+315,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
    bufp->fullIData(oldp+316,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
    bufp->fullIData(oldp+317,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
    bufp->fullIData(oldp+318,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
    bufp->fullCData(oldp+319,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
    bufp->fullIData(oldp+320,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
    bufp->fullIData(oldp+321,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
    bufp->fullSData(oldp+322,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
    bufp->fullSData(oldp+323,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
    bufp->fullQData(oldp+324,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
    bufp->fullQData(oldp+326,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
    bufp->fullIData(oldp+328,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
    bufp->fullSData(oldp+329,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
    bufp->fullSData(oldp+330,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
    bufp->fullQData(oldp+331,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
    bufp->fullQData(oldp+333,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
    bufp->fullQData(oldp+335,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
    bufp->fullQData(oldp+337,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
    bufp->fullIData(oldp+339,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0]),26);
    bufp->fullIData(oldp+340,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0]),26);
    bufp->fullIData(oldp+341,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0]),26);
    bufp->fullIData(oldp+342,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1]),26);
    bufp->fullIData(oldp+343,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0]),26);
    bufp->fullIData(oldp+344,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1]),26);
    bufp->fullBit(oldp+345,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_en));
    bufp->fullIData(oldp+346,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_0),26);
    bufp->fullIData(oldp+347,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_1),26);
    bufp->fullIData(oldp+348,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_0),26);
    bufp->fullIData(oldp+349,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_1),26);
    bufp->fullCData(oldp+350,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter),2);
    bufp->fullCData(oldp+351,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter),2);
    bufp->fullCData(oldp+352,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter),7);
    bufp->fullBit(oldp+353,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
    bufp->fullCData(oldp+354,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
    bufp->fullIData(oldp+355,(((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                               [3U] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [1U])),26);
    bufp->fullIData(oldp+356,(((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                               [3U] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [1U])),26);
    bufp->fullIData(oldp+357,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y0_re),26);
    bufp->fullIData(oldp+358,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y0_im),26);
    bufp->fullIData(oldp+359,(((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [1U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+360,(((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [1U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+361,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y1_re),26);
    bufp->fullIData(oldp+362,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y1_im),26);
    bufp->fullIData(oldp+363,(((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+364,(((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+365,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                              [1U]),26);
    bufp->fullIData(oldp+366,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                              [1U]),26);
    bufp->fullIData(oldp+367,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                              [3U]),26);
    bufp->fullIData(oldp+368,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                              [3U]),26);
    bufp->fullBit(oldp+369,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_out_ready));
    bufp->fullQData(oldp+370,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
    bufp->fullQData(oldp+372,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
    bufp->fullIData(oldp+374,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
    bufp->fullIData(oldp+375,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
    bufp->fullIData(oldp+376,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
    bufp->fullIData(oldp+377,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
    bufp->fullIData(oldp+378,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
    bufp->fullIData(oldp+379,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
    bufp->fullIData(oldp+380,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
    bufp->fullIData(oldp+381,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
    bufp->fullCData(oldp+382,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
    bufp->fullIData(oldp+383,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
    bufp->fullIData(oldp+384,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
    bufp->fullSData(oldp+385,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
    bufp->fullSData(oldp+386,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
    bufp->fullQData(oldp+387,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
    bufp->fullQData(oldp+389,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
    bufp->fullIData(oldp+391,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
    bufp->fullSData(oldp+392,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
    bufp->fullSData(oldp+393,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
    bufp->fullQData(oldp+394,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
    bufp->fullQData(oldp+396,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
    bufp->fullQData(oldp+398,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
    bufp->fullQData(oldp+400,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
    bufp->fullIData(oldp+402,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0]),26);
    bufp->fullIData(oldp+403,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1]),26);
    bufp->fullIData(oldp+404,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0]),26);
    bufp->fullIData(oldp+405,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1]),26);
    bufp->fullIData(oldp+406,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0]),26);
    bufp->fullIData(oldp+407,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1]),26);
    bufp->fullIData(oldp+408,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2]),26);
    bufp->fullIData(oldp+409,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3]),26);
    bufp->fullIData(oldp+410,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0]),26);
    bufp->fullIData(oldp+411,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1]),26);
    bufp->fullIData(oldp+412,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2]),26);
    bufp->fullIData(oldp+413,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3]),26);
    bufp->fullBit(oldp+414,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_en));
    bufp->fullIData(oldp+415,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_0),26);
    bufp->fullIData(oldp+416,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_1),26);
    bufp->fullIData(oldp+417,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_0),26);
    bufp->fullIData(oldp+418,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_1),26);
    bufp->fullCData(oldp+419,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter),3);
    bufp->fullCData(oldp+420,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter),3);
    bufp->fullCData(oldp+421,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter),7);
    bufp->fullBit(oldp+422,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
    bufp->fullCData(oldp+423,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
    bufp->fullIData(oldp+424,(((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                               [7U] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [3U])),26);
    bufp->fullIData(oldp+425,(((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                               [7U] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [3U])),26);
    bufp->fullIData(oldp+426,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y0_re),26);
    bufp->fullIData(oldp+427,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y0_im),26);
    bufp->fullIData(oldp+428,(((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [3U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+429,(((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [3U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+430,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y1_re),26);
    bufp->fullIData(oldp+431,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y1_im),26);
    bufp->fullIData(oldp+432,(((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+433,(((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+434,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                              [3U]),26);
    bufp->fullIData(oldp+435,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                              [3U]),26);
    bufp->fullIData(oldp+436,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                              [7U]),26);
    bufp->fullIData(oldp+437,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                              [7U]),26);
    bufp->fullBit(oldp+438,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_out_ready));
    bufp->fullQData(oldp+439,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
    bufp->fullQData(oldp+441,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
    bufp->fullIData(oldp+443,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
    bufp->fullIData(oldp+444,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
    bufp->fullIData(oldp+445,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
    bufp->fullIData(oldp+446,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
    bufp->fullIData(oldp+447,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
    bufp->fullIData(oldp+448,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
    bufp->fullIData(oldp+449,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
    bufp->fullIData(oldp+450,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
    bufp->fullCData(oldp+451,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
    bufp->fullIData(oldp+452,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
    bufp->fullIData(oldp+453,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
    bufp->fullSData(oldp+454,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
    bufp->fullSData(oldp+455,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
    bufp->fullQData(oldp+456,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
    bufp->fullQData(oldp+458,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
    bufp->fullIData(oldp+460,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
    bufp->fullSData(oldp+461,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
    bufp->fullSData(oldp+462,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
    bufp->fullQData(oldp+463,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
    bufp->fullQData(oldp+465,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
    bufp->fullQData(oldp+467,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
    bufp->fullQData(oldp+469,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
    bufp->fullIData(oldp+471,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0]),26);
    bufp->fullIData(oldp+472,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1]),26);
    bufp->fullIData(oldp+473,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[2]),26);
    bufp->fullIData(oldp+474,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[3]),26);
    bufp->fullIData(oldp+475,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0]),26);
    bufp->fullIData(oldp+476,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1]),26);
    bufp->fullIData(oldp+477,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[2]),26);
    bufp->fullIData(oldp+478,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[3]),26);
    bufp->fullIData(oldp+479,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0]),26);
    bufp->fullIData(oldp+480,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1]),26);
    bufp->fullIData(oldp+481,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2]),26);
    bufp->fullIData(oldp+482,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3]),26);
    bufp->fullIData(oldp+483,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[4]),26);
    bufp->fullIData(oldp+484,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[5]),26);
    bufp->fullIData(oldp+485,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[6]),26);
    bufp->fullIData(oldp+486,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[7]),26);
    bufp->fullIData(oldp+487,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0]),26);
    bufp->fullIData(oldp+488,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1]),26);
    bufp->fullIData(oldp+489,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2]),26);
    bufp->fullIData(oldp+490,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3]),26);
    bufp->fullIData(oldp+491,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[4]),26);
    bufp->fullIData(oldp+492,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[5]),26);
    bufp->fullIData(oldp+493,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[6]),26);
    bufp->fullIData(oldp+494,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[7]),26);
    bufp->fullBit(oldp+495,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_en));
    bufp->fullIData(oldp+496,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_0),26);
    bufp->fullIData(oldp+497,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_1),26);
    bufp->fullIData(oldp+498,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_0),26);
    bufp->fullIData(oldp+499,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_1),26);
    bufp->fullCData(oldp+500,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter),4);
    bufp->fullCData(oldp+501,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter),4);
    bufp->fullCData(oldp+502,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter),7);
    bufp->fullBit(oldp+503,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
    bufp->fullCData(oldp+504,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
    bufp->fullIData(oldp+505,(((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                               [0xfU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [7U])),26);
    bufp->fullIData(oldp+506,(((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                               [0xfU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [7U])),26);
    bufp->fullIData(oldp+507,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y0_re),26);
    bufp->fullIData(oldp+508,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y0_im),26);
    bufp->fullIData(oldp+509,(((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [7U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+510,(((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [7U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+511,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y1_re),26);
    bufp->fullIData(oldp+512,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y1_im),26);
    bufp->fullIData(oldp+513,(((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+514,(((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+515,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                              [7U]),26);
    bufp->fullIData(oldp+516,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                              [7U]),26);
    bufp->fullIData(oldp+517,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                              [0xfU]),26);
    bufp->fullIData(oldp+518,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                              [0xfU]),26);
    bufp->fullBit(oldp+519,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_out_ready));
    bufp->fullQData(oldp+520,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
    bufp->fullQData(oldp+522,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
    bufp->fullIData(oldp+524,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
    bufp->fullIData(oldp+525,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
    bufp->fullIData(oldp+526,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
    bufp->fullIData(oldp+527,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
    bufp->fullIData(oldp+528,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
    bufp->fullIData(oldp+529,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
    bufp->fullIData(oldp+530,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
    bufp->fullIData(oldp+531,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
    bufp->fullCData(oldp+532,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
    bufp->fullIData(oldp+533,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
    bufp->fullIData(oldp+534,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
    bufp->fullSData(oldp+535,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
    bufp->fullSData(oldp+536,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
    bufp->fullQData(oldp+537,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
    bufp->fullQData(oldp+539,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
    bufp->fullIData(oldp+541,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
    bufp->fullSData(oldp+542,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
    bufp->fullSData(oldp+543,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
    bufp->fullQData(oldp+544,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
    bufp->fullQData(oldp+546,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
    bufp->fullQData(oldp+548,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
    bufp->fullQData(oldp+550,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
    bufp->fullIData(oldp+552,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0]),26);
    bufp->fullIData(oldp+553,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1]),26);
    bufp->fullIData(oldp+554,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[2]),26);
    bufp->fullIData(oldp+555,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[3]),26);
    bufp->fullIData(oldp+556,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[4]),26);
    bufp->fullIData(oldp+557,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[5]),26);
    bufp->fullIData(oldp+558,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[6]),26);
    bufp->fullIData(oldp+559,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[7]),26);
    bufp->fullIData(oldp+560,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0]),26);
    bufp->fullIData(oldp+561,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1]),26);
    bufp->fullIData(oldp+562,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[2]),26);
    bufp->fullIData(oldp+563,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[3]),26);
    bufp->fullIData(oldp+564,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[4]),26);
    bufp->fullIData(oldp+565,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[5]),26);
    bufp->fullIData(oldp+566,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[6]),26);
    bufp->fullIData(oldp+567,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[7]),26);
    bufp->fullIData(oldp+568,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0]),26);
    bufp->fullIData(oldp+569,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1]),26);
    bufp->fullIData(oldp+570,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2]),26);
    bufp->fullIData(oldp+571,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3]),26);
    bufp->fullIData(oldp+572,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[4]),26);
    bufp->fullIData(oldp+573,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[5]),26);
    bufp->fullIData(oldp+574,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[6]),26);
    bufp->fullIData(oldp+575,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[7]),26);
    bufp->fullIData(oldp+576,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[8]),26);
    bufp->fullIData(oldp+577,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[9]),26);
    bufp->fullIData(oldp+578,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[10]),26);
    bufp->fullIData(oldp+579,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[11]),26);
    bufp->fullIData(oldp+580,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[12]),26);
    bufp->fullIData(oldp+581,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[13]),26);
    bufp->fullIData(oldp+582,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[14]),26);
    bufp->fullIData(oldp+583,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[15]),26);
    bufp->fullIData(oldp+584,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0]),26);
    bufp->fullIData(oldp+585,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1]),26);
    bufp->fullIData(oldp+586,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2]),26);
    bufp->fullIData(oldp+587,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3]),26);
    bufp->fullIData(oldp+588,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[4]),26);
    bufp->fullIData(oldp+589,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[5]),26);
    bufp->fullIData(oldp+590,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[6]),26);
    bufp->fullIData(oldp+591,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[7]),26);
    bufp->fullIData(oldp+592,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[8]),26);
    bufp->fullIData(oldp+593,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[9]),26);
    bufp->fullIData(oldp+594,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[10]),26);
    bufp->fullIData(oldp+595,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[11]),26);
    bufp->fullIData(oldp+596,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[12]),26);
    bufp->fullIData(oldp+597,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[13]),26);
    bufp->fullIData(oldp+598,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[14]),26);
    bufp->fullIData(oldp+599,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[15]),26);
    bufp->fullBit(oldp+600,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_en));
    bufp->fullIData(oldp+601,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_0),26);
    bufp->fullIData(oldp+602,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_1),26);
    bufp->fullIData(oldp+603,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_0),26);
    bufp->fullIData(oldp+604,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_1),26);
    bufp->fullCData(oldp+605,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter),5);
    bufp->fullCData(oldp+606,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter),5);
    bufp->fullCData(oldp+607,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter),7);
    bufp->fullBit(oldp+608,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
    bufp->fullCData(oldp+609,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
    bufp->fullIData(oldp+610,(((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                               [0x1fU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [0xfU])),26);
    bufp->fullIData(oldp+611,(((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                               [0x1fU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [0xfU])),26);
    bufp->fullIData(oldp+612,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y0_re),26);
    bufp->fullIData(oldp+613,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y0_im),26);
    bufp->fullIData(oldp+614,(((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [0xfU] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+615,(((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [0xfU] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+616,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y1_re),26);
    bufp->fullIData(oldp+617,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y1_im),26);
    bufp->fullIData(oldp+618,(((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+619,(((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+620,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                              [0xfU]),26);
    bufp->fullIData(oldp+621,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                              [0xfU]),26);
    bufp->fullIData(oldp+622,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                              [0x1fU]),26);
    bufp->fullIData(oldp+623,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                              [0x1fU]),26);
    bufp->fullBit(oldp+624,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_out_ready));
    bufp->fullQData(oldp+625,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
    bufp->fullQData(oldp+627,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
    bufp->fullIData(oldp+629,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
    bufp->fullIData(oldp+630,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
    bufp->fullIData(oldp+631,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
    bufp->fullIData(oldp+632,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
    bufp->fullIData(oldp+633,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
    bufp->fullIData(oldp+634,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
    bufp->fullIData(oldp+635,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
    bufp->fullIData(oldp+636,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
    bufp->fullCData(oldp+637,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
    bufp->fullIData(oldp+638,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
    bufp->fullIData(oldp+639,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
    bufp->fullSData(oldp+640,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
    bufp->fullSData(oldp+641,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
    bufp->fullQData(oldp+642,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
    bufp->fullQData(oldp+644,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
    bufp->fullIData(oldp+646,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
    bufp->fullSData(oldp+647,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
    bufp->fullSData(oldp+648,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
    bufp->fullQData(oldp+649,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
    bufp->fullQData(oldp+651,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
    bufp->fullQData(oldp+653,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
    bufp->fullQData(oldp+655,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
    bufp->fullIData(oldp+657,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0]),26);
    bufp->fullIData(oldp+658,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1]),26);
    bufp->fullIData(oldp+659,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[2]),26);
    bufp->fullIData(oldp+660,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[3]),26);
    bufp->fullIData(oldp+661,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[4]),26);
    bufp->fullIData(oldp+662,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[5]),26);
    bufp->fullIData(oldp+663,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[6]),26);
    bufp->fullIData(oldp+664,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[7]),26);
    bufp->fullIData(oldp+665,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[8]),26);
    bufp->fullIData(oldp+666,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[9]),26);
    bufp->fullIData(oldp+667,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[10]),26);
    bufp->fullIData(oldp+668,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[11]),26);
    bufp->fullIData(oldp+669,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[12]),26);
    bufp->fullIData(oldp+670,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[13]),26);
    bufp->fullIData(oldp+671,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[14]),26);
    bufp->fullIData(oldp+672,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[15]),26);
    bufp->fullIData(oldp+673,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0]),26);
    bufp->fullIData(oldp+674,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1]),26);
    bufp->fullIData(oldp+675,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[2]),26);
    bufp->fullIData(oldp+676,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[3]),26);
    bufp->fullIData(oldp+677,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[4]),26);
    bufp->fullIData(oldp+678,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[5]),26);
    bufp->fullIData(oldp+679,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[6]),26);
    bufp->fullIData(oldp+680,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[7]),26);
    bufp->fullIData(oldp+681,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[8]),26);
    bufp->fullIData(oldp+682,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[9]),26);
    bufp->fullIData(oldp+683,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[10]),26);
    bufp->fullIData(oldp+684,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[11]),26);
    bufp->fullIData(oldp+685,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[12]),26);
    bufp->fullIData(oldp+686,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[13]),26);
    bufp->fullIData(oldp+687,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[14]),26);
    bufp->fullIData(oldp+688,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[15]),26);
    bufp->fullIData(oldp+689,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0]),26);
    bufp->fullIData(oldp+690,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1]),26);
    bufp->fullIData(oldp+691,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2]),26);
    bufp->fullIData(oldp+692,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3]),26);
    bufp->fullIData(oldp+693,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[4]),26);
    bufp->fullIData(oldp+694,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[5]),26);
    bufp->fullIData(oldp+695,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[6]),26);
    bufp->fullIData(oldp+696,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[7]),26);
    bufp->fullIData(oldp+697,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[8]),26);
    bufp->fullIData(oldp+698,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[9]),26);
    bufp->fullIData(oldp+699,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[10]),26);
    bufp->fullIData(oldp+700,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[11]),26);
    bufp->fullIData(oldp+701,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[12]),26);
    bufp->fullIData(oldp+702,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[13]),26);
    bufp->fullIData(oldp+703,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[14]),26);
    bufp->fullIData(oldp+704,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[15]),26);
    bufp->fullIData(oldp+705,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[16]),26);
    bufp->fullIData(oldp+706,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[17]),26);
    bufp->fullIData(oldp+707,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[18]),26);
    bufp->fullIData(oldp+708,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[19]),26);
    bufp->fullIData(oldp+709,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[20]),26);
    bufp->fullIData(oldp+710,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[21]),26);
    bufp->fullIData(oldp+711,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[22]),26);
    bufp->fullIData(oldp+712,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[23]),26);
    bufp->fullIData(oldp+713,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[24]),26);
    bufp->fullIData(oldp+714,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[25]),26);
    bufp->fullIData(oldp+715,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[26]),26);
    bufp->fullIData(oldp+716,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[27]),26);
    bufp->fullIData(oldp+717,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[28]),26);
    bufp->fullIData(oldp+718,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[29]),26);
    bufp->fullIData(oldp+719,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[30]),26);
    bufp->fullIData(oldp+720,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[31]),26);
    bufp->fullIData(oldp+721,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0]),26);
    bufp->fullIData(oldp+722,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1]),26);
    bufp->fullIData(oldp+723,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2]),26);
    bufp->fullIData(oldp+724,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3]),26);
    bufp->fullIData(oldp+725,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[4]),26);
    bufp->fullIData(oldp+726,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[5]),26);
    bufp->fullIData(oldp+727,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[6]),26);
    bufp->fullIData(oldp+728,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[7]),26);
    bufp->fullIData(oldp+729,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[8]),26);
    bufp->fullIData(oldp+730,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[9]),26);
    bufp->fullIData(oldp+731,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[10]),26);
    bufp->fullIData(oldp+732,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[11]),26);
    bufp->fullIData(oldp+733,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[12]),26);
    bufp->fullIData(oldp+734,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[13]),26);
    bufp->fullIData(oldp+735,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[14]),26);
    bufp->fullIData(oldp+736,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[15]),26);
    bufp->fullIData(oldp+737,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[16]),26);
    bufp->fullIData(oldp+738,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[17]),26);
    bufp->fullIData(oldp+739,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[18]),26);
    bufp->fullIData(oldp+740,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[19]),26);
    bufp->fullIData(oldp+741,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[20]),26);
    bufp->fullIData(oldp+742,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[21]),26);
    bufp->fullIData(oldp+743,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[22]),26);
    bufp->fullIData(oldp+744,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[23]),26);
    bufp->fullIData(oldp+745,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[24]),26);
    bufp->fullIData(oldp+746,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[25]),26);
    bufp->fullIData(oldp+747,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[26]),26);
    bufp->fullIData(oldp+748,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[27]),26);
    bufp->fullIData(oldp+749,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[28]),26);
    bufp->fullIData(oldp+750,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[29]),26);
    bufp->fullIData(oldp+751,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[30]),26);
    bufp->fullIData(oldp+752,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[31]),26);
    bufp->fullBit(oldp+753,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_en));
    bufp->fullIData(oldp+754,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_0),26);
    bufp->fullIData(oldp+755,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_1),26);
    bufp->fullIData(oldp+756,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_0),26);
    bufp->fullIData(oldp+757,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_1),26);
    bufp->fullCData(oldp+758,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter),6);
    bufp->fullCData(oldp+759,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter),6);
    bufp->fullCData(oldp+760,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter),7);
    bufp->fullBit(oldp+761,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
    bufp->fullCData(oldp+762,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
    bufp->fullIData(oldp+763,(((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                               [0x3fU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [0x1fU])),26);
    bufp->fullIData(oldp+764,(((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                               [0x3fU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [0x1fU])),26);
    bufp->fullIData(oldp+765,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y0_re),26);
    bufp->fullIData(oldp+766,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y0_im),26);
    bufp->fullIData(oldp+767,(((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [0x1fU] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+768,(((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [0x1fU] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+769,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y1_re),26);
    bufp->fullIData(oldp+770,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y1_im),26);
    bufp->fullIData(oldp+771,(((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+772,(((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+773,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                              [0x1fU]),26);
    bufp->fullIData(oldp+774,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                              [0x1fU]),26);
    bufp->fullIData(oldp+775,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                              [0x3fU]),26);
    bufp->fullIData(oldp+776,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                              [0x3fU]),26);
    bufp->fullBit(oldp+777,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_out_ready));
    bufp->fullQData(oldp+778,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
    bufp->fullQData(oldp+780,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
    bufp->fullIData(oldp+782,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
    bufp->fullIData(oldp+783,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
    bufp->fullIData(oldp+784,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
    bufp->fullIData(oldp+785,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
    bufp->fullIData(oldp+786,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
    bufp->fullIData(oldp+787,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
    bufp->fullIData(oldp+788,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
    bufp->fullIData(oldp+789,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
    bufp->fullCData(oldp+790,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
    bufp->fullIData(oldp+791,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
    bufp->fullIData(oldp+792,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
    bufp->fullSData(oldp+793,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
    bufp->fullSData(oldp+794,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
    bufp->fullQData(oldp+795,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
    bufp->fullQData(oldp+797,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
    bufp->fullIData(oldp+799,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
    bufp->fullSData(oldp+800,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
    bufp->fullSData(oldp+801,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
    bufp->fullQData(oldp+802,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
    bufp->fullQData(oldp+804,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
    bufp->fullQData(oldp+806,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
    bufp->fullQData(oldp+808,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
    bufp->fullIData(oldp+810,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0]),26);
    bufp->fullIData(oldp+811,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1]),26);
    bufp->fullIData(oldp+812,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[2]),26);
    bufp->fullIData(oldp+813,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[3]),26);
    bufp->fullIData(oldp+814,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[4]),26);
    bufp->fullIData(oldp+815,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[5]),26);
    bufp->fullIData(oldp+816,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[6]),26);
    bufp->fullIData(oldp+817,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[7]),26);
    bufp->fullIData(oldp+818,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[8]),26);
    bufp->fullIData(oldp+819,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[9]),26);
    bufp->fullIData(oldp+820,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[10]),26);
    bufp->fullIData(oldp+821,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[11]),26);
    bufp->fullIData(oldp+822,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[12]),26);
    bufp->fullIData(oldp+823,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[13]),26);
    bufp->fullIData(oldp+824,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[14]),26);
    bufp->fullIData(oldp+825,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[15]),26);
    bufp->fullIData(oldp+826,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[16]),26);
    bufp->fullIData(oldp+827,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[17]),26);
    bufp->fullIData(oldp+828,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[18]),26);
    bufp->fullIData(oldp+829,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[19]),26);
    bufp->fullIData(oldp+830,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[20]),26);
    bufp->fullIData(oldp+831,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[21]),26);
    bufp->fullIData(oldp+832,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[22]),26);
    bufp->fullIData(oldp+833,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[23]),26);
    bufp->fullIData(oldp+834,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[24]),26);
    bufp->fullIData(oldp+835,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[25]),26);
    bufp->fullIData(oldp+836,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[26]),26);
    bufp->fullIData(oldp+837,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[27]),26);
    bufp->fullIData(oldp+838,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[28]),26);
    bufp->fullIData(oldp+839,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[29]),26);
    bufp->fullIData(oldp+840,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[30]),26);
    bufp->fullIData(oldp+841,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[31]),26);
    bufp->fullIData(oldp+842,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0]),26);
    bufp->fullIData(oldp+843,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1]),26);
    bufp->fullIData(oldp+844,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[2]),26);
    bufp->fullIData(oldp+845,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[3]),26);
    bufp->fullIData(oldp+846,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[4]),26);
    bufp->fullIData(oldp+847,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[5]),26);
    bufp->fullIData(oldp+848,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[6]),26);
    bufp->fullIData(oldp+849,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[7]),26);
    bufp->fullIData(oldp+850,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[8]),26);
    bufp->fullIData(oldp+851,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[9]),26);
    bufp->fullIData(oldp+852,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[10]),26);
    bufp->fullIData(oldp+853,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[11]),26);
    bufp->fullIData(oldp+854,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[12]),26);
    bufp->fullIData(oldp+855,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[13]),26);
    bufp->fullIData(oldp+856,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[14]),26);
    bufp->fullIData(oldp+857,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[15]),26);
    bufp->fullIData(oldp+858,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[16]),26);
    bufp->fullIData(oldp+859,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[17]),26);
    bufp->fullIData(oldp+860,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[18]),26);
    bufp->fullIData(oldp+861,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[19]),26);
    bufp->fullIData(oldp+862,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[20]),26);
    bufp->fullIData(oldp+863,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[21]),26);
    bufp->fullIData(oldp+864,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[22]),26);
    bufp->fullIData(oldp+865,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[23]),26);
    bufp->fullIData(oldp+866,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[24]),26);
    bufp->fullIData(oldp+867,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[25]),26);
    bufp->fullIData(oldp+868,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[26]),26);
    bufp->fullIData(oldp+869,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[27]),26);
    bufp->fullIData(oldp+870,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[28]),26);
    bufp->fullIData(oldp+871,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[29]),26);
    bufp->fullIData(oldp+872,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[30]),26);
    bufp->fullIData(oldp+873,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[31]),26);
    bufp->fullCData(oldp+874,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter),7);
    bufp->fullCData(oldp+875,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter),7);
    bufp->fullCData(oldp+876,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter),7);
    bufp->fullBit(oldp+877,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
    bufp->fullCData(oldp+878,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
    bufp->fullIData(oldp+879,(((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                               [0x7fU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [0x3fU])),26);
    bufp->fullIData(oldp+880,(((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                               [0x7fU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [0x3fU])),26);
    bufp->fullIData(oldp+881,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y0_re),26);
    bufp->fullIData(oldp+882,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y0_im),26);
    bufp->fullIData(oldp+883,(((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                               [0x3fU] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+884,(((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                               [0x3fU] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+885,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y1_re),26);
    bufp->fullIData(oldp+886,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y1_im),26);
    bufp->fullIData(oldp+887,(((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_0)),26);
    bufp->fullIData(oldp+888,(((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_1
                                : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_0)),26);
    bufp->fullIData(oldp+889,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                              [0x3fU]),26);
    bufp->fullIData(oldp+890,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                              [0x3fU]),26);
    bufp->fullIData(oldp+891,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                              [0x7fU]),26);
    bufp->fullIData(oldp+892,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                              [0x7fU]),26);
    bufp->fullBit(oldp+893,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_out_ready));
    bufp->fullQData(oldp+894,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
    bufp->fullQData(oldp+896,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
    bufp->fullIData(oldp+898,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
    bufp->fullIData(oldp+899,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
    bufp->fullIData(oldp+900,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
    bufp->fullIData(oldp+901,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
    bufp->fullIData(oldp+902,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
    bufp->fullIData(oldp+903,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
    bufp->fullIData(oldp+904,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
    bufp->fullIData(oldp+905,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
    bufp->fullCData(oldp+906,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
    bufp->fullIData(oldp+907,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
    bufp->fullIData(oldp+908,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
    bufp->fullSData(oldp+909,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
    bufp->fullSData(oldp+910,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
    bufp->fullQData(oldp+911,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
    bufp->fullQData(oldp+913,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
    bufp->fullIData(oldp+915,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
    bufp->fullSData(oldp+916,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
    bufp->fullSData(oldp+917,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
    bufp->fullQData(oldp+918,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
    bufp->fullQData(oldp+920,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
    bufp->fullQData(oldp+922,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
    bufp->fullQData(oldp+924,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
    bufp->fullBit(oldp+926,(vlSelf->tb_radix2_top__DOT__clock));
}
