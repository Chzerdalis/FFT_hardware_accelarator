// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_radix2_top.h for the primary calling header

#include "Vtb_radix2_top__pch.h"
#include "Vtb_radix2_top___024root.h"

VL_ATTR_COLD void Vtb_radix2_top___024root___eval_static__TOP(Vtb_radix2_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_radix2_top___024root___eval_static(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_static\n"); );
    // Body
    Vtb_radix2_top___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtb_radix2_top___024root___eval_static__TOP(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->tb_radix2_top__DOT__total_samples_read = 0U;
    vlSelf->tb_radix2_top__DOT__output_count = 0U;
    vlSelf->tb_radix2_top__DOT__frame_ready = 0U;
    vlSelf->tb_radix2_top__DOT__window_count = 0U;
    vlSelf->tb_radix2_top__DOT__write_offset = 0U;
    vlSelf->tb_radix2_top__DOT__print_offset = 0U;
    vlSelf->tb_radix2_top__DOT__input_en_d = 0U;
    vlSelf->tb_radix2_top__DOT__output_en_d = 0U;
    vlSelf->tb_radix2_top__DOT__counting_latency = 0U;
    vlSelf->tb_radix2_top__DOT__t_latency = 0U;
    vlSelf->tb_radix2_top__DOT__counting_active = 0U;
    vlSelf->tb_radix2_top__DOT__t_active = 0U;
}

VL_ATTR_COLD void Vtb_radix2_top___024root___eval_initial__TOP(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ tb_radix2_top__DOT__in_file_id;
    tb_radix2_top__DOT__in_file_id = 0;
    IData/*31:0*/ tb_radix2_top__DOT__i;
    tb_radix2_top__DOT__i = 0;
    VlUnpacked<CData/*7:0*/, 1> tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_real;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_real[__Vi0] = 0;
    }
    VlUnpacked<CData/*7:0*/, 1> tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_imag;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_imag[__Vi0] = 0;
    }
    VlWide<6>/*191:0*/ __Vtemp_1;
    VlWide<6>/*191:0*/ __Vtemp_4;
    // Body
    __Vtemp_1[0U] = 0x2e747874U;
    __Vtemp_1[1U] = 0x64617461U;
    __Vtemp_1[2U] = 0x7075745fU;
    __Vtemp_1[3U] = 0x612f696eU;
    __Vtemp_1[4U] = 0x2f446174U;
    __Vtemp_1[5U] = 0x2e2eU;
    tb_radix2_top__DOT__in_file_id = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(6, __Vtemp_1)
                                                 , 
                                                 std::string{"r"});
    ;
    if (VL_UNLIKELY((0U == tb_radix2_top__DOT__in_file_id))) {
        VL_WRITEF("ERROR: Could not open input_data.txt. Please ensure it is in the run directory.\n");
        VL_FINISH_MT("../Radix-2/tb_top_radix_2.v", 78, "");
    }
    while (((! (tb_radix2_top__DOT__in_file_id ? feof(VL_CVT_I_FP(tb_radix2_top__DOT__in_file_id)) : true)) 
            && VL_GTS_III(32, 0x4e8U, vlSelf->tb_radix2_top__DOT__total_samples_read))) {
        vlSelf->tb_radix2_top__DOT__scan_count = VL_FSCANF_IX(tb_radix2_top__DOT__in_file_id,"%# %#",
                                                              32,
                                                              &(vlSelf->tb_radix2_top__DOT__t_i),
                                                              32,
                                                              &(vlSelf->tb_radix2_top__DOT__t_r)) ;
        if ((2U == vlSelf->tb_radix2_top__DOT__scan_count)) {
            vlSelf->tb_radix2_top__DOT____Vlvbound_he6a872a1__0 
                = (0xffffU & vlSelf->tb_radix2_top__DOT__t_r);
            vlSelf->tb_radix2_top__DOT____Vlvbound_h1a871cae__0 
                = (0xffffU & vlSelf->tb_radix2_top__DOT__t_i);
            if ((0x4e7U >= (0x7ffU & vlSelf->tb_radix2_top__DOT__total_samples_read))) {
                vlSelf->tb_radix2_top__DOT__file_imag_data[(0x7ffU 
                                                            & vlSelf->tb_radix2_top__DOT__total_samples_read)] 
                    = vlSelf->tb_radix2_top__DOT____Vlvbound_he6a872a1__0;
                vlSelf->tb_radix2_top__DOT__file_real_data[(0x7ffU 
                                                            & vlSelf->tb_radix2_top__DOT__total_samples_read)] 
                    = vlSelf->tb_radix2_top__DOT____Vlvbound_h1a871cae__0;
            }
            vlSelf->tb_radix2_top__DOT__total_samples_read 
                = ((IData)(1U) + vlSelf->tb_radix2_top__DOT__total_samples_read);
        }
    }
    tb_radix2_top__DOT__i = 0U;
    while (VL_LTS_III(32, tb_radix2_top__DOT__i, vlSelf->tb_radix2_top__DOT__total_samples_read)) {
        tb_radix2_top__DOT__i = ((IData)(1U) + tb_radix2_top__DOT__i);
    }
    VL_FCLOSE_I(tb_radix2_top__DOT__in_file_id); __Vtemp_4[0U] = 0x2e747874U;
    __Vtemp_4[1U] = 0x63696573U;
    __Vtemp_4[2U] = 0x6174656eU;
    __Vtemp_4[3U] = 0x74612f6cU;
    __Vtemp_4[4U] = 0x2e2f4461U;
    __Vtemp_4[5U] = 0x2eU;
    vlSelf->tb_radix2_top__DOT__file_id = VL_FOPEN_NN(
                                                      VL_CVT_PACK_STR_NW(6, __Vtemp_4)
                                                      , 
                                                      std::string{"w"});
    ;
    if (VL_UNLIKELY((0U == vlSelf->tb_radix2_top__DOT__file_id))) {
        VL_WRITEF("Error: Could not open latencies file.\n");
        VL_FINISH_MT("../Radix-2/tb_top_radix_2.v", 240, "");
    }
    VL_READMEM_N(true, 8, 1, 0, std::string{"../Data/f_twiddle_real_1.mem"}
                 ,  &(tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_real)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 1, 0, std::string{"../Data/f_twiddle_imag_1.mem"}
                 ,  &(tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_imag)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 2, 0, std::string{"../Data/f_twiddle_real_2.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_real)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 2, 0, std::string{"../Data/f_twiddle_imag_2.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_imag)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 4, 0, std::string{"../Data/f_twiddle_real_3.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 4, 0, std::string{"../Data/f_twiddle_imag_3.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 8, 0, std::string{"../Data/f_twiddle_real_4.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 8, 0, std::string{"../Data/f_twiddle_imag_4.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 16, 0, std::string{"../Data/f_twiddle_real_5.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 16, 0, std::string{"../Data/f_twiddle_imag_5.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 32, 0, std::string{"../Data/f_twiddle_real_6.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 32, 0, std::string{"../Data/f_twiddle_imag_6.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 64, 0, std::string{"../Data/f_twiddle_real_7.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__w_real)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 64, 0, std::string{"../Data/f_twiddle_imag_7.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__w_imag)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 128, 0, std::string{"../Data/f_twiddle_real_8.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__w_real)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 128, 0, std::string{"../Data/f_twiddle_imag_8.mem"}
                 ,  &(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__w_imag)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb_radix2_top___024root___eval_final(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_radix2_top___024root___dump_triggers__stl(Vtb_radix2_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_radix2_top___024root___eval_phase__stl(Vtb_radix2_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_radix2_top___024root___eval_settle(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_radix2_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../Radix-2/tb_top_radix_2.v", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_radix2_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_radix2_top___024root___dump_triggers__stl(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_radix2_top___024root___stl_sequent__TOP__0(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    if (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [0U];
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [0U];
    } else {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_0;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_0;
    }
    if ((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter))) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [1U];
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [1U];
    } else {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_0;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_0;
    }
    if ((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter))) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [3U];
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [3U];
    } else {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_0;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_0;
    }
    if ((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter))) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [7U];
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [7U];
    } else {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_0;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_0;
    }
    if ((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter))) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [0xfU];
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [0xfU];
    } else {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_0;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_0;
    }
    if ((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter))) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [0x1fU];
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [0x1fU];
    } else {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_0;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_0;
    }
    if ((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter))) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [0x3fU];
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [0x3fU];
    } else {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_re 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_0;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_im 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_0;
    }
}

