// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_radix2_top.h for the primary calling header

#ifndef VERILATED_VTB_RADIX2_TOP_CHEAPMULT__P18_F0_H_
#define VERILATED_VTB_RADIX2_TOP_CHEAPMULT__P18_F0_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_radix2_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_radix2_top_CheapMult__P18_F0 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(w0re,7,0);
        VL_IN8(w0im,7,0);
        CData/*7:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__w0re_d;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_do_sub;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_cin_r;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_do_sub;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_cin_r;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_do_sub;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_cin_r;
        VL_IN16(a_re,15,0);
        VL_IN16(a_im,15,0);
        SData/*8:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_w0_in;
        SData/*8:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__diff_w0_in;
        SData/*15:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__a_re_d;
        SData/*15:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__a_im_d;
        VL_OUT(out_a_re,24,0);
        VL_OUT(out_a_im,24,0);
        IData/*16:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__sum_a_in;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__k2_a;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__k3_a;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__k1_a_reg;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_sum;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_carry;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_pp;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_sum_r;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_carry_r;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_sum;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_carry;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_pp;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_sum_r;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_carry_r;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_sum;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_carry;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_pp;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_sum_r;
        IData/*24:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_carry_r;
        VlUnpacked<IData/*24:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe;
        VlUnpacked<CData/*7:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe;
        VlUnpacked<IData/*24:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe;
        VlUnpacked<IData/*24:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe;
        VlUnpacked<IData/*31:0*/, 4> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe;
        VlUnpacked<IData/*31:0*/, 4> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe;
        VlUnpacked<IData/*31:0*/, 4> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe;
        VlUnpacked<CData/*0:0*/, 4> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe;
        VlUnpacked<IData/*24:0*/, 9> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe;
        VlUnpacked<SData/*8:0*/, 9> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe;
        VlUnpacked<IData/*24:0*/, 9> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe;
        VlUnpacked<IData/*24:0*/, 9> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe;
        VlUnpacked<IData/*31:0*/, 4> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe;
        VlUnpacked<IData/*31:0*/, 4> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe;
        VlUnpacked<IData/*31:0*/, 4> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe;
        VlUnpacked<CData/*0:0*/, 4> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe;
        VlUnpacked<IData/*24:0*/, 9> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe;
        VlUnpacked<SData/*8:0*/, 9> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe;
        VlUnpacked<IData/*24:0*/, 9> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe;
        VlUnpacked<IData/*24:0*/, 9> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe;
        VlUnpacked<IData/*31:0*/, 4> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe;
        VlUnpacked<IData/*31:0*/, 4> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe;
        VlUnpacked<IData/*31:0*/, 4> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe;
    };
    struct {
        VlUnpacked<CData/*0:0*/, 4> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe;
    };

    // INTERNAL VARIABLES
    Vtb_radix2_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_radix2_top_CheapMult__P18_F0(Vtb_radix2_top__Syms* symsp, const char* v__name);
    ~Vtb_radix2_top_CheapMult__P18_F0();
    VL_UNCOPYABLE(Vtb_radix2_top_CheapMult__P18_F0);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
