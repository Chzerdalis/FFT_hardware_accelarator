// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_radix2_top.h for the primary calling header

#include "Vtb_radix2_top__pch.h"
#include "Vtb_radix2_top_CheapMult__P18_F0.h"
#include "Vtb_radix2_top__Syms.h"

VL_INLINE_OPT void Vtb_radix2_top_CheapMult__P18_F0___nba_sequent__TOP__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__0(Vtb_radix2_top_CheapMult__P18_F0* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtb_radix2_top_CheapMult__P18_F0___nba_sequent__TOP__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__0\n"); );
    // Init
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry = 0;
    SData/*8:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry = 0;
    SData/*8:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp = 0;
    IData/*24:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 = 0;
    SData/*8:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 = 0;
    IData/*24:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 = 0;
    IData/*24:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry = 0;
    SData/*8:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp = 0;
    IData/*24:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 = 0;
    SData/*8:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 = 0;
    IData/*24:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 = 0;
    IData/*24:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v0 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v0 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v0 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v1 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v2 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v3 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v4 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v5 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v6 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v6 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v0 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v0 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v0 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v2 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v4 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v3 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v3 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v6 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v0 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v0 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v0 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v1 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v2 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v3 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v4 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v5 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v6 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v7 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v7 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v7 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v7 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v0 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v0 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v0 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v2 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v4 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v3 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v3 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v6 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v0 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v0 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v0 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v1 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v2 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v3 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v4 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v5 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v6 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v7 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v7 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v7 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v7 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v0 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v0 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v0 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v2 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v4 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v3 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v3 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v6 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v3 = 0;
    // Body
    vlSelf->out_a_re = (0x1ffffffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a_reg 
                                      - vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k3_a));
    vlSelf->out_a_im = (0x1ffffffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a_reg 
                                      + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k2_a));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a_reg 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp 
        = (0x1ffU & (((0xffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_sum_r) 
                      + (0xffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_carry_r)) 
                     + (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_cin_r)));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_sum_r;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_carry_r;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1 = 0U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v0 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp 
        = (0x1ffU & (((0xffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe
                                [0U] >> 8U)) + (0xffU 
                                                & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe
                                                   [0U] 
                                                   >> 8U))) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe
                     [0U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3 = 8U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v1 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp 
        = (0x1ffU & (((0xffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe
                                [1U] >> 0x10U)) + (0xffU 
                                                   & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe
                                                      [1U] 
                                                      >> 0x10U))) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe
                     [1U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v4 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5 = 0x10U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v2 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp 
        = (0x1ffU & (((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe
                       [2U] >> 0x18U) + (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe
                                         [2U] >> 0x18U)) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe
                     [2U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v6 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7 = 0x18U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v3 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp) 
                 >> 8U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k3_a 
        = (0x1ffffffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
           [3U]);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp 
        = (0x1ffU & (((0xffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_sum_r) 
                      + (0xffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_carry_r)) 
                     + (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_cin_r)));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_sum_r;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_carry_r;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1 = 0U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v0 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp 
        = (0x1ffU & (((0xffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe
                                [0U] >> 8U)) + (0xffU 
                                                & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe
                                                   [0U] 
                                                   >> 8U))) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe
                     [0U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3 = 8U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v1 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp 
        = (0x1ffU & (((0xffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe
                                [1U] >> 0x10U)) + (0xffU 
                                                   & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe
                                                      [1U] 
                                                      >> 0x10U))) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe
                     [1U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v4 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5 = 0x10U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v2 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp 
        = (0x1ffU & (((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe
                       [2U] >> 0x18U) + (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe
                                         [2U] >> 0x18U)) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe
                     [2U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v6 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7 = 0x18U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v3 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp) 
                 >> 8U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k2_a 
        = (0x1ffffffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
           [3U]);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[0U] = 0U;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[0U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
            [0U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[1U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
            [1U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[2U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
            [2U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[3U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
            [3U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[0U] = 0U;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[0U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
            [0U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[1U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
            [1U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[2U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
            [2U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[3U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
            [3U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7))));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp 
        = (0x1ffU & (((0xffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_sum_r) 
                      + (0xffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_carry_r)) 
                     + (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_cin_r)));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_sum_r;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_carry_r;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1 = 0U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v0 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp 
        = (0x1ffU & (((0xffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe
                                [0U] >> 8U)) + (0xffU 
                                                & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe
                                                   [0U] 
                                                   >> 8U))) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe
                     [0U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3 = 8U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v1 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp 
        = (0x1ffU & (((0xffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe
                                [1U] >> 0x10U)) + (0xffU 
                                                   & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe
                                                      [1U] 
                                                      >> 0x10U))) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe
                     [1U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v4 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5 = 0x10U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v2 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp 
        = (0x1ffU & (((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe
                       [2U] >> 0x18U) + (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe
                                         [2U] >> 0x18U)) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe
                     [2U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v6 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7 = 0x18U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v3 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp) 
                 >> 8U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a 
        = (0x1ffffffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
           [3U]);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_cin_r 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_do_sub;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_sum_r 
        = (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_sum 
           ^ (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_carry 
              ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_carry_r 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_sum 
                                                  & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_carry 
                                                     | vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_carry 
                                                    & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w)), 1U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_cin_r 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_do_sub;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_sum_r 
        = (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_sum 
           ^ (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_carry 
              ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_carry_r 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_sum 
                                                  & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_carry 
                                                     | vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_carry 
                                                    & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w)), 1U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[0U] = 0U;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[0U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
            [0U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[1U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
            [1U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[2U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
            [2U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[3U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
            [3U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_cin_r 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_do_sub;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_sum_r 
        = (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_sum 
           ^ (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_carry 
              ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_carry_r 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_sum 
                                                  & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_carry 
                                                     | vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_carry 
                                                    & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v0 
        = ((0x1ff0000U & ((- (IData)((1U & ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_im_d) 
                                            >> 0xfU)))) 
                          << 0x10U)) | (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_im_d));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_w0_in;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((1U & (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_w0_in))
            ? ((0x1ff0000U & ((- (IData)((1U & ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_im_d) 
                                                >> 0xfU)))) 
                              << 0x10U)) | (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_im_d))
            : 0U);
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v0 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((2U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [0U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [0U], 1U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [0U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [0U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [0U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [0U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [0U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [0U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((4U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [1U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [1U], 2U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [1U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [1U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [1U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [1U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [1U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [1U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((8U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [2U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [2U], 3U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [2U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [2U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [2U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [2U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [2U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [2U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [3U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [3U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((0x10U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [3U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [3U], 4U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [3U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [3U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [3U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [3U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [3U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [3U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [4U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [4U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((0x20U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [4U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [4U], 5U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [4U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [4U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [4U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [4U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [4U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [4U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [5U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [5U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((0x40U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [5U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [5U], 6U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [5U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [5U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [5U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [5U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [5U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [5U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [6U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [6U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((0x80U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [6U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [6U], 7U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [6U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [6U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [6U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [6U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [6U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [6U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((0x100U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [7U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [7U], 8U))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_sum 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
        [7U];
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_carry 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
        [7U];
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_pp 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_do_sub 
        = (1U & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
                 [7U] >> 8U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v0 
        = ((0x1ff0000U & ((- (IData)((1U & ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_re_d) 
                                            >> 0xfU)))) 
                          << 0x10U)) | (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_re_d));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__diff_w0_in;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((1U & (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__diff_w0_in))
            ? ((0x1ff0000U & ((- (IData)((1U & ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_re_d) 
                                                >> 0xfU)))) 
                              << 0x10U)) | (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_re_d))
            : 0U);
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v0 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((2U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [0U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [0U], 1U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [0U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [0U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [0U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [0U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [0U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [0U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((4U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [1U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [1U], 2U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [1U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [1U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [1U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [1U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [1U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [1U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((8U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [2U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [2U], 3U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [2U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [2U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [2U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [2U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [2U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [2U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [3U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [3U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((0x10U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [3U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [3U], 4U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [3U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [3U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [3U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [3U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [3U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [3U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [4U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [4U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((0x20U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [4U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [4U], 5U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [4U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [4U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [4U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [4U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [4U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [4U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [5U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [5U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((0x40U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [5U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [5U], 6U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [5U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [5U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [5U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [5U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [5U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [5U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [6U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [6U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((0x80U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [6U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [6U], 7U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [6U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [6U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [6U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [6U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [6U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [6U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((0x100U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [7U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [7U], 8U))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_sum 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
        [7U];
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_carry 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
        [7U];
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_pp 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_do_sub 
        = (1U & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
                 [7U] >> 8U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[0U] = 0U;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[0U] = 0U;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v0 
        = ((0x1fe0000U & ((- (IData)((1U & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_a_in 
                                            >> 0x10U)))) 
                          << 0x11U)) | vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_a_in);
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__w0re_d;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((1U & (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__w0re_d))
            ? ((0x1fe0000U & ((- (IData)((1U & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_a_in 
                                                >> 0x10U)))) 
                              << 0x11U)) | vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_a_in)
            : 0U);
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v0 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
        [0U];
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((2U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [0U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [0U], 1U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
            [0U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
            [0U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                   [0U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                   [0U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                     [0U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                    [0U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
        [1U];
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((4U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [1U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [1U], 2U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
            [1U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
            [1U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                   [1U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                   [1U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                     [1U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                    [1U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v2 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v2 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
        [2U];
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((8U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [2U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [2U], 3U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
            [2U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
            [2U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                   [2U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                   [2U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                     [2U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                    [2U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v3 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v3 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v4 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
        [3U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v4 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
        [3U];
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((0x10U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [3U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [3U], 4U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
            [3U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
            [3U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                   [3U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                   [3U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                     [3U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                    [3U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v4 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v4 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v5 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
        [4U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v5 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
        [4U];
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((0x20U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [4U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [4U], 5U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
            [4U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
            [4U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                   [4U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                   [4U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                     [4U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                    [4U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v5 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v5 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v6 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
        [5U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v6 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
        [5U];
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((0x40U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [5U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [5U], 6U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
            [5U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
            [5U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                   [5U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                   [5U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                     [5U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                    [5U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v6 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v6 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((0x80U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [6U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [6U], 7U))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_sum 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
        [6U];
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_carry 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
        [6U];
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_pp 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_do_sub 
        = (1U & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
                 [6U] >> 7U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w 
        = ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_do_sub)
            ? (0x1ffffffU & (~ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_pp))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_im_d 
        = vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_im;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wr)) 
                     + VL_EXTENDS_II(9,8, (IData)(vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wi))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w 
        = ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_do_sub)
            ? (0x1ffffffU & (~ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_pp))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_re_d 
        = vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_re;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__diff_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wi)) 
                     - VL_EXTENDS_II(9,8, (IData)(vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wr))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[0U] = 0U;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w 
        = ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_do_sub)
            ? (0x1ffffffU & (~ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_pp))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__w0re_d 
        = vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wr;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_a_in 
        = (0x1ffffU & (VL_EXTENDS_II(17,16, (IData)(vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_re)) 
                       + VL_EXTENDS_II(17,16, (IData)(vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_im))));
}

VL_INLINE_OPT void Vtb_radix2_top_CheapMult__P18_F0___nba_sequent__TOP__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__0(Vtb_radix2_top_CheapMult__P18_F0* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtb_radix2_top_CheapMult__P18_F0___nba_sequent__TOP__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__0\n"); );
    // Init
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry = 0;
    SData/*8:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry = 0;
    SData/*8:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp = 0;
    IData/*24:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 = 0;
    SData/*8:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 = 0;
    IData/*24:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 = 0;
    IData/*24:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum = 0;
    IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry = 0;
    SData/*8:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp = 0;
    IData/*24:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 = 0;
    SData/*8:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 = 0;
    IData/*24:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 = 0;
    IData/*24:0*/ slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v0 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v0 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v0 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v1 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v2 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v3 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v4 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v5 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v6 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v6 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v0 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v0 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v0 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v2 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v4 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v3 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v3 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v6 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v0 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v0 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v0 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v1 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v2 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v3 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v4 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v5 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v6 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v7 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v7 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v7 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v7 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v0 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v0 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v0 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v2 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v4 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v3 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v3 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v6 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v0 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v0 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v0 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v1 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v1 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v2 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v2 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v3 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v3 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v4 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v4 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v5 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v5 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v6 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v6 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v7 = 0;
    SData/*8:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v7 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v7 = 0;
    IData/*24:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v7 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v0 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v0 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v0;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v0 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v2 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v1;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v1 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v4;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v4 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v2;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v2 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v3 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v3 = 0;
    IData/*31:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v6;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v6 = 0;
    CData/*4:0*/ __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7;
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7 = 0;
    CData/*7:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7 = 0;
    CData/*0:0*/ __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v3;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v3 = 0;
    // Body
    vlSelf->out_a_re = (0x1ffffffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a_reg 
                                      - vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k3_a));
    vlSelf->out_a_im = (0x1ffffffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a_reg 
                                      + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k2_a));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a_reg 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp 
        = (0x1ffU & (((0xffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_sum_r) 
                      + (0xffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_carry_r)) 
                     + (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_cin_r)));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_sum_r;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_carry_r;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1 = 0U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v0 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp 
        = (0x1ffU & (((0xffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe
                                [0U] >> 8U)) + (0xffU 
                                                & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe
                                                   [0U] 
                                                   >> 8U))) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe
                     [0U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3 = 8U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v1 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp 
        = (0x1ffU & (((0xffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe
                                [1U] >> 0x10U)) + (0xffU 
                                                   & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe
                                                      [1U] 
                                                      >> 0x10U))) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe
                     [1U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v4 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5 = 0x10U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v2 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp 
        = (0x1ffU & (((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe
                       [2U] >> 0x18U) + (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe
                                         [2U] >> 0x18U)) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe
                     [2U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v6 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7 = 0x18U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v3 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__add_tmp) 
                 >> 8U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k3_a 
        = (0x1ffffffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
           [3U]);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp 
        = (0x1ffU & (((0xffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_sum_r) 
                      + (0xffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_carry_r)) 
                     + (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_cin_r)));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_sum_r;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_carry_r;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1 = 0U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v0 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp 
        = (0x1ffU & (((0xffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe
                                [0U] >> 8U)) + (0xffU 
                                                & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe
                                                   [0U] 
                                                   >> 8U))) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe
                     [0U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3 = 8U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v1 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp 
        = (0x1ffU & (((0xffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe
                                [1U] >> 0x10U)) + (0xffU 
                                                   & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe
                                                      [1U] 
                                                      >> 0x10U))) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe
                     [1U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v4 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5 = 0x10U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v2 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp 
        = (0x1ffU & (((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe
                       [2U] >> 0x18U) + (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe
                                         [2U] >> 0x18U)) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe
                     [2U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v6 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7 = 0x18U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v3 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__add_tmp) 
                 >> 8U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k2_a 
        = (0x1ffffffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
           [3U]);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[0U] = 0U;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[0U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
            [0U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v1))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[1U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
            [1U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v3))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[2U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
            [2U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v5))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe[3U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe
            [3U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe__v7))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[0U] = 0U;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[0U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
            [0U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v1))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[1U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
            [1U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v3))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[2U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
            [2U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v5))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe[3U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe
            [3U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe__v7))));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp 
        = (0x1ffU & (((0xffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_sum_r) 
                      + (0xffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_carry_r)) 
                     + (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_cin_r)));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_sum_r;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_carry_r;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1 = 0U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v0 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp 
        = (0x1ffU & (((0xffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe
                                [0U] >> 8U)) + (0xffU 
                                                & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe
                                                   [0U] 
                                                   >> 8U))) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe
                     [0U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3 = 8U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v1 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp 
        = (0x1ffU & (((0xffU & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe
                                [1U] >> 0x10U)) + (0xffU 
                                                   & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe
                                                      [1U] 
                                                      >> 0x10U))) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe
                     [1U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v4 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5 = 0x10U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v2 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp) 
                 >> 8U));
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp 
        = (0x1ffU & (((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe
                       [2U] >> 0x18U) + (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe
                                         [2U] >> 0x18U)) 
                     + vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe
                     [2U]));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v6 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7 
        = (0xffU & (IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp));
    __Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7 = 0x18U;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v3 
        = (1U & ((IData)(__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__add_tmp) 
                 >> 8U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a 
        = (0x1ffffffU & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
           [3U]);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_cin_r 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_do_sub;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_sum_r 
        = (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_sum 
           ^ (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_carry 
              ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_carry_r 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_sum 
                                                  & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_carry 
                                                     | vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_carry 
                                                    & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w)), 1U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_cin_r 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_do_sub;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_sum_r 
        = (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_sum 
           ^ (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_carry 
              ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_carry_r 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_sum 
                                                  & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_carry 
                                                     | vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_carry 
                                                    & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w)), 1U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[0U] = 0U;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[0U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
            [0U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v1))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[1U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
            [1U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v3))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[2U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
            [2U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v5))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe[3U] 
        = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7))) 
            & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe
            [3U]) | (0xffffffffULL & ((IData)(__Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7) 
                                      << (IData)(__Vdlyvlsb__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe__v7))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_cin_r 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_do_sub;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_sum_r 
        = (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_sum 
           ^ (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_carry 
              ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_carry_r 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_sum 
                                                  & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_carry 
                                                     | vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_carry 
                                                    & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v0 
        = ((0x1ff0000U & ((- (IData)((1U & ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_im_d) 
                                            >> 0xfU)))) 
                          << 0x10U)) | (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_im_d));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_w0_in;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((1U & (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_w0_in))
            ? ((0x1ff0000U & ((- (IData)((1U & ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_im_d) 
                                                >> 0xfU)))) 
                              << 0x10U)) | (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_im_d))
            : 0U);
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v0 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((2U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [0U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [0U], 1U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [0U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [0U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [0U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [0U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [0U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [0U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((4U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [1U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [1U], 2U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [1U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [1U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [1U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [1U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [1U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [1U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((8U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [2U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [2U], 3U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [2U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [2U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [2U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [2U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [2U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [2U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [3U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [3U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((0x10U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [3U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [3U], 4U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [3U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [3U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [3U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [3U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [3U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [3U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [4U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [4U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((0x20U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [4U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [4U], 5U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [4U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [4U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [4U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [4U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [4U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [4U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [5U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [5U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((0x40U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [5U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [5U], 6U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [5U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [5U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [5U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [5U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [5U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [5U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
        [6U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
        [6U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((0x80U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [6U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [6U], 7U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
            [6U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
            [6U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                   [6U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                   [6U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
                                                     [6U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
                                                    [6U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT____Vlvbound_h893735b6__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp 
        = ((0x100U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
            [7U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe
                                                [7U], 8U))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_sum 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe
        [7U];
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_carry 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe
        [7U];
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_pp 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__comb_pp;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_do_sub 
        = (1U & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe
                 [7U] >> 8U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v0 
        = ((0x1ff0000U & ((- (IData)((1U & ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_re_d) 
                                            >> 0xfU)))) 
                          << 0x10U)) | (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_re_d));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__diff_w0_in;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((1U & (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__diff_w0_in))
            ? ((0x1ff0000U & ((- (IData)((1U & ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_re_d) 
                                                >> 0xfU)))) 
                              << 0x10U)) | (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_re_d))
            : 0U);
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v0 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((2U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [0U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [0U], 1U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [0U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [0U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [0U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [0U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [0U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [0U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v1 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((4U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [1U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [1U], 2U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [1U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [1U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [1U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [1U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [1U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [1U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v2 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((8U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [2U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [2U], 3U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [2U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [2U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [2U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [2U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [2U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [2U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v3 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [3U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [3U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((0x10U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [3U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [3U], 4U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [3U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [3U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [3U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [3U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [3U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [3U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v4 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [4U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [4U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((0x20U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [4U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [4U], 5U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [4U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [4U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [4U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [4U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [4U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [4U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v5 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [5U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [5U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((0x40U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [5U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [5U], 6U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [5U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [5U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [5U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [5U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [5U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [5U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v6 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
        [6U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_ha141e9fe__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
        [6U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h4ce2f4d7__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((0x80U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [6U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [6U], 7U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
            [6U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
            [6U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                   [6U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                   [6U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
                                                     [6U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
                                                    [6U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp)), 1U));
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h8e73ef88__1;
    slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v7 
        = slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT____Vlvbound_h893735b6__1;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp 
        = ((0x100U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
            [7U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe
                                                [7U], 8U))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_sum 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe
        [7U];
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_carry 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe
        [7U];
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_pp 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__comb_pp;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_do_sub 
        = (1U & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe
                 [7U] >> 8U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[0U] = 0U;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[0U] = 0U;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe__v7;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe[7U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe__v7;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v0 
        = ((0x1fe0000U & ((- (IData)((1U & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_a_in 
                                            >> 0x10U)))) 
                          << 0x11U)) | vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_a_in);
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v0 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__w0re_d;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((1U & (IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__w0re_d))
            ? ((0x1fe0000U & ((- (IData)((1U & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_a_in 
                                                >> 0x10U)))) 
                              << 0x11U)) | vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_a_in)
            : 0U);
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v0 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
        [0U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v1 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
        [0U];
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((2U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [0U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [0U], 1U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
            [0U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
            [0U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                   [0U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                   [0U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                     [0U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                    [0U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v1 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
        [1U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v2 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
        [1U];
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((4U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [1U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [1U], 2U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
            [1U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
            [1U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                   [1U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                   [1U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                     [1U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                    [1U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v2 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v2 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
        [2U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v3 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
        [2U];
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((8U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [2U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [2U], 3U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
            [2U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
            [2U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                   [2U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                   [2U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                     [2U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                    [2U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v3 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v3 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v4 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
        [3U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v4 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
        [3U];
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((0x10U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [3U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [3U], 4U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
            [3U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
            [3U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                   [3U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                   [3U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                     [3U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                    [3U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v4 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v4 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v5 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
        [4U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v5 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
        [4U];
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((0x20U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [4U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [4U], 5U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
            [4U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
            [4U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                   [4U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                   [4U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                     [4U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                    [4U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v5 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v5 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v6 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
        [5U];
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v6 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
        [5U];
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((0x40U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [5U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [5U], 6U))
            : 0U);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum 
        = ((vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
            [5U] ^ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
            [5U]) ^ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp);
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry 
        = (0x1ffffffU & VL_SHIFTL_III(25,25,32, (((
                                                   vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                   [5U] 
                                                   & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                   [5U]) 
                                                  | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
                                                     [5U] 
                                                     & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)) 
                                                 | (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
                                                    [5U] 
                                                    & __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp)), 1U));
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v6 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_sum;
    __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v6 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_carry;
    __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp 
        = ((0x80U & vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
            [6U]) ? (0x1ffffffU & VL_SHIFTL_III(25,25,32, 
                                                vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe
                                                [6U], 7U))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_sum 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe
        [6U];
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_carry 
        = vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe
        [6U];
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_pp 
        = __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__comb_pp;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_do_sub 
        = (1U & (vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe
                 [6U] >> 7U));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w 
        = ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_do_sub)
            ? (0x1ffffffU & (~ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_pp))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_im_d 
        = vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_im;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wr)) 
                     + VL_EXTENDS_II(9,8, (IData)(vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wi))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w 
        = ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_do_sub)
            ? (0x1ffffffU & (~ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_pp))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__a_re_d 
        = vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_re;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__diff_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wi)) 
                     - VL_EXTENDS_II(9,8, (IData)(vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wr))));
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[0U] = 0U;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[0U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v0;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[1U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v1;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[2U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v2;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[3U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v3;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[4U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v4;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[5U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v5;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe[6U] 
        = __Vdlyvval__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe__v6;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w 
        = ((IData)(vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_do_sub)
            ? (0x1ffffffU & (~ vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_pp))
            : 0U);
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__w0re_d 
        = vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wr;
    vlSelf->__PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_a_in 
        = (0x1ffffU & (VL_EXTENDS_II(17,16, (IData)(vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_re)) 
                       + VL_EXTENDS_II(17,16, (IData)(vlSymsp->TOP.tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_im))));
}
