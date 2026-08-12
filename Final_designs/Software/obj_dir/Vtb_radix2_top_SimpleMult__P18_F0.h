// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_radix2_top.h for the primary calling header

#ifndef VERILATED_VTB_RADIX2_TOP_SIMPLEMULT__P18_F0_H_
#define VERILATED_VTB_RADIX2_TOP_SIMPLEMULT__P18_F0_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_radix2_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_radix2_top_SimpleMult__P18_F0 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(w0re,7,0);
        VL_IN8(w0im,7,0);
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_do_sub;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_cin_r;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_do_sub;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_cin_r;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_do_sub;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_cin_r;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__final_do_sub;
        CData/*0:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__csa_cin_r;
        VL_IN16(a_re,15,0);
        VL_IN16(a_im,15,0);
        VL_OUT(out_a_re,24,0);
        VL_OUT(out_a_im,24,0);
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__rr_a;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__ii_a;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__ri_a;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__ir_a;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_sum;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_carry;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__final_pp;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__pp_mod_w;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_sum_r;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__csa_carry_r;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_sum;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_carry;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__final_pp;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__pp_mod_w;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_sum_r;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__csa_carry_r;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_sum;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_carry;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__final_pp;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__pp_mod_w;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_sum_r;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__csa_carry_r;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__final_sum;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__final_carry;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__final_pp;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__pp_mod_w;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__csa_sum_r;
        IData/*23:0*/ __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__csa_carry_r;
        VlUnpacked<IData/*23:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__a_pipe;
        VlUnpacked<CData/*7:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__b_pipe;
        VlUnpacked<IData/*23:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__sum_pipe;
        VlUnpacked<IData/*23:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__carry_pipe;
        VlUnpacked<IData/*23:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_a_pipe;
        VlUnpacked<IData/*23:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_b_pipe;
        VlUnpacked<IData/*23:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_result_pipe;
        VlUnpacked<CData/*0:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_1__DOT__cpa_carry_pipe;
        VlUnpacked<IData/*23:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__a_pipe;
        VlUnpacked<CData/*7:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__b_pipe;
        VlUnpacked<IData/*23:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__sum_pipe;
        VlUnpacked<IData/*23:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__carry_pipe;
        VlUnpacked<IData/*23:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_a_pipe;
        VlUnpacked<IData/*23:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_b_pipe;
        VlUnpacked<IData/*23:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_result_pipe;
        VlUnpacked<CData/*0:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_2__DOT__cpa_carry_pipe;
        VlUnpacked<IData/*23:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__a_pipe;
        VlUnpacked<CData/*7:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__b_pipe;
        VlUnpacked<IData/*23:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__sum_pipe;
        VlUnpacked<IData/*23:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__carry_pipe;
        VlUnpacked<IData/*23:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_a_pipe;
    };
    struct {
        VlUnpacked<IData/*23:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_b_pipe;
        VlUnpacked<IData/*23:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_result_pipe;
        VlUnpacked<CData/*0:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_3__DOT__cpa_carry_pipe;
        VlUnpacked<IData/*23:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__a_pipe;
        VlUnpacked<CData/*7:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__b_pipe;
        VlUnpacked<IData/*23:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__sum_pipe;
        VlUnpacked<IData/*23:0*/, 8> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__carry_pipe;
        VlUnpacked<IData/*23:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__cpa_a_pipe;
        VlUnpacked<IData/*23:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__cpa_b_pipe;
        VlUnpacked<IData/*23:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__cpa_result_pipe;
        VlUnpacked<CData/*0:0*/, 3> __PVT__slow_dsp__DOT__carry_save_mult__DOT__u_carry_mult_4__DOT__cpa_carry_pipe;
    };

    // INTERNAL VARIABLES
    Vtb_radix2_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_radix2_top_SimpleMult__P18_F0(Vtb_radix2_top__Syms* symsp, const char* v__name);
    ~Vtb_radix2_top_SimpleMult__P18_F0();
    VL_UNCOPYABLE(Vtb_radix2_top_SimpleMult__P18_F0);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
