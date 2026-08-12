// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_radix2_top.h for the primary calling header

#ifndef VERILATED_VTB_RADIX2_TOP_CHEAPMULT__W18_P24_F0_H_
#define VERILATED_VTB_RADIX2_TOP_CHEAPMULT__W18_P24_F0_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_radix2_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_radix2_top_CheapMult__W18_P24_F0 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_do_sub;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_cin_r;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_do_sub;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_cin_r;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_do_sub;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_cin_r;
        VL_IN16(w0re,11,0);
        VL_IN16(w0im,11,0);
        SData/*12:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_w0_in;
        SData/*12:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__diff_w0_in;
        SData/*11:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__w0re_d;
        VL_IN(a_re,23,0);
        VL_IN(a_im,23,0);
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_a_in;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__a_re_d;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__a_im_d;
        VL_OUT64(out_a_re,36,0);
        VL_OUT64(out_a_im,36,0);
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__k2_a;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__k3_a;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a_reg;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_sum;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_carry;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_pp;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_sum_r;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_carry_r;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_sum;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_carry;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_pp;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_sum_r;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_carry_r;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_sum;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_carry;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_pp;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_sum_r;
        QData/*36:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_carry_r;
        VlUnpacked<QData/*36:0*/, 12> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe;
        VlUnpacked<SData/*11:0*/, 12> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe;
        VlUnpacked<QData/*36:0*/, 12> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe;
        VlUnpacked<QData/*36:0*/, 12> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe;
        VlUnpacked<QData/*39:0*/, 5> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe;
        VlUnpacked<QData/*39:0*/, 5> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe;
        VlUnpacked<QData/*39:0*/, 5> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe;
        VlUnpacked<CData/*0:0*/, 5> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe;
        VlUnpacked<QData/*36:0*/, 13> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe;
        VlUnpacked<SData/*12:0*/, 13> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe;
        VlUnpacked<QData/*36:0*/, 13> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe;
        VlUnpacked<QData/*36:0*/, 13> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe;
        VlUnpacked<QData/*39:0*/, 5> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe;
        VlUnpacked<QData/*39:0*/, 5> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe;
        VlUnpacked<QData/*39:0*/, 5> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe;
        VlUnpacked<CData/*0:0*/, 5> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe;
        VlUnpacked<QData/*36:0*/, 13> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe;
        VlUnpacked<SData/*12:0*/, 13> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe;
        VlUnpacked<QData/*36:0*/, 13> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe;
        VlUnpacked<QData/*36:0*/, 13> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe;
        VlUnpacked<QData/*39:0*/, 5> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe;
        VlUnpacked<QData/*39:0*/, 5> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe;
        VlUnpacked<QData/*39:0*/, 5> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe;
    };
    struct {
        VlUnpacked<CData/*0:0*/, 5> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe;
    };

    // INTERNAL VARIABLES
    Vtb_radix2_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_radix2_top_CheapMult__W18_P24_F0(Vtb_radix2_top__Syms* symsp, const char* v__name);
    ~Vtb_radix2_top_CheapMult__W18_P24_F0();
    VL_UNCOPYABLE(Vtb_radix2_top_CheapMult__W18_P24_F0);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
