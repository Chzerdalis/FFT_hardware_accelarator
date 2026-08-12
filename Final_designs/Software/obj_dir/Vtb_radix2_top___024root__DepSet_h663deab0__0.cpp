// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_radix2_top.h for the primary calling header

#include "Vtb_radix2_top__pch.h"
#include "Vtb_radix2_top___024root.h"

VL_ATTR_COLD void Vtb_radix2_top___024root___eval_initial__TOP(Vtb_radix2_top___024root* vlSelf);
VlCoroutine Vtb_radix2_top___024root___eval_initial__TOP__Vtiming__0(Vtb_radix2_top___024root* vlSelf);
VlCoroutine Vtb_radix2_top___024root___eval_initial__TOP__Vtiming__1(Vtb_radix2_top___024root* vlSelf);

void Vtb_radix2_top___024root___eval_initial(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_initial\n"); );
    // Body
    Vtb_radix2_top___024root___eval_initial__TOP(vlSelf);
    Vtb_radix2_top___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_radix2_top___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_radix2_top__DOT__clock__0 
        = vlSelf->tb_radix2_top__DOT__clock;
    vlSelf->__Vtrigprevexpr___TOP__tb_radix2_top__DOT__reset__0 
        = vlSelf->tb_radix2_top__DOT__reset;
}

VL_INLINE_OPT VlCoroutine Vtb_radix2_top___024root___eval_initial__TOP__Vtiming__0(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->tb_radix2_top__DOT__clock = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(5ULL, nullptr, 
                                           "../Radix-2/tb_top_radix_2.v", 
                                           61);
        vlSelf->tb_radix2_top__DOT__clock = (1U & (~ (IData)(vlSelf->tb_radix2_top__DOT__clock)));
    }
}