VL_ATTR_COLD void Vtb_radix2_top___024root___eval_stl(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_radix2_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_radix2_top___024root___eval_triggers__stl(Vtb_radix2_top___024root* vlSelf);

VL_ATTR_COLD bool Vtb_radix2_top___024root___eval_phase__stl(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_radix2_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_radix2_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_radix2_top___024root___dump_triggers__act(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_radix2_top.clock)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_radix2_top.clock or posedge tb_radix2_top.reset)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_radix2_top___024root___dump_triggers__nba(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_radix2_top.clock)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_radix2_top.clock or posedge tb_radix2_top.reset)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_radix2_top___024root___ctor_var_reset(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_radix2_top__DOT__clock = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__input_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__input_real_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__input_real_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__input_imag_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__input_imag_1 = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__output_real[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__output_imag[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 1256; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__file_real_data[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 1256; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__file_imag_data[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_radix2_top__DOT__total_samples_read = VL_RAND_RESET_I(32);
    vlSelf->tb_radix2_top__DOT__output_count = VL_RAND_RESET_I(32);
    vlSelf->tb_radix2_top__DOT__out_file_id = 0;
    vlSelf->tb_radix2_top__DOT__scan_count = VL_RAND_RESET_I(32);
    vlSelf->tb_radix2_top__DOT__t_i = VL_RAND_RESET_I(32);
    vlSelf->tb_radix2_top__DOT__t_r = VL_RAND_RESET_I(32);
    vlSelf->tb_radix2_top__DOT__k = VL_RAND_RESET_I(32);
    vlSelf->tb_radix2_top__DOT__frame_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__window_count = VL_RAND_RESET_I(32);
    vlSelf->tb_radix2_top__DOT__write_offset = VL_RAND_RESET_I(32);
    vlSelf->tb_radix2_top__DOT__print_offset = VL_RAND_RESET_I(32);
    vlSelf->tb_radix2_top__DOT__file_id = VL_RAND_RESET_I(32);
    vlSelf->tb_radix2_top__DOT__input_en_d = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__output_en_d = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__counting_latency = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__t_latency = VL_RAND_RESET_I(32);
    vlSelf->tb_radix2_top__DOT__counting_active = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__t_active = VL_RAND_RESET_I(32);
    vlSelf->tb_radix2_top__DOT____Vlvbound_he6a872a1__0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT____Vlvbound_h1a871cae__0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_imag_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_imag_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_real_1 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_real_0 = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y0_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y0_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y1_im = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter = VL_RAND_RESET_I(7);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y0_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y0_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__x1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__x1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__wr = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__wi = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_real[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_imag[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in = VL_RAND_RESET_I(17);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter = VL_RAND_RESET_I(2);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter = VL_RAND_RESET_I(2);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter = VL_RAND_RESET_I(7);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y0_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y0_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__x1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__x1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__wr = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__wi = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in = VL_RAND_RESET_I(17);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter = VL_RAND_RESET_I(3);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter = VL_RAND_RESET_I(3);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter = VL_RAND_RESET_I(7);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y0_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y0_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__x1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__x1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__wr = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__wi = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in = VL_RAND_RESET_I(17);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter = VL_RAND_RESET_I(4);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter = VL_RAND_RESET_I(4);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter = VL_RAND_RESET_I(7);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y0_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y0_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__x1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__x1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__wr = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__wi = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in = VL_RAND_RESET_I(17);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter = VL_RAND_RESET_I(5);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter = VL_RAND_RESET_I(5);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter = VL_RAND_RESET_I(7);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y0_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y0_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__x1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__x1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__wr = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__wi = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in = VL_RAND_RESET_I(17);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter = VL_RAND_RESET_I(6);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter = VL_RAND_RESET_I(6);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter = VL_RAND_RESET_I(7);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y0_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y0_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wr = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wi = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__w_real[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__w_imag[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in = VL_RAND_RESET_I(17);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter = VL_RAND_RESET_I(7);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter = VL_RAND_RESET_I(7);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter = VL_RAND_RESET_I(7);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y0_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y0_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y1_re = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y1_im = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wr = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wi = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__w_real[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__w_imag[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in = VL_RAND_RESET_I(17);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in = VL_RAND_RESET_I(9);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d = VL_RAND_RESET_I(16);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d = VL_RAND_RESET_I(8);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a = VL_RAND_RESET_I(25);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a = VL_RAND_RESET_I(25);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_radix2_top__DOT__clock__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_radix2_top__DOT__reset__0 = VL_RAND_RESET_I(1);
}
