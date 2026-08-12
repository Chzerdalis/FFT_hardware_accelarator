// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_radix2_top.h for the primary calling header

#include "Vtb_radix2_top__pch.h"
#include "Vtb_radix2_top__Syms.h"
#include "Vtb_radix2_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_radix2_top___024root___dump_triggers__act(Vtb_radix2_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_radix2_top___024root___eval_triggers__act(Vtb_radix2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->tb_radix2_top__DOT__clock) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_radix2_top__DOT__clock__0))));
    vlSelf->__VactTriggered.set(1U, (((IData)(vlSelf->tb_radix2_top__DOT__clock) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_radix2_top__DOT__clock__0))) 
                                     | ((IData)(vlSelf->tb_radix2_top__DOT__reset) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_radix2_top__DOT__reset__0)))));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_radix2_top__DOT__clock__0 
        = vlSelf->tb_radix2_top__DOT__clock;
    vlSelf->__Vtrigprevexpr___TOP__tb_radix2_top__DOT__reset__0 
        = vlSelf->tb_radix2_top__DOT__reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_radix2_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