VL_INLINE_OPT VlCoroutine Vtb_radix2_top___024root___eval_initial__TOP__Vtiming__1(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Init
    IData/*31:0*/ tb_radix2_top__DOT__i;
    tb_radix2_top__DOT__i = 0;
    VlWide<6>/*191:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e747874U;
    __Vtemp_1[1U] = 0x74707574U;
    __Vtemp_1[2U] = 0x745f6f75U;
    __Vtemp_1[3U] = 0x612f6666U;
    __Vtemp_1[4U] = 0x2f446174U;
    __Vtemp_1[5U] = 0x2e2eU;
    vlSelf->tb_radix2_top__DOT__out_file_id = VL_FOPEN_NN(
                                                          VL_CVT_PACK_STR_NW(6, __Vtemp_1)
                                                          , 
                                                          std::string{"w"});
    ;
    if (VL_UNLIKELY((0U == vlSelf->tb_radix2_top__DOT__out_file_id))) {
        VL_WRITEF("ERROR: Could not create fft_output.txt.\n");
        VL_FINISH_MT("../Radix-2/tb_top_radix_2.v", 110, "");
    }
    vlSelf->tb_radix2_top__DOT__input_en = 0U;
    vlSelf->tb_radix2_top__DOT__input_real_0 = 0U;
    vlSelf->tb_radix2_top__DOT__input_imag_0 = 0U;
    vlSelf->tb_radix2_top__DOT__input_real_1 = 0U;
    vlSelf->tb_radix2_top__DOT__input_imag_1 = 0U;
    co_await vlSelf->__VdlySched.delay(5ULL, nullptr, 
                                       "../Radix-2/tb_top_radix_2.v", 
                                       117);
    vlSelf->tb_radix2_top__DOT__reset = 1U;
    co_await vlSelf->__VdlySched.delay(0xaULL, nullptr, 
                                       "../Radix-2/tb_top_radix_2.v", 
                                       121);
    co_await vlSelf->__VtrigSched_h121e40a7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_radix2_top.clock)", 
                                                       "../Radix-2/tb_top_radix_2.v", 
                                                       122);
    vlSelf->tb_radix2_top__DOT__reset = 0U;
    co_await vlSelf->__VdlySched.delay(0x64ULL, nullptr, 
                                       "../Radix-2/tb_top_radix_2.v", 
                                       124);
    vlSelf->tb_radix2_top__DOT__input_en = 1U;
    tb_radix2_top__DOT__i = 0U;
    while (VL_LTS_III(32, tb_radix2_top__DOT__i, vlSelf->tb_radix2_top__DOT__total_samples_read)) {
        if ((0x4e7U >= (0x7ffU & tb_radix2_top__DOT__i))) {
            vlSelf->tb_radix2_top__DOT__input_real_0 
                = vlSelf->tb_radix2_top__DOT__file_real_data
                [(0x7ffU & tb_radix2_top__DOT__i)];
            vlSelf->tb_radix2_top__DOT__input_imag_0 
                = vlSelf->tb_radix2_top__DOT__file_imag_data
                [(0x7ffU & tb_radix2_top__DOT__i)];
        } else {
            vlSelf->tb_radix2_top__DOT__input_real_0 = 0U;
            vlSelf->tb_radix2_top__DOT__input_imag_0 = 0U;
        }
        if ((0x4e7U >= (0x7ffU & ((IData)(1U) + tb_radix2_top__DOT__i)))) {
            vlSelf->tb_radix2_top__DOT__input_real_1 
                = vlSelf->tb_radix2_top__DOT__file_real_data
                [(0x7ffU & ((IData)(1U) + tb_radix2_top__DOT__i))];
            vlSelf->tb_radix2_top__DOT__input_imag_1 
                = vlSelf->tb_radix2_top__DOT__file_imag_data
                [(0x7ffU & ((IData)(1U) + tb_radix2_top__DOT__i))];
        } else {
            vlSelf->tb_radix2_top__DOT__input_real_1 = 0U;
            vlSelf->tb_radix2_top__DOT__input_imag_1 = 0U;
        }
        co_await vlSelf->__VdlySched.delay(0xaULL, 
                                           nullptr, 
                                           "../Radix-2/tb_top_radix_2.v", 
                                           136);
        tb_radix2_top__DOT__i = ((IData)(2U) + tb_radix2_top__DOT__i);
    }
    vlSelf->tb_radix2_top__DOT__input_en = 0U;
    VL_WRITEF("Finished streaming data to FFT. Waiting for outputs to flush...\n");
    co_await vlSelf->__VdlySched.delay(0x3110ULL, nullptr, 
                                       "../Radix-2/tb_top_radix_2.v", 
                                       143);
    VL_FCLOSE_I(vlSelf->tb_radix2_top__DOT__out_file_id); VL_WRITEF("Simulation complete. Outputs saved to fft_output.txt.\n");
    VL_FINISH_MT("../Radix-2/tb_top_radix_2.v", 147, "");
}

void Vtb_radix2_top___024root___eval_act(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_radix2_top___024root___nba_sequent__TOP__0(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__0__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__0__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__0__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__0__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__1__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__1__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__1__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__1__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__2__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__2__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__2__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__2__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__3__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__3__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__3__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__3__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__4__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__4__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__4__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__4__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__5__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__5__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__5__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__5__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__6__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__6__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__6__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__6__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__7__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__7__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__7__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__7__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__8__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__8__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__8__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__8__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__9__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__9__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__9__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__9__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__10__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__10__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__10__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__10__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__11__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__11__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__11__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__11__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__12__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__12__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__12__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__12__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__13__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__13__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__13__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__13__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__14__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__14__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__14__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__14__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__15__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__15__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__15__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__15__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__16__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__16__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__16__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__16__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__17__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__17__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__17__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__17__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__18__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__18__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__18__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__18__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__19__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__19__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__19__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__19__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__20__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__20__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__20__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__20__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__21__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__21__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__21__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__21__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__22__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__22__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__22__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__22__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__23__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__23__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__23__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__23__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__24__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__24__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__24__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__24__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__25__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__25__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__25__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__25__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__26__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__26__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__26__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__26__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__27__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__27__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__27__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__27__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__28__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__28__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__28__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__28__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__29__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__29__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__29__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__29__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__30__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__30__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__30__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__30__x = 0;
    SData/*15:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__31__Vfuncout;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__31__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__31__x;
    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__31__x = 0;
    IData/*31:0*/ __Vdly__tb_radix2_top__DOT__output_count;
    __Vdly__tb_radix2_top__DOT__output_count = 0;
    IData/*31:0*/ __Vdly__tb_radix2_top__DOT__write_offset;
    __Vdly__tb_radix2_top__DOT__write_offset = 0;
    SData/*8:0*/ __Vdlyvdim0__tb_radix2_top__DOT__output_real__v0;
    __Vdlyvdim0__tb_radix2_top__DOT__output_real__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__output_real__v0;
    __Vdlyvval__tb_radix2_top__DOT__output_real__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__output_real__v0;
    __Vdlyvset__tb_radix2_top__DOT__output_real__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__tb_radix2_top__DOT__output_imag__v0;
    __Vdlyvdim0__tb_radix2_top__DOT__output_imag__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__output_imag__v0;
    __Vdlyvval__tb_radix2_top__DOT__output_imag__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__tb_radix2_top__DOT__output_real__v1;
    __Vdlyvdim0__tb_radix2_top__DOT__output_real__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__output_real__v1;
    __Vdlyvval__tb_radix2_top__DOT__output_real__v1 = 0;
    SData/*8:0*/ __Vdlyvdim0__tb_radix2_top__DOT__output_imag__v1;
    __Vdlyvdim0__tb_radix2_top__DOT__output_imag__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__output_imag__v1;
    __Vdlyvval__tb_radix2_top__DOT__output_imag__v1 = 0;
    CData/*0:0*/ __Vdly__tb_radix2_top__DOT__counting_latency;
    __Vdly__tb_radix2_top__DOT__counting_latency = 0;
    IData/*31:0*/ __Vdly__tb_radix2_top__DOT__t_latency;
    __Vdly__tb_radix2_top__DOT__t_latency = 0;
    CData/*0:0*/ __Vdly__tb_radix2_top__DOT__counting_active;
    __Vdly__tb_radix2_top__DOT__counting_active = 0;
    IData/*31:0*/ __Vdly__tb_radix2_top__DOT__t_active;
    __Vdly__tb_radix2_top__DOT__t_active = 0;
    CData/*0:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0;
    CData/*0:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter = 0;
    CData/*6:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 = 0;
    CData/*1:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0;
    CData/*1:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter = 0;
    CData/*6:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3 = 0;
    CData/*2:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0;
    CData/*2:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter = 0;
    CData/*6:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7 = 0;
    CData/*3:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0;
    CData/*3:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter = 0;
    CData/*6:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15 = 0;
    CData/*4:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0;
    CData/*4:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter = 0;
    CData/*6:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v15 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v15 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v16;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v16 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v16;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v16 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v17;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v17 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v17;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v17 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v18;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v18 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v18;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v18 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v19;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v19 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v19;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v19 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v20;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v20 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v20;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v20 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v21;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v21 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v21;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v21 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v22;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v22 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v22;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v22 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v23;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v23 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v23;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v23 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v24;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v24 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v24;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v24 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v25;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v25 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v25;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v25 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v26;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v26 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v26;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v26 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v27;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v27 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v27;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v27 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v28;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v28 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v28;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v28 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v29;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v29 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v29;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v29 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v30;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v30 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v30;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v30 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v31;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v31 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v31;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v31 = 0;
    CData/*5:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0;
    CData/*5:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter = 0;
    CData/*6:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v15 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v15 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v16;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v16 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v16;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v16 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v17;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v17 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v17;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v17 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v18;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v18 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v18;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v18 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v19;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v19 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v19;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v19 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v20;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v20 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v20;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v20 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v21;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v21 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v21;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v21 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v22;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v22 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v22;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v22 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v23;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v23 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v23;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v23 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v24;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v24 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v24;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v24 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v25;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v25 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v25;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v25 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v26;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v26 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v26;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v26 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v27;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v27 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v27;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v27 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v28;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v28 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v28;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v28 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v29;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v29 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v29;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v29 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v30;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v30 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v30;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v30 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v31;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v31 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v31;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v31 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v16;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v16 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v16;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v16 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v17;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v17 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v17;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v17 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v18;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v18 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v18;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v18 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v19;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v19 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v19;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v19 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v20;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v20 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v20;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v20 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v21;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v21 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v21;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v21 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v22;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v22 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v22;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v22 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v23;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v23 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v23;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v23 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v24;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v24 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v24;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v24 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v25;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v25 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v25;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v25 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v26;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v26 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v26;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v26 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v27;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v27 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v27;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v27 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v28;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v28 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v28;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v28 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v29;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v29 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v29;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v29 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v30;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v30 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v30;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v30 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v31;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v31 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v31;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v31 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v32;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v32 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v32;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v32 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v33;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v33 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v33;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v33 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v34;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v34 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v34;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v34 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v35;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v35 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v35;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v35 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v36;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v36 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v36;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v36 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v37;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v37 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v37;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v37 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v38;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v38 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v38;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v38 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v39;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v39 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v39;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v39 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v40;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v40 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v40;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v40 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v41;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v41 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v41;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v41 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v42;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v42 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v42;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v42 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v43;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v43 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v43;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v43 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v44;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v44 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v44;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v44 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v45;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v45 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v45;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v45 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v46;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v46 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v46;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v46 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v47;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v47 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v47;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v47 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v48;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v48 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v48;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v48 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v49;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v49 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v49;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v49 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v50;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v50 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v50;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v50 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v51;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v51 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v51;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v51 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v52;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v52 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v52;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v52 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v53;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v53 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v53;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v53 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v54;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v54 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v54;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v54 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v55;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v55 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v55;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v55 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v56;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v56 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v56;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v56 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v57;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v57 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v57;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v57 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v58;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v58 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v58;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v58 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v59;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v59 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v59;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v59 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v60;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v60 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v60;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v60 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v61;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v61 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v61;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v61 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v62;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v62 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v62;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v62 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v63;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v63 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v63;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v63 = 0;
    CData/*6:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0;
    CData/*6:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter = 0;
    CData/*6:0*/ __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v15 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v15 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v16;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v16 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v16;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v16 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v17;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v17 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v17;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v17 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v18;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v18 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v18;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v18 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v19;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v19 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v19;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v19 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v20;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v20 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v20;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v20 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v21;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v21 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v21;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v21 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v22;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v22 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v22;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v22 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v23;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v23 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v23;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v23 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v24;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v24 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v24;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v24 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v25;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v25 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v25;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v25 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v26;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v26 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v26;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v26 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v27;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v27 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v27;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v27 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v28;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v28 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v28;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v28 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v29;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v29 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v29;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v29 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v30;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v30 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v30;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v30 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v31;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v31 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v31;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v31 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v32;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v32 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v32;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v32 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v33;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v33 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v33;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v33 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v34;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v34 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v34;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v34 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v35;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v35 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v35;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v35 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v36;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v36 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v36;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v36 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v37;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v37 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v37;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v37 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v38;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v38 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v38;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v38 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v39;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v39 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v39;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v39 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v40;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v40 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v40;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v40 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v41;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v41 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v41;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v41 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v42;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v42 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v42;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v42 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v43;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v43 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v43;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v43 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v44;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v44 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v44;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v44 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v45;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v45 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v45;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v45 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v46;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v46 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v46;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v46 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v47;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v47 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v47;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v47 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v48;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v48 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v48;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v48 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v49;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v49 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v49;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v49 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v50;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v50 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v50;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v50 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v51;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v51 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v51;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v51 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v52;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v52 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v52;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v52 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v53;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v53 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v53;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v53 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v54;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v54 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v54;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v54 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v55;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v55 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v55;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v55 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v56;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v56 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v56;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v56 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v57;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v57 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v57;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v57 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v58;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v58 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v58;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v58 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v59;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v59 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v59;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v59 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v60;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v60 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v60;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v60 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v61;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v61 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v61;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v61 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v62;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v62 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v62;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v62 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v63;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v63 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v63;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v63 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v16;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v16 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v16;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v16 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v17;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v17 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v17;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v17 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v18;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v18 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v18;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v18 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v19;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v19 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v19;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v19 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v20;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v20 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v20;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v20 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v21;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v21 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v21;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v21 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v22;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v22 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v22;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v22 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v23;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v23 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v23;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v23 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v24;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v24 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v24;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v24 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v25;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v25 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v25;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v25 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v26;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v26 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v26;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v26 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v27;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v27 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v27;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v27 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v28;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v28 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v28;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v28 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v29;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v29 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v29;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v29 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v30;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v30 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v30;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v30 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v31;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v31 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v31;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v31 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v32;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v32 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v32;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v32 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v33;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v33 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v33;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v33 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v34;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v34 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v34;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v34 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v35;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v35 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v35;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v35 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v36;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v36 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v36;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v36 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v37;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v37 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v37;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v37 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v38;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v38 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v38;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v38 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v39;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v39 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v39;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v39 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v40;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v40 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v40;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v40 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v41;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v41 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v41;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v41 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v42;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v42 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v42;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v42 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v43;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v43 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v43;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v43 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v44;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v44 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v44;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v44 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v45;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v45 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v45;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v45 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v46;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v46 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v46;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v46 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v47;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v47 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v47;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v47 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v48;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v48 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v48;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v48 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v49;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v49 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v49;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v49 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v50;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v50 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v50;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v50 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v51;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v51 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v51;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v51 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v52;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v52 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v52;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v52 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v53;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v53 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v53;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v53 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v54;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v54 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v54;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v54 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v55;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v55 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v55;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v55 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v56;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v56 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v56;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v56 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v57;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v57 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v57;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v57 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v58;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v58 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v58;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v58 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v59;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v59 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v59;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v59 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v60;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v60 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v60;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v60 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v61;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v61 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v61;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v61 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v62;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v62 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v62;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v62 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v63;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v63 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v63;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v63 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v64;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v64 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v64;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v64 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v65;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v65 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v65;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v65 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v66;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v66 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v66;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v66 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v67;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v67 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v67;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v67 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v68;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v68 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v68;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v68 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v69;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v69 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v69;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v69 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v70;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v70 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v70;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v70 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v71;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v71 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v71;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v71 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v72;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v72 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v72;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v72 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v73;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v73 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v73;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v73 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v74;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v74 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v74;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v74 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v75;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v75 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v75;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v75 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v76;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v76 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v76;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v76 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v77;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v77 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v77;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v77 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v78;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v78 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v78;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v78 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v79;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v79 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v79;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v79 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v80;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v80 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v80;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v80 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v81;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v81 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v81;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v81 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v82;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v82 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v82;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v82 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v83;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v83 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v83;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v83 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v84;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v84 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v84;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v84 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v85;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v85 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v85;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v85 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v86;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v86 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v86;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v86 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v87;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v87 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v87;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v87 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v88;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v88 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v88;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v88 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v89;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v89 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v89;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v89 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v90;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v90 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v90;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v90 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v91;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v91 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v91;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v91 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v92;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v92 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v92;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v92 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v93;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v93 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v93;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v93 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v94;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v94 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v94;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v94 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v95;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v95 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v95;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v95 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v96;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v96 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v96;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v96 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v97;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v97 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v97;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v97 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v98;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v98 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v98;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v98 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v99;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v99 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v99;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v99 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v100;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v100 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v100;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v100 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v101;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v101 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v101;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v101 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v102;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v102 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v102;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v102 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v103;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v103 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v103;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v103 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v104;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v104 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v104;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v104 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v105;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v105 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v105;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v105 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v106;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v106 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v106;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v106 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v107;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v107 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v107;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v107 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v108;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v108 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v108;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v108 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v109;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v109 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v109;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v109 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v110;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v110 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v110;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v110 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v111;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v111 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v111;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v111 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v112;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v112 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v112;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v112 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v113;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v113 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v113;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v113 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v114;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v114 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v114;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v114 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v115;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v115 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v115;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v115 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v116;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v116 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v116;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v116 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v117;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v117 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v117;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v117 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v118;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v118 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v118;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v118 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v119;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v119 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v119;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v119 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v120;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v120 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v120;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v120 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v121;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v121 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v121;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v121 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v122;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v122 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v122;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v122 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v123;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v123 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v123;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v123 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v124;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v124 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v124;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v124 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v125;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v125 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v125;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v125 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v126;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v126 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v126;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v126 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v127;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v127 = 0;
    SData/*15:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v127;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v127 = 0;
    // Body
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter;
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter;
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter;
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter;
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter;
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter;
    vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    __Vdly__tb_radix2_top__DOT__t_active = vlSelf->tb_radix2_top__DOT__t_active;
    __Vdly__tb_radix2_top__DOT__counting_active = vlSelf->tb_radix2_top__DOT__counting_active;
    __Vdly__tb_radix2_top__DOT__t_latency = vlSelf->tb_radix2_top__DOT__t_latency;
    __Vdly__tb_radix2_top__DOT__counting_latency = vlSelf->tb_radix2_top__DOT__counting_latency;
    __Vdly__tb_radix2_top__DOT__write_offset = vlSelf->tb_radix2_top__DOT__write_offset;
    __Vdly__tb_radix2_top__DOT__output_count = vlSelf->tb_radix2_top__DOT__output_count;
    __Vdlyvset__tb_radix2_top__DOT__output_real__v0 = 0U;
    if (VL_UNLIKELY(vlSelf->tb_radix2_top__DOT__frame_ready)) {
        vlSelf->tb_radix2_top__DOT__window_count = 
            ((IData)(1U) + vlSelf->tb_radix2_top__DOT__window_count);
        vlSelf->tb_radix2_top__DOT__k = 0U;
        while (VL_GTS_III(32, 0x100U, vlSelf->tb_radix2_top__DOT__k)) {
            VL_FWRITEF(vlSelf->tb_radix2_top__DOT__out_file_id,"%6d %6d\n",
                       16,vlSelf->tb_radix2_top__DOT__output_real
                       [(0x1ffU & (vlSelf->tb_radix2_top__DOT__print_offset 
                                   + vlSelf->tb_radix2_top__DOT__k))],
                       16,vlSelf->tb_radix2_top__DOT__output_imag
                       [(0x1ffU & (vlSelf->tb_radix2_top__DOT__print_offset 
                                   + vlSelf->tb_radix2_top__DOT__k))]);
            vlSelf->tb_radix2_top__DOT__k = ((IData)(1U) 
                                             + vlSelf->tb_radix2_top__DOT__k);
        }
    }
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [6U];
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xeU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xeU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xeU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xeU];
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_1;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xeU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xfU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v16 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x10U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v17 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x11U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v18 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x12U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v19 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x13U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v20 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x14U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v21 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x15U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v22 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x16U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v23 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x17U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v24 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x18U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v25 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x19U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v26 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v27 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v28 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v29 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v30 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xeU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xfU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v16 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x10U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v17 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x11U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v18 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x12U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v19 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x13U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v20 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x14U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v21 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x15U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v22 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x16U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v23 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x17U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v24 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x18U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v25 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x19U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v26 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v27 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v28 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v29 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v30 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xeU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v15 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xfU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v16 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x10U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v17 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x11U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v18 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x12U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v19 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x13U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v20 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x14U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v21 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x15U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v22 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x16U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v23 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x17U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v24 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x18U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v25 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x19U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v26 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x1aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v27 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x1bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v28 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x1cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v29 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x1dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v30 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x1eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xeU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v15 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xfU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v16 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x10U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v17 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x11U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v18 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x12U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v19 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x13U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v20 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x14U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v21 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x15U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v22 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x16U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v23 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x17U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v24 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x18U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v25 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x19U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v26 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x1aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v27 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x1bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v28 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x1cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v29 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x1dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v30 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x1eU];
    if (((IData)(vlSelf->tb_radix2_top__DOT__input_en_d) 
         & (~ (IData)(vlSelf->tb_radix2_top__DOT__input_en)))) {
        __Vdly__tb_radix2_top__DOT__counting_latency = 1U;
        __Vdly__tb_radix2_top__DOT__t_latency = 1U;
    } else if (((IData)(vlSelf->tb_radix2_top__DOT__counting_latency) 
                & (~ (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_en)))) {
        __Vdly__tb_radix2_top__DOT__t_latency = ((IData)(1U) 
                                                 + vlSelf->tb_radix2_top__DOT__t_latency);
    }
    if (vlSelf->tb_radix2_top__DOT__reset) {
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter = 0U;
        vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter = 0U;
        vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter = 0U;
        vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter = 0U;
        vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter = 0U;
        vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter = 0U;
        vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
        __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter = 0U;
        vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
    } else {
        if (vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_en) {
            if ((1U & ((~ (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter)) 
                       & (~ (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en))))) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter = 0x7fU;
            } else if (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = (1U & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter 
                    = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter) 
                                - (IData)(1U)));
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
            } else {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
            }
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (1U & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter)));
        } else if ((0U == (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter))) {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter = 0U;
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
        } else {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (1U & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                = (1U & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter 
                = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter) 
                            - (IData)(1U)));
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
        }
        if (vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_en) {
            if (((0x3fU == (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter)) 
                 & (~ (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en)))) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter = 0x7fU;
            } else if (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = (0x7fU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter 
                    = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter) 
                                - (IData)(1U)));
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
            } else {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
            }
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter)));
        } else if ((0U == (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter))) {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter = 0U;
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
        } else {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter 
                = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter) 
                            - (IData)(1U)));
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
        }
        if (vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_en) {
            if (((0x1fU == (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter)) 
                 & (~ (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en)))) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter = 0x7fU;
            } else if (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter 
                    = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter) 
                                - (IData)(1U)));
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
            } else {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
            }
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (0x3fU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter)));
        } else if ((0U == (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter))) {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter = 0U;
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
        } else {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (0x3fU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                = (0x3fU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter 
                = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter) 
                            - (IData)(1U)));
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
        }
        if (vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_en) {
            if (((0xfU == (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter)) 
                 & (~ (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en)))) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter = 0x7fU;
            } else if (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = (0x1fU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter 
                    = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter) 
                                - (IData)(1U)));
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
            } else {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
            }
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter)));
        } else if ((0U == (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter))) {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter = 0U;
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
        } else {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter 
                = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter) 
                            - (IData)(1U)));
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
        }
        if (vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_en) {
            if (((7U == (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter)) 
                 & (~ (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en)))) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter = 0x7fU;
            } else if (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter 
                    = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter) 
                                - (IData)(1U)));
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
            } else {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
            }
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter)));
        } else if ((0U == (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter))) {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter = 0U;
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
        } else {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter 
                = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter) 
                            - (IData)(1U)));
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
        }
        if (vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_en) {
            if (((3U == (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter)) 
                 & (~ (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en)))) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter = 0x7fU;
            } else if (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = (7U & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter 
                    = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter) 
                                - (IData)(1U)));
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
            } else {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
            }
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (7U & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter)));
        } else if ((0U == (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter))) {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter = 0U;
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
        } else {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (7U & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                = (7U & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter 
                = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter) 
                            - (IData)(1U)));
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
        }
        if (vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_en) {
            if (((1U == (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter)) 
                 & (~ (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en)))) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter = 0x7fU;
            } else if (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en) {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = (3U & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter 
                    = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter) 
                                - (IData)(1U)));
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
            } else {
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter;
                __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter 
                    = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter;
                vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
            }
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (3U & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter)));
        } else if ((0U == (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter))) {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter = 0U;
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter = 0U;
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 0U;
        } else {
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter 
                = (3U & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter 
                = (3U & ((IData)(1U) + (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter)));
            __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter 
                = (0x7fU & ((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter) 
                            - (IData)(1U)));
            vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en = 1U;
        }
    }
    if (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
            [1U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
            [1U];
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [0U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [0U];
    }
    if ((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter))) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
            [3U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
            [3U];
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [1U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [1U];
    }
    if ((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter))) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
            [7U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
            [7U];
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [3U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [3U];
    }
    if ((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter))) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
            [0xfU];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
            [0xfU];
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [7U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [7U];
    }
    if ((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter))) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
            [0x1fU];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
            [0x1fU];
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [0xfU];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [0xfU];
    }
    if (VL_UNLIKELY(((~ (IData)(vlSelf->tb_radix2_top__DOT__output_en_d)) 
                     & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_en)))) {
        VL_FWRITEF(vlSelf->tb_radix2_top__DOT__file_id,"%0d\n",
                   32,vlSelf->tb_radix2_top__DOT__t_latency);
        __Vdly__tb_radix2_top__DOT__counting_latency = 0U;
    }
    if (((~ (IData)(vlSelf->tb_radix2_top__DOT__input_en_d)) 
         & (IData)(vlSelf->tb_radix2_top__DOT__input_en))) {
        __Vdly__tb_radix2_top__DOT__counting_active = 1U;
        __Vdly__tb_radix2_top__DOT__t_active = 1U;
    } else if (vlSelf->tb_radix2_top__DOT__counting_active) {
        __Vdly__tb_radix2_top__DOT__t_active = ((IData)(1U) 
                                                + vlSelf->tb_radix2_top__DOT__t_active);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->tb_radix2_top__DOT__output_en_d) 
                     & (~ (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_en))))) {
        VL_FWRITEF(vlSelf->tb_radix2_top__DOT__file_id,"%0d\n",
                   32,vlSelf->tb_radix2_top__DOT__t_active);
        __Vdly__tb_radix2_top__DOT__counting_active = 0U;
    }
    if (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_1;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_1;
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_0;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_0;
    }
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xeU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xfU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v16 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x10U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v17 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x11U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v18 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x12U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v19 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x13U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v20 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x14U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v21 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x15U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v22 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x16U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v23 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x17U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v24 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x18U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v25 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x19U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v26 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v27 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v28 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v29 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v30 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v31 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v32 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x20U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v33 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x21U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v34 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x22U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v35 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x23U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v36 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x24U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v37 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x25U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v38 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x26U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v39 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x27U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v40 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x28U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v41 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x29U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v42 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x2aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v43 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x2bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v44 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x2cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v45 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x2dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v46 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x2eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v47 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x2fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v48 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x30U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v49 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x31U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v50 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x32U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v51 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x33U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v52 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x34U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v53 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x35U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v54 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x36U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v55 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x37U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v56 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x38U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v57 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x39U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v58 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x3aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v59 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x3bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v60 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x3cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v61 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x3dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v62 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x3eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xeU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xfU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v16 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x10U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v17 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x11U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v18 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x12U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v19 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x13U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v20 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x14U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v21 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x15U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v22 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x16U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v23 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x17U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v24 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x18U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v25 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x19U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v26 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v27 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v28 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v29 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v30 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v31 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v32 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x20U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v33 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x21U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v34 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x22U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v35 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x23U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v36 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x24U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v37 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x25U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v38 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x26U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v39 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x27U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v40 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x28U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v41 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x29U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v42 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x2aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v43 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x2bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v44 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x2cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v45 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x2dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v46 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x2eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v47 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x2fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v48 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x30U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v49 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x31U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v50 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x32U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v51 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x33U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v52 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x34U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v53 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x35U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v54 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x36U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v55 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x37U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v56 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x38U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v57 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x39U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v58 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x3aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v59 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x3bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v60 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x3cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v61 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x3dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v62 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x3eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xeU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v15 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0xfU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v16 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x10U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v17 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x11U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v18 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x12U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v19 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x13U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v20 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x14U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v21 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x15U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v22 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x16U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v23 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x17U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v24 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x18U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v25 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x19U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v26 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x1aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v27 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x1bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v28 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x1cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v29 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x1dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v30 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x1eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v31 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x1fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v32 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x20U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v33 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x21U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v34 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x22U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v35 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x23U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v36 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x24U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v37 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x25U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v38 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x26U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v39 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x27U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v40 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x28U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v41 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x29U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v42 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x2aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v43 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x2bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v44 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x2cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v45 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x2dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v46 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x2eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v47 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x2fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v48 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x30U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v49 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x31U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v50 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x32U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v51 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x33U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v52 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x34U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v53 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x35U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v54 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x36U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v55 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x37U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v56 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x38U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v57 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x39U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v58 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x3aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v59 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x3bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v60 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x3cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v61 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x3dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v62 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
        [0x3eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xeU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v15 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0xfU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v16 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x10U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v17 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x11U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v18 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x12U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v19 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x13U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v20 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x14U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v21 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x15U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v22 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x16U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v23 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x17U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v24 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x18U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v25 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x19U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v26 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x1aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v27 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x1bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v28 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x1cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v29 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x1dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v30 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x1eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v31 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x1fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v32 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x20U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v33 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x21U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v34 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x22U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v35 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x23U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v36 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x24U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v37 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x25U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v38 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x26U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v39 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x27U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v40 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x28U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v41 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x29U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v42 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x2aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v43 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x2bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v44 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x2cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v45 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x2dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v46 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x2eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v47 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x2fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v48 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x30U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v49 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x31U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v50 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x32U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v51 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x33U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v52 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x34U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v53 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x35U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v54 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x36U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v55 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x37U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v56 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x38U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v57 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x39U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v58 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x3aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v59 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x3bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v60 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x3cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v61 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x3dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v62 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
        [0x3eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_1;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2 
        = tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT____Vlvbound_h779ebe74__0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v31 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v31 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v63 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v63 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xeU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0xfU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v16 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x10U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v17 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x11U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v18 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x12U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v19 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x13U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v20 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x14U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v21 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x15U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v22 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x16U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v23 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x17U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v24 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x18U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v25 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x19U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v26 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v27 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v28 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v29 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v30 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v31 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x1fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v32 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x20U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v33 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x21U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v34 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x22U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v35 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x23U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v36 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x24U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v37 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x25U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v38 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x26U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v39 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x27U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v40 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x28U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v41 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x29U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v42 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x2aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v43 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x2bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v44 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x2cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v45 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x2dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v46 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x2eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v47 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x2fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v48 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x30U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v49 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x31U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v50 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x32U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v51 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x33U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v52 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x34U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v53 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x35U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v54 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x36U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v55 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x37U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v56 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x38U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v57 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x39U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v58 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x3aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v59 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x3bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v60 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x3cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v61 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x3dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v62 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x3eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v63 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x3fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v64 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x40U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v65 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x41U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v66 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x42U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v67 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x43U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v68 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x44U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v69 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x45U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v70 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x46U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v71 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x47U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v72 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x48U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v73 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x49U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v74 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x4aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v75 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x4bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v76 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x4cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v77 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x4dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v78 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x4eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v79 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x4fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v80 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x50U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v81 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x51U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v82 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x52U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v83 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x53U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v84 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x54U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v85 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x55U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v86 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x56U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v87 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x57U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v88 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x58U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v89 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x59U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v90 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x5aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v91 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x5bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v92 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x5cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v93 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x5dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v94 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x5eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v95 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x5fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v96 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x60U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v97 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x61U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v98 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x62U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v99 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x63U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v100 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x64U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v101 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x65U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v102 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x66U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v103 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x67U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v104 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x68U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v105 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x69U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v106 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x6aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v107 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x6bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v108 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x6cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v109 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x6dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v110 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x6eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v111 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x6fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v112 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x70U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v113 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x71U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v114 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x72U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v115 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x73U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v116 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x74U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v117 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x75U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v118 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x76U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v119 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x77U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v120 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x78U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v121 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x79U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v122 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x7aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v123 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x7bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v124 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x7cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v125 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x7dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v126 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
        [0x7eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [1U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [2U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [3U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [4U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [5U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [6U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [7U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [8U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [9U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xaU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xbU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xcU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xdU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xeU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0xfU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v16 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x10U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v17 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x11U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v18 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x12U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v19 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x13U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v20 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x14U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v21 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x15U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v22 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x16U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v23 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x17U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v24 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x18U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v25 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x19U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v26 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v27 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v28 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v29 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v30 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v31 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x1fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v32 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x20U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v33 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x21U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v34 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x22U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v35 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x23U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v36 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x24U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v37 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x25U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v38 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x26U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v39 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x27U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v40 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x28U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v41 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x29U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v42 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x2aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v43 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x2bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v44 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x2cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v45 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x2dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v46 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x2eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v47 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x2fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v48 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x30U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v49 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x31U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v50 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x32U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v51 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x33U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v52 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x34U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v53 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x35U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v54 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x36U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v55 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x37U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v56 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x38U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v57 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x39U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v58 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x3aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v59 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x3bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v60 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x3cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v61 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x3dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v62 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x3eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v63 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x3fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v64 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x40U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v65 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x41U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v66 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x42U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v67 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x43U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v68 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x44U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v69 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x45U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v70 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x46U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v71 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x47U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v72 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x48U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v73 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x49U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v74 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x4aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v75 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x4bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v76 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x4cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v77 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x4dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v78 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x4eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v79 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x4fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v80 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x50U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v81 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x51U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v82 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x52U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v83 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x53U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v84 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x54U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v85 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x55U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v86 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x56U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v87 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x57U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v88 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x58U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v89 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x59U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v90 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x5aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v91 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x5bU];
    if ((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter))) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
            [0x3fU];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
            [0x3fU];
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [0x1fU];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [0x1fU];
    }
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v92 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x5cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v93 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x5dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v94 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x5eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v95 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x5fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v96 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x60U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v97 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x61U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v98 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x62U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v99 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x63U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v100 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x64U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v101 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x65U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v102 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x66U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v103 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x67U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v104 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x68U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v105 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x69U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v106 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x6aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v107 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x6bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v108 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x6cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v109 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x6dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v110 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x6eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v111 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x6fU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v112 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x70U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v113 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x71U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v114 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x72U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v115 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x73U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v116 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x74U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v117 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x75U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v118 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x76U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v119 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x77U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v120 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x78U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v121 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x79U];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v122 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x7aU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v123 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x7bU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v124 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x7cU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v125 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x7dU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v126 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
        [0x7eU];
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v127 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_1;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v127 
        = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_1;
    if ((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter))) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_1;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_1;
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_0;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_0;
    }
    if ((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter))) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_1;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_1;
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_0;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_0;
    }
    if ((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter))) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_1;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_1;
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_0;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_0;
    }
    if ((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter))) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v15 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_1;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v15 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_1;
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v15 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_0;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v15 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_0;
    }
    if ((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter))) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v31 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_1;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v31 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_1;
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v31 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_0;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v31 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_0;
    }
    if ((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter))) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v63 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_1;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v63 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_1;
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v63 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_0;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v63 
            = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_0;
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    vlSelf->tb_radix2_top__DOT__counting_latency = __Vdly__tb_radix2_top__DOT__counting_latency;
    vlSelf->tb_radix2_top__DOT__t_latency = __Vdly__tb_radix2_top__DOT__t_latency;
    vlSelf->tb_radix2_top__DOT__counting_active = __Vdly__tb_radix2_top__DOT__counting_active;
    vlSelf->tb_radix2_top__DOT__t_active = __Vdly__tb_radix2_top__DOT__t_active;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15;
    if ((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter))) {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
            [0x7fU];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
            [0x7fU];
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
            [0x3fU];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
            [0x3fU];
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x10U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x11U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v16;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x12U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v17;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x13U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v18;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x14U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v19;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x15U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v20;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x16U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v21;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x17U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v22;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x18U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v23;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x19U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v24;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v25;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v26;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v27;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v28;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v29;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v30;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v31;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x10U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x11U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v16;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x12U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v17;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x13U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v18;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x14U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v19;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x15U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v20;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x16U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v21;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x17U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v22;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x18U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v23;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x19U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v24;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v25;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v26;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v27;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v28;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v29;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v30;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v31;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x10U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x11U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v16;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x12U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v17;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x13U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v18;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x14U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v19;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x15U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v20;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x16U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v21;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x17U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v22;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x18U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v23;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x19U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v24;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v25;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v26;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v27;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v28;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v29;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v30;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x20U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v31;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x21U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v32;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x22U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v33;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x23U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v34;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x24U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v35;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x25U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v36;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x26U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v37;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x27U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v38;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x28U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v39;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x29U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v40;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x2aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v41;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x2bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v42;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x2cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v43;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x2dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v44;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x2eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v45;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x2fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v46;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x30U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v47;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x31U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v48;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x32U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v49;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x33U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v50;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x34U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v51;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x35U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v52;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x36U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v53;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x37U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v54;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x38U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v55;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x39U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v56;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x3aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v57;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x3bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v58;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x3cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v59;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x3dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v60;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x3eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v61;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x3fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v62;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v63;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x10U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x11U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v16;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x12U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v17;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x13U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v18;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x14U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v19;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x15U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v20;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x16U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v21;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x17U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v22;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x18U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v23;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x19U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v24;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v25;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v26;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v27;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v28;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v29;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v30;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x20U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v31;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x21U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v32;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x22U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v33;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x23U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v34;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x24U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v35;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x25U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v36;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x26U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v37;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x27U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v38;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x28U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v39;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x29U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v40;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x2aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v41;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x2bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v42;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x2cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v43;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x2dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v44;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x2eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v45;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x2fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v46;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x30U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v47;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x31U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v48;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x32U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v49;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x33U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v50;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x34U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v51;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x35U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v52;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x36U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v53;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x37U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v54;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x38U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v55;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x39U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v56;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x3aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v57;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x3bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v58;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x3cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v59;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x3dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v60;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x3eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v61;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x3fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v62;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v63;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x10U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v15;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x11U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v16;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x12U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v17;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x13U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v18;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x14U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v19;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x15U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v20;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x16U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v21;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x17U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v22;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x18U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v23;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x19U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v24;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v25;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v26;
    if (vlSelf->tb_radix2_top__DOT__reset) {
        __Vdly__tb_radix2_top__DOT__output_count = 0U;
        __Vdly__tb_radix2_top__DOT__write_offset = 0U;
        vlSelf->tb_radix2_top__DOT__frame_ready = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_real_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_imag_0 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_real_1 = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_imag_1 = 0U;
    } else {
        vlSelf->tb_radix2_top__DOT__frame_ready = 0U;
        if (vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_en) {
            __Vdlyvval__tb_radix2_top__DOT__output_real__v0 
                = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_real_0;
            __Vdlyvset__tb_radix2_top__DOT__output_real__v0 = 1U;
            __Vdlyvdim0__tb_radix2_top__DOT__output_real__v0 
                = (0x1ffU & (vlSelf->tb_radix2_top__DOT__write_offset 
                             + vlSelf->tb_radix2_top__DOT__output_count));
            __Vdlyvval__tb_radix2_top__DOT__output_imag__v0 
                = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_imag_0;
            __Vdlyvdim0__tb_radix2_top__DOT__output_imag__v0 
                = (0x1ffU & (vlSelf->tb_radix2_top__DOT__write_offset 
                             + vlSelf->tb_radix2_top__DOT__output_count));
            __Vdlyvval__tb_radix2_top__DOT__output_real__v1 
                = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_real_1;
            __Vdlyvdim0__tb_radix2_top__DOT__output_real__v1 
                = (0x1ffU & ((IData)(0x80U) + (vlSelf->tb_radix2_top__DOT__write_offset 
                                               + vlSelf->tb_radix2_top__DOT__output_count)));
            __Vdlyvval__tb_radix2_top__DOT__output_imag__v1 
                = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_imag_1;
            __Vdlyvdim0__tb_radix2_top__DOT__output_imag__v1 
                = (0x1ffU & ((IData)(0x80U) + (vlSelf->tb_radix2_top__DOT__write_offset 
                                               + vlSelf->tb_radix2_top__DOT__output_count)));
            if ((0x7fU == vlSelf->tb_radix2_top__DOT__output_count)) {
                __Vdly__tb_radix2_top__DOT__output_count = 0U;
                vlSelf->tb_radix2_top__DOT__print_offset 
                    = vlSelf->tb_radix2_top__DOT__write_offset;
                vlSelf->tb_radix2_top__DOT__frame_ready = 1U;
                __Vdly__tb_radix2_top__DOT__write_offset 
                    = ((0U == vlSelf->tb_radix2_top__DOT__write_offset)
                        ? 0x100U : 0U);
            } else {
                __Vdly__tb_radix2_top__DOT__output_count 
                    = ((IData)(1U) + vlSelf->tb_radix2_top__DOT__output_count);
            }
        }
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y1_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y0_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y1_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y0_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y1_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y0_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y1_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y0_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y1_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y0_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y1_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y0_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y1_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y0_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y1_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y0_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y1_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y0_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y1_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y0_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y1_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y0_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y1_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y0_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y1_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y0_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y1_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y0_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_real_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y0_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_imag_0 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y0_im;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_real_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y1_re;
        vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_imag_1 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y1_im;
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v27;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v28;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v29;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x1fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v30;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x20U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v31;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x21U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v32;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x22U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v33;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x23U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v34;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x24U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v35;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x25U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v36;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x26U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v37;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x27U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v38;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x28U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v39;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x29U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v40;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x2aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v41;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x2bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v42;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x2cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v43;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x2dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v44;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x2eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v45;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x2fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v46;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x30U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v47;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x31U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v48;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x32U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v49;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x33U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v50;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x34U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v51;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x35U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v52;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x36U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v53;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x37U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v54;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x38U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v55;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x39U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v56;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x3aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v57;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x3bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v58;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x3cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v59;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x3dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v60;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x3eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v61;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x3fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v62;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x40U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v63;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x41U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v64;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x42U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v65;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x43U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v66;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x44U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v67;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x45U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v68;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x46U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v69;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x47U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v70;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x48U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v71;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x49U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v72;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x4aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v73;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x4bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v74;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x4cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v75;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x4dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v76;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x4eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v77;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x4fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v78;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x50U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v79;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x51U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v80;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x52U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v81;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x53U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v82;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x54U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v83;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x55U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v84;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x56U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v85;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x57U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v86;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x58U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v87;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x59U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v88;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x5aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v89;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x5bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v90;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x5cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v91;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x5dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v92;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x5eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v93;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x5fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v94;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x60U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v95;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x61U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v96;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x62U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v97;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x63U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v98;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x64U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v99;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x65U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v100;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x66U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v101;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x67U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v102;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x68U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v103;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x69U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v104;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x6aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v105;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x6bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v106;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x6cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v107;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x6dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v108;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x6eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v109;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x6fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v110;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x70U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v111;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x71U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v112;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x72U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v113;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x73U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v114;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x74U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v115;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x75U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v116;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x76U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v117;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x77U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v118;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x78U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v119;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x79U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v120;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x7aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v121;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x7bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v122;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x7cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v123;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x7dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v124;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x7eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v125;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0x7fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v126;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im__v127;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x10U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v15;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x11U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v16;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x12U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v17;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x13U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v18;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x14U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v19;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x15U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v20;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x16U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v21;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x17U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v22;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x18U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v23;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x19U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v24;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v25;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v26;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v27;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v28;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v29;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x1fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v30;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x20U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v31;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x21U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v32;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x22U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v33;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x23U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v34;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x24U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v35;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x25U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v36;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x26U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v37;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x27U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v38;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x28U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v39;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x29U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v40;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x2aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v41;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x2bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v42;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x2cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v43;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x2dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v44;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x2eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v45;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x2fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v46;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x30U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v47;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x31U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v48;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x32U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v49;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x33U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v50;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x34U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v51;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x35U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v52;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x36U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v53;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x37U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v54;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x38U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v55;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x39U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v56;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x3aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v57;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x3bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v58;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x3cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v59;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x3dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v60;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x3eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v61;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x3fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v62;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x40U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v63;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x41U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v64;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x42U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v65;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x43U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v66;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x44U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v67;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x45U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v68;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x46U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v69;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x47U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v70;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x48U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v71;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x49U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v72;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x4aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v73;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x4bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v74;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x4cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v75;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x4dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v76;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x4eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v77;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x4fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v78;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x50U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v79;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x51U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v80;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x52U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v81;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x53U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v82;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x54U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v83;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x55U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v84;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x56U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v85;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x57U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v86;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x58U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v87;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x59U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v88;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x5aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v89;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x5bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v90;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x5cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v91;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x5dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v92;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x5eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v93;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x5fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v94;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x60U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v95;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x61U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v96;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x62U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v97;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x63U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v98;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x64U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v99;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x65U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v100;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x66U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v101;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x67U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v102;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x68U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v103;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x69U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v104;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x6aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v105;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x6bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v106;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x6cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v107;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x6dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v108;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x6eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v109;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x6fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v110;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x70U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v111;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x71U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v112;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x72U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v113;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x73U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v114;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x74U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v115;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x75U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v116;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x76U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v117;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x77U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v118;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x78U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v119;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x79U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v120;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x7aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v121;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x7bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v122;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x7cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v123;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x7dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v124;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x7eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v125;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0x7fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v126;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re__v127;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v15;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v15;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x10U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v15;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x11U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v16;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x12U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v17;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x13U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v18;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x14U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v19;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x15U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v20;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x16U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v21;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x17U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v22;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x18U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v23;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x19U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v24;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x1aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v25;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x1bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v26;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x1cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v27;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x1dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v28;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x1eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v29;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x1fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v30;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v31;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x10U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v15;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x11U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v16;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x12U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v17;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x13U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v18;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x14U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v19;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x15U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v20;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x16U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v21;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x17U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v22;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x18U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v23;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x19U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v24;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x1aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v25;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x1bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v26;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x1cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v27;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x1dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v28;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x1eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v29;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x1fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v30;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v31;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x10U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v15;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x11U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v16;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x12U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v17;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x13U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v18;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x14U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v19;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x15U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v20;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x16U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v21;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x17U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v22;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x18U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v23;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x19U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v24;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x1aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v25;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x1bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v26;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x1cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v27;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x1dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v28;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x1eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v29;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x1fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v30;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x20U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v31;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x21U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v32;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x22U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v33;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x23U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v34;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x24U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v35;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x25U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v36;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x26U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v37;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x27U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v38;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x28U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v39;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x29U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v40;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x2aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v41;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x2bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v42;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x2cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v43;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x2dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v44;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x2eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v45;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x2fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v46;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x30U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v47;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x31U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v48;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x32U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v49;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x33U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v50;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x34U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v51;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x35U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v52;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x36U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v53;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x37U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v54;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x38U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v55;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x39U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v56;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x3aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v57;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x3bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v58;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x3cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v59;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x3dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v60;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x3eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v61;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0x3fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v62;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im__v63;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter 
        = __Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[3U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[4U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v3;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[5U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v4;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[6U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v5;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[7U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v6;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[8U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v7;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[9U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v8;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xaU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v9;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xbU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v10;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xcU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v11;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xdU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v12;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xeU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v13;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0xfU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v14;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x10U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v15;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x11U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v16;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x12U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v17;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x13U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v18;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x14U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v19;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x15U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v20;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x16U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v21;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x17U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v22;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x18U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v23;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x19U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v24;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x1aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v25;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x1bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v26;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x1cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v27;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x1dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v28;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x1eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v29;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x1fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v30;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x20U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v31;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x21U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v32;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x22U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v33;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x23U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v34;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x24U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v35;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x25U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v36;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x26U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v37;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x27U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v38;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x28U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v39;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x29U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v40;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x2aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v41;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x2bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v42;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x2cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v43;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x2dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v44;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x2eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v45;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x2fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v46;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x30U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v47;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x31U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v48;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x32U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v49;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x33U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v50;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x34U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v51;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x35U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v52;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x36U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v53;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x37U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v54;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x38U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v55;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x39U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v56;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x3aU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v57;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x3bU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v58;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x3cU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v59;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x3dU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v60;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x3eU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v61;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0x3fU] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v62;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re__v63;
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_en 
        = ((1U & (~ (IData)(vlSelf->tb_radix2_top__DOT__reset))) 
           && vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
           [0U]);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_en 
        = ((1U & (~ (IData)(vlSelf->tb_radix2_top__DOT__reset))) 
           && vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
           [3U]);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_en 
        = ((1U & (~ (IData)(vlSelf->tb_radix2_top__DOT__reset))) 
           && vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
           [3U]);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_en 
        = ((1U & (~ (IData)(vlSelf->tb_radix2_top__DOT__reset))) 
           && vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
           [3U]);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_en 
        = ((1U & (~ (IData)(vlSelf->tb_radix2_top__DOT__reset))) 
           && vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
           [3U]);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_en 
        = ((1U & (~ (IData)(vlSelf->tb_radix2_top__DOT__reset))) 
           && vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
           [3U]);
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_en 
        = ((1U & (~ (IData)(vlSelf->tb_radix2_top__DOT__reset))) 
           && vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
           [3U]);
    vlSelf->tb_radix2_top__DOT__input_en_d = vlSelf->tb_radix2_top__DOT__input_en;
    vlSelf->tb_radix2_top__DOT__output_en_d = vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_en;
    vlSelf->tb_radix2_top__DOT__output_count = __Vdly__tb_radix2_top__DOT__output_count;
    vlSelf->tb_radix2_top__DOT__write_offset = __Vdly__tb_radix2_top__DOT__write_offset;
    if (__Vdlyvset__tb_radix2_top__DOT__output_real__v0) {
        vlSelf->tb_radix2_top__DOT__output_imag[__Vdlyvdim0__tb_radix2_top__DOT__output_imag__v0] 
            = __Vdlyvval__tb_radix2_top__DOT__output_imag__v0;
        vlSelf->tb_radix2_top__DOT__output_imag[__Vdlyvdim0__tb_radix2_top__DOT__output_imag__v1] 
            = __Vdlyvval__tb_radix2_top__DOT__output_imag__v1;
        vlSelf->tb_radix2_top__DOT__output_real[__Vdlyvdim0__tb_radix2_top__DOT__output_real__v0] 
            = __Vdlyvval__tb_radix2_top__DOT__output_real__v0;
        vlSelf->tb_radix2_top__DOT__output_real[__Vdlyvdim0__tb_radix2_top__DOT__output_real__v1] 
            = __Vdlyvval__tb_radix2_top__DOT__output_real__v1;
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_en 
        = ((1U & (~ (IData)(vlSelf->tb_radix2_top__DOT__reset))) 
           && vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
           [3U]);
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y0_re 
        = (0xffffU & ((IData)(vlSelf->tb_radix2_top__DOT__input_real_0) 
                      + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__0__x 
                        = (0xffffffU & VL_SHIFTL_III(24,24,32, 
                                                     VL_EXTENDS_II(24,16, (IData)(vlSelf->tb_radix2_top__DOT__input_real_1)), 7U));
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__0__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__0__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__0__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y0_im 
        = (0xffffU & ((IData)(vlSelf->tb_radix2_top__DOT__input_imag_0) 
                      + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__1__x 
                        = (0xffffffU & VL_SHIFTL_III(24,24,32, 
                                                     VL_EXTENDS_II(24,16, (IData)(vlSelf->tb_radix2_top__DOT__input_imag_1)), 7U));
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__1__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__1__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__1__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y1_re 
        = (0xffffU & ((IData)(vlSelf->tb_radix2_top__DOT__input_real_0) 
                      - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__2__x 
                        = (0xffffffU & VL_SHIFTL_III(24,24,32, 
                                                     VL_EXTENDS_II(24,16, (IData)(vlSelf->tb_radix2_top__DOT__input_real_1)), 7U));
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__2__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__2__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__2__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y1_im 
        = (0xffffU & ((IData)(vlSelf->tb_radix2_top__DOT__input_imag_0) 
                      - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__3__x 
                        = (0xffffffU & VL_SHIFTL_III(24,24,32, 
                                                     VL_EXTENDS_II(24,16, (IData)(vlSelf->tb_radix2_top__DOT__input_imag_1)), 7U));
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__3__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__3__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__3__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y0_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__4__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__4__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__4__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__4__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y0_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__5__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__5__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__5__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__5__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y1_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__6__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__6__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__6__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__6__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y1_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__7__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__7__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__7__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__7__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y0_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__8__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__8__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__8__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__8__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y0_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__9__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__9__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__9__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__9__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y1_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__10__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__10__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__10__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__10__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y1_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__11__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__11__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__11__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__11__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y0_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__12__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__12__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__12__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__12__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y0_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__13__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__13__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__13__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__13__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y1_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__14__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__14__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__14__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__14__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y1_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__15__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__15__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__15__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__15__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y0_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__16__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__16__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__16__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__16__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y0_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__17__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__17__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__17__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__17__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y1_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__18__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__18__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__18__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__18__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y1_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__19__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__19__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__19__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__19__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y0_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__20__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__20__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__20__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__20__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y0_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__21__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__21__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__21__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__21__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y1_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__22__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__22__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__22__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__22__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y1_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__23__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__23__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__23__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__23__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y0_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__24__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__24__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__24__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__24__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y0_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__25__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__25__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__25__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__25__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y1_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__26__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__26__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__26__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__26__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y1_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__27__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__27__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__27__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__27__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y0_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__28__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__28__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__28__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__28__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y0_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] + ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__29__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__29__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__29__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__29__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y1_re 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__30__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__30__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__30__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__30__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y1_im 
        = (0xffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line
                      [2U] - ([&]() {
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__31__x 
                        = (0xffffffU & vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im);
                    __Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__31__Vfuncout 
                        = (0xffffU & (__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__31__x 
                                      >> 7U));
                }(), (IData)(__Vfunc_tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__scale_product__31__Vfuncout))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         - vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         + vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         - vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         + vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         - vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         + vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         - vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         + vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         - vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         + vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         - vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         + vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_a__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v0;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[1U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v1;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line[2U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_ai__DOT__genblk1__DOT__delay_line__v2;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_re 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         - vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT____Vcellout__stage_gen__DOT__cheap_mult__DOT__u_cmul__out_a_im 
        = (0x1ffffffU & (vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
                         + vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,17, vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,17, vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,17, vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,17, vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,17, vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,17, vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k3_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k2_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,9, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in)))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__k1_a 
        = (0x1ffffffU & VL_MULS_III(25, (0x1ffffffU 
                                         & VL_EXTENDS_II(25,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d))), 
                                    (0x1ffffffU & VL_EXTENDS_II(25,17, vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__x1_im;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__wr)) 
                     + VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__wi))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__x1_re;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__wi)) 
                     - VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__wr))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__wr;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in 
        = (0x1ffffU & (VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__x1_re)) 
                       + VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__x1_im))));
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
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__x1_im;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__wr)) 
                     + VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__wi))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__x1_re;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__wi)) 
                     - VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__wr))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__wr;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in 
        = (0x1ffffU & (VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__x1_re)) 
                       + VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__x1_im))));
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
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__x1_im;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__wr)) 
                     + VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__wi))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__x1_re;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__wi)) 
                     - VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__wr))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__wr;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in 
        = (0x1ffffU & (VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__x1_re)) 
                       + VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__x1_im))));
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
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__x1_im;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__wr)) 
                     + VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__wi))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__x1_re;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__wi)) 
                     - VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__wr))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__wr;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in 
        = (0x1ffffU & (VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__x1_re)) 
                       + VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__x1_im))));
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
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__x1_im;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__wr)) 
                     + VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__wi))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__x1_re;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__wi)) 
                     - VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__wr))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__wr;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in 
        = (0x1ffffU & (VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__x1_re)) 
                       + VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__x1_im))));
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
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_im;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wr)) 
                     + VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wi))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_re;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wi)) 
                     - VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wr))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wr;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in 
        = (0x1ffffU & (VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_re)) 
                       + VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__x1_im))));
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
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_im_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_im;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wr)) 
                     + VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wi))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__a_re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_re;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__diff_w0_in 
        = (0x1ffU & (VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wi)) 
                     - VL_EXTENDS_II(9,8, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wr))));
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__w0re_d 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wr;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__stage_gen__DOT__cheap_mult__DOT__u_cmul__DOT__slow_dsp__DOT__no_carry_save_mult__DOT__sum_a_in 
        = (0x1ffffU & (VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_re)) 
                       + VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__x1_im))));
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
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wi 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__w_imag
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter];
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__wr 
        = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__w_real
        [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter];
}

VL_INLINE_OPT void Vtb_radix2_top___024root___nba_sequent__TOP__1(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 = 0;
    CData/*0:0*/ __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 = 0;
    // Body
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0U;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0U;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0U;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0U;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0U;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0U;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0U;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0U;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0U;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0U;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0U;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0U;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 0U;
    __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 0U;
    __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 
        = ((1U & (~ (IData)(vlSelf->tb_radix2_top__DOT__reset))) 
           && (IData)(vlSelf->tb_radix2_top__DOT__input_en));
    if (vlSelf->tb_radix2_top__DOT__reset) {
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 1U;
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 1U;
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 1U;
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 1U;
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 1U;
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 1U;
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0 = 1U;
    } else {
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 1U;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [0U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [1U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [2U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 1U;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [0U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [1U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [2U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 1U;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [0U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [1U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [2U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 1U;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [0U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [1U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [2U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 1U;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [0U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [1U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [2U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 1U;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [0U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [1U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [2U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
        __Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4 = 1U;
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [0U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [1U];
        __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7 
            = vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line
            [2U];
    }
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] 
        = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0;
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] = 0U;
    }
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    }
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] = 0U;
    }
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    }
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] = 0U;
    }
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    }
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] = 0U;
    }
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    }
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] = 0U;
    }
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    }
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] = 0U;
    }
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    }
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v0) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] = 0U;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] = 0U;
    }
    if (__Vdlyvset__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4) {
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[0U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v4;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[1U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v5;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[2U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v6;
        vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line[3U] 
            = __Vdlyvval__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_delay_start__DOT__genblk1__DOT__delay_line__v7;
    }
}

VL_INLINE_OPT void Vtb_radix2_top___024root___nba_sequent__TOP__2(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
    vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en 
        = vlSelf->__Vdly__tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en;
}

void Vtb_radix2_top___024root___eval_nba(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_radix2_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_radix2_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_radix2_top___024root___nba_sequent__TOP__2(vlSelf);
    }
}

void Vtb_radix2_top___024root___timing_resume(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h121e40a7__0.resume("@(posedge tb_radix2_top.clock)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_radix2_top___024root___timing_commit(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h121e40a7__0.commit("@(posedge tb_radix2_top.clock)");
    }
}

void Vtb_radix2_top___024root___eval_triggers__act(Vtb_radix2_top___024root* vlSelf);

bool Vtb_radix2_top___024root___eval_phase__act(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_radix2_top___024root___eval_triggers__act(vlSelf);
    Vtb_radix2_top___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_radix2_top___024root___timing_resume(vlSelf);
        Vtb_radix2_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_radix2_top___024root___eval_phase__nba(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_radix2_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_radix2_top___024root___dump_triggers__nba(Vtb_radix2_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_radix2_top___024root___dump_triggers__act(Vtb_radix2_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_radix2_top___024root___eval(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_radix2_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../Radix-2/tb_top_radix_2.v", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_radix2_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../Radix-2/tb_top_radix_2.v", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_radix2_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_radix2_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_radix2_top___024root___eval_debug_assertions(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
