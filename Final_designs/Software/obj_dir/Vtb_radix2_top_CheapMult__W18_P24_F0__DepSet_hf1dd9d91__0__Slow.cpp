// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_radix2_top.h for the primary calling header

#include "Vtb_radix2_top__pch.h"
#include "Vtb_radix2_top_CheapMult__W18_P24_F0.h"

VL_ATTR_COLD void Vtb_radix2_top_CheapMult__W18_P24_F0___stl_sequent__TOP__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__0(Vtb_radix2_top_CheapMult__W18_P24_F0* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtb_radix2_top_CheapMult__W18_P24_F0___stl_sequent__TOP__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__0\n"); );
    // Body
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w 
        = ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_do_sub)
            ? (0x1fffffffffULL & (~ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_pp))
            : 0ULL);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w 
        = ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_do_sub)
            ? (0x1fffffffffULL & (~ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_pp))
            : 0ULL);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w 
        = ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_do_sub)
            ? (0x1fffffffffULL & (~ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_pp))
            : 0ULL);
}

VL_ATTR_COLD void Vtb_radix2_top_CheapMult__W18_P24_F0___ctor_var_reset(Vtb_radix2_top_CheapMult__W18_P24_F0* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtb_radix2_top_CheapMult__W18_P24_F0___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->a_re = VL_RAND_RESET_I(24);
    vlSelf->a_im = VL_RAND_RESET_I(24);
    vlSelf->w0re = VL_RAND_RESET_I(12);
    vlSelf->w0im = VL_RAND_RESET_I(12);
    vlSelf->out_a_re = VL_RAND_RESET_Q(37);
    vlSelf->out_a_im = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_a_in = VL_RAND_RESET_I(25);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_w0_in = VL_RAND_RESET_I(13);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__diff_w0_in = VL_RAND_RESET_I(13);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_re_d = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_im_d = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__w0re_d = VL_RAND_RESET_I(12);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k2_a = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k3_a = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a_reg = VL_RAND_RESET_Q(37);
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[__Vi0] = VL_RAND_RESET_Q(37);
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[__Vi0] = VL_RAND_RESET_I(12);
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[__Vi0] = VL_RAND_RESET_Q(37);
    }
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[__Vi0] = VL_RAND_RESET_Q(37);
    }
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_sum = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_carry = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_pp = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_do_sub = VL_RAND_RESET_I(1);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_sum_r = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_carry_r = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_cin_r = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe[__Vi0] = VL_RAND_RESET_Q(40);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe[__Vi0] = VL_RAND_RESET_Q(40);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[__Vi0] = VL_RAND_RESET_Q(40);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 13; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[__Vi0] = VL_RAND_RESET_Q(37);
    }
    for (int __Vi0 = 0; __Vi0 < 13; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[__Vi0] = VL_RAND_RESET_I(13);
    }
    for (int __Vi0 = 0; __Vi0 < 13; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[__Vi0] = VL_RAND_RESET_Q(37);
    }
    for (int __Vi0 = 0; __Vi0 < 13; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[__Vi0] = VL_RAND_RESET_Q(37);
    }
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_sum = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_carry = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_pp = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_do_sub = VL_RAND_RESET_I(1);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_sum_r = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_carry_r = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_cin_r = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe[__Vi0] = VL_RAND_RESET_Q(40);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe[__Vi0] = VL_RAND_RESET_Q(40);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[__Vi0] = VL_RAND_RESET_Q(40);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 13; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[__Vi0] = VL_RAND_RESET_Q(37);
    }
    for (int __Vi0 = 0; __Vi0 < 13; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[__Vi0] = VL_RAND_RESET_I(13);
    }
    for (int __Vi0 = 0; __Vi0 < 13; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[__Vi0] = VL_RAND_RESET_Q(37);
    }
    for (int __Vi0 = 0; __Vi0 < 13; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[__Vi0] = VL_RAND_RESET_Q(37);
    }
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_sum = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_carry = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_pp = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_do_sub = VL_RAND_RESET_I(1);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_sum_r = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_carry_r = VL_RAND_RESET_Q(37);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_cin_r = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe[__Vi0] = VL_RAND_RESET_Q(40);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe[__Vi0] = VL_RAND_RESET_Q(40);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[__Vi0] = VL_RAND_RESET_Q(40);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe[__Vi0] = VL_RAND_RESET_I(1);
    }
}
