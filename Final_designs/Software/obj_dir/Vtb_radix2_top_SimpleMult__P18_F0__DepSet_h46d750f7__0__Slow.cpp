// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_radix2_top.h for the primary calling header

#include "Vtb_radix2_top__pch.h"
#include "Vtb_radix2_top_SimpleMult__P18_F0.h"

VL_ATTR_COLD void Vtb_radix2_top_SimpleMult__P18_F0___stl_sequent__TOP__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__simple_mult__DOT__u_cmul__0(Vtb_radix2_top_SimpleMult__P18_F0* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtb_radix2_top_SimpleMult__P18_F0___stl_sequent__TOP__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__simple_mult__DOT__u_cmul__0\n"); );
    // Body
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w 
        = ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_do_sub)
            ? (0xffffffU & (~ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_pp))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w 
        = ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_do_sub)
            ? (0xffffffU & (~ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_pp))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w 
        = ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_do_sub)
            ? (0xffffffU & (~ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_pp))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__pp_mod_w 
        = ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__final_do_sub)
            ? (0xffffffU & (~ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__final_pp))
            : 0U);
}

VL_ATTR_COLD void Vtb_radix2_top_SimpleMult__P18_F0___ctor_var_reset(Vtb_radix2_top_SimpleMult__P18_F0* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtb_radix2_top_SimpleMult__P18_F0___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->a_re = VL_RAND_RESET_I(16);
    vlSelf->a_im = VL_RAND_RESET_I(16);
    vlSelf->w0re = VL_RAND_RESET_I(8);
    vlSelf->w0im = VL_RAND_RESET_I(8);
    vlSelf->out_a_re = VL_RAND_RESET_I(25);
    vlSelf->out_a_im = VL_RAND_RESET_I(25);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__rr_a = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__ii_a = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__ri_a = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__ir_a = VL_RAND_RESET_I(24);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_sum = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_carry = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_pp = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_do_sub = VL_RAND_RESET_I(1);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_sum_r = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_carry_r = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_cin_r = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_sum = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_carry = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_pp = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_do_sub = VL_RAND_RESET_I(1);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_sum_r = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_carry_r = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_cin_r = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_sum = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_carry = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_pp = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_do_sub = VL_RAND_RESET_I(1);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_sum_r = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_carry_r = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_cin_r = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__a_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__b_pipe[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__sum_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__carry_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__final_sum = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__final_carry = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__final_pp = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__final_do_sub = VL_RAND_RESET_I(1);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__pp_mod_w = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__csa_sum_r = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__csa_carry_r = VL_RAND_RESET_I(24);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__csa_cin_r = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__cpa_a_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__cpa_b_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__cpa_result_pipe[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__cpa_carry_pipe[__Vi0] = VL_RAND_RESET_I(1);
    }
}
