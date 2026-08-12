// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_radix2_top__Syms.h"


void Vtb_radix2_top___024root__trace_chg_0_sub_0(Vtb_radix2_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_radix2_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root__trace_chg_0\n"); );
    // Init
    Vtb_radix2_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_radix2_top___024root*>(voidSelf);
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_radix2_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_radix2_top___024root__trace_chg_0_sub_0(Vtb_radix2_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->tb_radix2_top__DOT__total_samples_read),32);
        bufp->chgIData(oldp+1,(vlSelf->tb_radix2_top__DOT__in_file_id),32);
        bufp->chgIData(oldp+2,(vlSelf->tb_radix2_top__DOT__scan_count),32);
        bufp->chgIData(oldp+3,(vlSelf->tb_radix2_top__DOT__t_i),32);
        bufp->chgIData(oldp+4,(vlSelf->tb_radix2_top__DOT__t_r),32);
        bufp->chgSData(oldp+5,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_real
                               [0U]),13);
        bufp->chgSData(oldp+6,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_imag
                               [0U]),13);
        bufp->chgSData(oldp+7,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_real[0]),13);
        bufp->chgSData(oldp+8,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__w_imag[0]),13);
        bufp->chgSData(oldp+9,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_real[0]),13);
        bufp->chgSData(oldp+10,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_real[1]),13);
        bufp->chgSData(oldp+11,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_imag[0]),13);
        bufp->chgSData(oldp+12,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_imag[1]),13);
        bufp->chgSData(oldp+13,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real[0]),13);
        bufp->chgSData(oldp+14,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real[1]),13);
        bufp->chgSData(oldp+15,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real[2]),13);
        bufp->chgSData(oldp+16,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real[3]),13);
        bufp->chgSData(oldp+17,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag[0]),13);
        bufp->chgSData(oldp+18,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag[1]),13);
        bufp->chgSData(oldp+19,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag[2]),13);
        bufp->chgSData(oldp+20,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag[3]),13);
        bufp->chgSData(oldp+21,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[0]),13);
        bufp->chgSData(oldp+22,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[1]),13);
        bufp->chgSData(oldp+23,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[2]),13);
        bufp->chgSData(oldp+24,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[3]),13);
        bufp->chgSData(oldp+25,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[4]),13);
        bufp->chgSData(oldp+26,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[5]),13);
        bufp->chgSData(oldp+27,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[6]),13);
        bufp->chgSData(oldp+28,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real[7]),13);
        bufp->chgSData(oldp+29,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[0]),13);
        bufp->chgSData(oldp+30,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[1]),13);
        bufp->chgSData(oldp+31,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[2]),13);
        bufp->chgSData(oldp+32,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[3]),13);
        bufp->chgSData(oldp+33,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[4]),13);
        bufp->chgSData(oldp+34,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[5]),13);
        bufp->chgSData(oldp+35,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[6]),13);
        bufp->chgSData(oldp+36,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag[7]),13);
        bufp->chgSData(oldp+37,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[0]),13);
        bufp->chgSData(oldp+38,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[1]),13);
        bufp->chgSData(oldp+39,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[2]),13);
        bufp->chgSData(oldp+40,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[3]),13);
        bufp->chgSData(oldp+41,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[4]),13);
        bufp->chgSData(oldp+42,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[5]),13);
        bufp->chgSData(oldp+43,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[6]),13);
        bufp->chgSData(oldp+44,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[7]),13);
        bufp->chgSData(oldp+45,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[8]),13);
        bufp->chgSData(oldp+46,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[9]),13);
        bufp->chgSData(oldp+47,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[10]),13);
        bufp->chgSData(oldp+48,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[11]),13);
        bufp->chgSData(oldp+49,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[12]),13);
        bufp->chgSData(oldp+50,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[13]),13);
        bufp->chgSData(oldp+51,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[14]),13);
        bufp->chgSData(oldp+52,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real[15]),13);
        bufp->chgSData(oldp+53,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[0]),13);
        bufp->chgSData(oldp+54,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[1]),13);
        bufp->chgSData(oldp+55,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[2]),13);
        bufp->chgSData(oldp+56,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[3]),13);
        bufp->chgSData(oldp+57,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[4]),13);
        bufp->chgSData(oldp+58,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[5]),13);
        bufp->chgSData(oldp+59,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[6]),13);
        bufp->chgSData(oldp+60,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[7]),13);
        bufp->chgSData(oldp+61,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[8]),13);
        bufp->chgSData(oldp+62,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[9]),13);
        bufp->chgSData(oldp+63,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[10]),13);
        bufp->chgSData(oldp+64,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[11]),13);
        bufp->chgSData(oldp+65,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[12]),13);
        bufp->chgSData(oldp+66,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[13]),13);
        bufp->chgSData(oldp+67,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[14]),13);
        bufp->chgSData(oldp+68,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag[15]),13);
        bufp->chgSData(oldp+69,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[0]),13);
        bufp->chgSData(oldp+70,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[1]),13);
        bufp->chgSData(oldp+71,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[2]),13);
        bufp->chgSData(oldp+72,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[3]),13);
        bufp->chgSData(oldp+73,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[4]),13);
        bufp->chgSData(oldp+74,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[5]),13);
        bufp->chgSData(oldp+75,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[6]),13);
        bufp->chgSData(oldp+76,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[7]),13);
        bufp->chgSData(oldp+77,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[8]),13);
        bufp->chgSData(oldp+78,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[9]),13);
        bufp->chgSData(oldp+79,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[10]),13);
        bufp->chgSData(oldp+80,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[11]),13);
        bufp->chgSData(oldp+81,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[12]),13);
        bufp->chgSData(oldp+82,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[13]),13);
        bufp->chgSData(oldp+83,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[14]),13);
        bufp->chgSData(oldp+84,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[15]),13);
        bufp->chgSData(oldp+85,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[16]),13);
        bufp->chgSData(oldp+86,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[17]),13);
        bufp->chgSData(oldp+87,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[18]),13);
        bufp->chgSData(oldp+88,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[19]),13);
        bufp->chgSData(oldp+89,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[20]),13);
        bufp->chgSData(oldp+90,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[21]),13);
        bufp->chgSData(oldp+91,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[22]),13);
        bufp->chgSData(oldp+92,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[23]),13);
        bufp->chgSData(oldp+93,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[24]),13);
        bufp->chgSData(oldp+94,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[25]),13);
        bufp->chgSData(oldp+95,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[26]),13);
        bufp->chgSData(oldp+96,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[27]),13);
        bufp->chgSData(oldp+97,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[28]),13);
        bufp->chgSData(oldp+98,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[29]),13);
        bufp->chgSData(oldp+99,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[30]),13);
        bufp->chgSData(oldp+100,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real[31]),13);
        bufp->chgSData(oldp+101,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[0]),13);
        bufp->chgSData(oldp+102,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[1]),13);
        bufp->chgSData(oldp+103,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[2]),13);
        bufp->chgSData(oldp+104,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[3]),13);
        bufp->chgSData(oldp+105,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[4]),13);
        bufp->chgSData(oldp+106,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[5]),13);
        bufp->chgSData(oldp+107,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[6]),13);
        bufp->chgSData(oldp+108,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[7]),13);
        bufp->chgSData(oldp+109,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[8]),13);
        bufp->chgSData(oldp+110,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[9]),13);
        bufp->chgSData(oldp+111,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[10]),13);
        bufp->chgSData(oldp+112,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[11]),13);
        bufp->chgSData(oldp+113,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[12]),13);
        bufp->chgSData(oldp+114,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[13]),13);
        bufp->chgSData(oldp+115,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[14]),13);
        bufp->chgSData(oldp+116,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[15]),13);
        bufp->chgSData(oldp+117,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[16]),13);
        bufp->chgSData(oldp+118,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[17]),13);
        bufp->chgSData(oldp+119,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[18]),13);
        bufp->chgSData(oldp+120,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[19]),13);
        bufp->chgSData(oldp+121,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[20]),13);
        bufp->chgSData(oldp+122,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[21]),13);
        bufp->chgSData(oldp+123,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[22]),13);
        bufp->chgSData(oldp+124,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[23]),13);
        bufp->chgSData(oldp+125,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[24]),13);
        bufp->chgSData(oldp+126,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[25]),13);
        bufp->chgSData(oldp+127,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[26]),13);
        bufp->chgSData(oldp+128,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[27]),13);
        bufp->chgSData(oldp+129,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[28]),13);
        bufp->chgSData(oldp+130,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[29]),13);
        bufp->chgSData(oldp+131,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[30]),13);
        bufp->chgSData(oldp+132,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag[31]),13);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+133,(vlSelf->tb_radix2_top__DOT__reset));
        bufp->chgBit(oldp+134,(vlSelf->tb_radix2_top__DOT__input_en));
        bufp->chgIData(oldp+135,(vlSelf->tb_radix2_top__DOT__input_real_0),26);
        bufp->chgIData(oldp+136,(vlSelf->tb_radix2_top__DOT__input_real_1),26);
        bufp->chgIData(oldp+137,(vlSelf->tb_radix2_top__DOT__input_imag_0),26);
        bufp->chgIData(oldp+138,(vlSelf->tb_radix2_top__DOT__input_imag_1),26);
        bufp->chgIData(oldp+139,(vlSelf->tb_radix2_top__DOT__out_file_id),32);
        bufp->chgIData(oldp+140,(vlSelf->tb_radix2_top__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[4U]))) {
        bufp->chgSData(oldp+141,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_real
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
        bufp->chgSData(oldp+142,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__w_imag
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
        bufp->chgSData(oldp+143,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_real
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
        bufp->chgSData(oldp+144,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__w_imag
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
        bufp->chgSData(oldp+145,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_real
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
        bufp->chgSData(oldp+146,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__w_imag
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
        bufp->chgSData(oldp+147,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_real
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
        bufp->chgSData(oldp+148,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__w_imag
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
        bufp->chgSData(oldp+149,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_real
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
        bufp->chgSData(oldp+150,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__w_imag
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
        bufp->chgSData(oldp+151,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__w_real
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
        bufp->chgSData(oldp+152,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__w_imag
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
        bufp->chgSData(oldp+153,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__w_real
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
        bufp->chgSData(oldp+154,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__w_imag
                                 [vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter]),13);
    }
    if (VL_UNLIKELY(((vlSelf->__Vm_traceActivity[3U] 
                      | vlSelf->__Vm_traceActivity[4U]) 
                     | vlSelf->__Vm_traceActivity[5U]))) {
        bufp->chgIData(oldp+155,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[0]),26);
        bufp->chgIData(oldp+156,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[1]),26);
        bufp->chgIData(oldp+157,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[2]),26);
        bufp->chgIData(oldp+158,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[3]),26);
        bufp->chgIData(oldp+159,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[4]),26);
        bufp->chgIData(oldp+160,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[5]),26);
        bufp->chgIData(oldp+161,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[6]),26);
        bufp->chgIData(oldp+162,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_0[7]),26);
        bufp->chgIData(oldp+163,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[0]),26);
        bufp->chgIData(oldp+164,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[1]),26);
        bufp->chgIData(oldp+165,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[2]),26);
        bufp->chgIData(oldp+166,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[3]),26);
        bufp->chgIData(oldp+167,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[4]),26);
        bufp->chgIData(oldp+168,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[5]),26);
        bufp->chgIData(oldp+169,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[6]),26);
        bufp->chgIData(oldp+170,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_real_stage_1[7]),26);
        bufp->chgIData(oldp+171,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[0]),26);
        bufp->chgIData(oldp+172,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[1]),26);
        bufp->chgIData(oldp+173,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[2]),26);
        bufp->chgIData(oldp+174,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[3]),26);
        bufp->chgIData(oldp+175,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[4]),26);
        bufp->chgIData(oldp+176,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[5]),26);
        bufp->chgIData(oldp+177,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[6]),26);
        bufp->chgIData(oldp+178,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_0[7]),26);
        bufp->chgIData(oldp+179,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[0]),26);
        bufp->chgIData(oldp+180,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[1]),26);
        bufp->chgIData(oldp+181,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[2]),26);
        bufp->chgIData(oldp+182,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[3]),26);
        bufp->chgIData(oldp+183,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[4]),26);
        bufp->chgIData(oldp+184,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[5]),26);
        bufp->chgIData(oldp+185,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[6]),26);
        bufp->chgIData(oldp+186,(vlSelf->tb_radix2_top__DOT__dut__DOT__input_imag_stage_1[7]),26);
        bufp->chgBit(oldp+187,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[0]));
        bufp->chgBit(oldp+188,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[1]));
        bufp->chgBit(oldp+189,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[2]));
        bufp->chgBit(oldp+190,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[3]));
        bufp->chgBit(oldp+191,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[4]));
        bufp->chgBit(oldp+192,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[5]));
        bufp->chgBit(oldp+193,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[6]));
        bufp->chgBit(oldp+194,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[7]));
        bufp->chgBit(oldp+195,(vlSelf->tb_radix2_top__DOT__dut__DOT__enable_stage[8]));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgBit(oldp+196,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_en));
        bufp->chgIData(oldp+197,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_real_0),26);
        bufp->chgIData(oldp+198,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_real_1),26);
        bufp->chgIData(oldp+199,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_imag_0),26);
        bufp->chgIData(oldp+200,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__7__KET____DOT__stage_inst__output_imag_1),26);
        bufp->chgIData(oldp+201,(vlSelf->tb_radix2_top__DOT__output_count),32);
        bufp->chgIData(oldp+202,(vlSelf->tb_radix2_top__DOT__k),32);
        bufp->chgBit(oldp+203,(vlSelf->tb_radix2_top__DOT__frame_ready));
        bufp->chgIData(oldp+204,(vlSelf->tb_radix2_top__DOT__window_count),32);
        bufp->chgIData(oldp+205,(vlSelf->tb_radix2_top__DOT__write_offset),32);
        bufp->chgIData(oldp+206,(vlSelf->tb_radix2_top__DOT__print_offset),32);
        bufp->chgIData(oldp+207,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[0]),26);
        bufp->chgIData(oldp+208,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[1]),26);
        bufp->chgIData(oldp+209,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[2]),26);
        bufp->chgIData(oldp+210,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[3]),26);
        bufp->chgIData(oldp+211,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[4]),26);
        bufp->chgIData(oldp+212,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[5]),26);
        bufp->chgIData(oldp+213,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[6]),26);
        bufp->chgIData(oldp+214,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_0[7]),26);
        bufp->chgIData(oldp+215,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[0]),26);
        bufp->chgIData(oldp+216,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[1]),26);
        bufp->chgIData(oldp+217,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[2]),26);
        bufp->chgIData(oldp+218,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[3]),26);
        bufp->chgIData(oldp+219,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[4]),26);
        bufp->chgIData(oldp+220,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[5]),26);
        bufp->chgIData(oldp+221,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[6]),26);
        bufp->chgIData(oldp+222,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_real_1[7]),26);
        bufp->chgIData(oldp+223,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[0]),26);
        bufp->chgIData(oldp+224,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[1]),26);
        bufp->chgIData(oldp+225,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[2]),26);
        bufp->chgIData(oldp+226,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[3]),26);
        bufp->chgIData(oldp+227,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[4]),26);
        bufp->chgIData(oldp+228,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[5]),26);
        bufp->chgIData(oldp+229,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[6]),26);
        bufp->chgIData(oldp+230,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_0[7]),26);
        bufp->chgIData(oldp+231,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[0]),26);
        bufp->chgIData(oldp+232,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[1]),26);
        bufp->chgIData(oldp+233,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[2]),26);
        bufp->chgIData(oldp+234,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[3]),26);
        bufp->chgIData(oldp+235,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[4]),26);
        bufp->chgIData(oldp+236,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[5]),26);
        bufp->chgIData(oldp+237,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[6]),26);
        bufp->chgIData(oldp+238,(vlSelf->tb_radix2_top__DOT__dut__DOT__stage_output_imag_1[7]),26);
        bufp->chgBit(oldp+239,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_en));
        bufp->chgIData(oldp+240,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_0),26);
        bufp->chgIData(oldp+241,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_1),26);
        bufp->chgIData(oldp+242,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_0),26);
        bufp->chgIData(oldp+243,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_1),26);
        bufp->chgIData(oldp+244,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y0_re),26);
        bufp->chgIData(oldp+245,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y0_im),26);
        bufp->chgIData(oldp+246,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y1_re),26);
        bufp->chgIData(oldp+247,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__y1_im),26);
        bufp->chgBit(oldp+248,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__butterfly_out_ready));
        bufp->chgQData(oldp+249,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
        bufp->chgQData(oldp+251,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
        bufp->chgIData(oldp+253,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
        bufp->chgIData(oldp+254,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
        bufp->chgIData(oldp+255,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
        bufp->chgIData(oldp+256,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
        bufp->chgIData(oldp+257,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
        bufp->chgIData(oldp+258,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
        bufp->chgIData(oldp+259,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
        bufp->chgIData(oldp+260,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
        bufp->chgCData(oldp+261,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
        bufp->chgIData(oldp+262,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
        bufp->chgIData(oldp+263,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
        bufp->chgSData(oldp+264,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
        bufp->chgSData(oldp+265,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
        bufp->chgQData(oldp+266,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
        bufp->chgQData(oldp+268,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
        bufp->chgIData(oldp+270,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
        bufp->chgSData(oldp+271,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
        bufp->chgSData(oldp+272,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
        bufp->chgQData(oldp+273,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
        bufp->chgQData(oldp+275,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
        bufp->chgQData(oldp+277,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
        bufp->chgQData(oldp+279,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__0__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
        bufp->chgBit(oldp+281,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_en));
        bufp->chgIData(oldp+282,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_0),26);
        bufp->chgIData(oldp+283,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_1),26);
        bufp->chgIData(oldp+284,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_0),26);
        bufp->chgIData(oldp+285,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_1),26);
        bufp->chgBit(oldp+286,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter));
        bufp->chgBit(oldp+287,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter));
        bufp->chgCData(oldp+288,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__flush_counter),7);
        bufp->chgBit(oldp+289,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
        bufp->chgCData(oldp+290,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
        bufp->chgIData(oldp+291,(((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter)
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                  [1U] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [0U])),26);
        bufp->chgIData(oldp+292,(((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter)
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                  [1U] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [0U])),26);
        bufp->chgIData(oldp+293,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y0_re),26);
        bufp->chgIData(oldp+294,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y0_im),26);
        bufp->chgIData(oldp+295,(((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter)
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [0U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+296,(((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_op_counter)
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [0U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+297,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y1_re),26);
        bufp->chgIData(oldp+298,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__y1_im),26);
        bufp->chgIData(oldp+299,(((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter)
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+300,(((IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__stride_segment_counter)
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__0__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+301,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                 [0U]),26);
        bufp->chgIData(oldp+302,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                 [0U]),26);
        bufp->chgIData(oldp+303,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                 [1U]),26);
        bufp->chgIData(oldp+304,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                 [1U]),26);
        bufp->chgBit(oldp+305,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__butterfly_out_ready));
        bufp->chgQData(oldp+306,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
        bufp->chgQData(oldp+308,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
        bufp->chgIData(oldp+310,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
        bufp->chgIData(oldp+311,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
        bufp->chgIData(oldp+312,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
        bufp->chgIData(oldp+313,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
        bufp->chgIData(oldp+314,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
        bufp->chgIData(oldp+315,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
        bufp->chgIData(oldp+316,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
        bufp->chgIData(oldp+317,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
        bufp->chgCData(oldp+318,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
        bufp->chgIData(oldp+319,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
        bufp->chgIData(oldp+320,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
        bufp->chgSData(oldp+321,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
        bufp->chgSData(oldp+322,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
        bufp->chgQData(oldp+323,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
        bufp->chgQData(oldp+325,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
        bufp->chgIData(oldp+327,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
        bufp->chgSData(oldp+328,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
        bufp->chgSData(oldp+329,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
        bufp->chgQData(oldp+330,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
        bufp->chgQData(oldp+332,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
        bufp->chgQData(oldp+334,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
        bufp->chgQData(oldp+336,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
        bufp->chgIData(oldp+338,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0]),26);
        bufp->chgIData(oldp+339,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0]),26);
        bufp->chgIData(oldp+340,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0]),26);
        bufp->chgIData(oldp+341,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1]),26);
        bufp->chgIData(oldp+342,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0]),26);
        bufp->chgIData(oldp+343,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__1__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1]),26);
        bufp->chgBit(oldp+344,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_en));
        bufp->chgIData(oldp+345,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_0),26);
        bufp->chgIData(oldp+346,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_1),26);
        bufp->chgIData(oldp+347,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_0),26);
        bufp->chgIData(oldp+348,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_1),26);
        bufp->chgCData(oldp+349,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter),2);
        bufp->chgCData(oldp+350,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter),2);
        bufp->chgCData(oldp+351,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__flush_counter),7);
        bufp->chgBit(oldp+352,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
        bufp->chgCData(oldp+353,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
        bufp->chgIData(oldp+354,(((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                  [3U] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [1U])),26);
        bufp->chgIData(oldp+355,(((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                  [3U] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [1U])),26);
        bufp->chgIData(oldp+356,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y0_re),26);
        bufp->chgIData(oldp+357,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y0_im),26);
        bufp->chgIData(oldp+358,(((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [1U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+359,(((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [1U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+360,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y1_re),26);
        bufp->chgIData(oldp+361,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__y1_im),26);
        bufp->chgIData(oldp+362,(((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+363,(((2U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__1__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+364,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                 [1U]),26);
        bufp->chgIData(oldp+365,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                 [1U]),26);
        bufp->chgIData(oldp+366,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                 [3U]),26);
        bufp->chgIData(oldp+367,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                 [3U]),26);
        bufp->chgBit(oldp+368,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__butterfly_out_ready));
        bufp->chgQData(oldp+369,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
        bufp->chgQData(oldp+371,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
        bufp->chgIData(oldp+373,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
        bufp->chgIData(oldp+374,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
        bufp->chgIData(oldp+375,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
        bufp->chgIData(oldp+376,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
        bufp->chgIData(oldp+377,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
        bufp->chgIData(oldp+378,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
        bufp->chgIData(oldp+379,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
        bufp->chgIData(oldp+380,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
        bufp->chgCData(oldp+381,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
        bufp->chgIData(oldp+382,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
        bufp->chgIData(oldp+383,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
        bufp->chgSData(oldp+384,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
        bufp->chgSData(oldp+385,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
        bufp->chgQData(oldp+386,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
        bufp->chgQData(oldp+388,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
        bufp->chgIData(oldp+390,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
        bufp->chgSData(oldp+391,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
        bufp->chgSData(oldp+392,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
        bufp->chgQData(oldp+393,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
        bufp->chgQData(oldp+395,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
        bufp->chgQData(oldp+397,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
        bufp->chgQData(oldp+399,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
        bufp->chgIData(oldp+401,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0]),26);
        bufp->chgIData(oldp+402,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1]),26);
        bufp->chgIData(oldp+403,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0]),26);
        bufp->chgIData(oldp+404,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1]),26);
        bufp->chgIData(oldp+405,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0]),26);
        bufp->chgIData(oldp+406,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1]),26);
        bufp->chgIData(oldp+407,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2]),26);
        bufp->chgIData(oldp+408,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3]),26);
        bufp->chgIData(oldp+409,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0]),26);
        bufp->chgIData(oldp+410,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1]),26);
        bufp->chgIData(oldp+411,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2]),26);
        bufp->chgIData(oldp+412,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__2__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3]),26);
        bufp->chgBit(oldp+413,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_en));
        bufp->chgIData(oldp+414,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_0),26);
        bufp->chgIData(oldp+415,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_1),26);
        bufp->chgIData(oldp+416,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_0),26);
        bufp->chgIData(oldp+417,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_1),26);
        bufp->chgCData(oldp+418,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter),3);
        bufp->chgCData(oldp+419,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter),3);
        bufp->chgCData(oldp+420,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__flush_counter),7);
        bufp->chgBit(oldp+421,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
        bufp->chgCData(oldp+422,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
        bufp->chgIData(oldp+423,(((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                  [7U] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [3U])),26);
        bufp->chgIData(oldp+424,(((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                  [7U] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [3U])),26);
        bufp->chgIData(oldp+425,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y0_re),26);
        bufp->chgIData(oldp+426,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y0_im),26);
        bufp->chgIData(oldp+427,(((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [3U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+428,(((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [3U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+429,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y1_re),26);
        bufp->chgIData(oldp+430,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__y1_im),26);
        bufp->chgIData(oldp+431,(((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+432,(((4U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__2__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+433,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                 [3U]),26);
        bufp->chgIData(oldp+434,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                 [3U]),26);
        bufp->chgIData(oldp+435,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                 [7U]),26);
        bufp->chgIData(oldp+436,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                 [7U]),26);
        bufp->chgBit(oldp+437,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__butterfly_out_ready));
        bufp->chgQData(oldp+438,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
        bufp->chgQData(oldp+440,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
        bufp->chgIData(oldp+442,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
        bufp->chgIData(oldp+443,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
        bufp->chgIData(oldp+444,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
        bufp->chgIData(oldp+445,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
        bufp->chgIData(oldp+446,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
        bufp->chgIData(oldp+447,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
        bufp->chgIData(oldp+448,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
        bufp->chgIData(oldp+449,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
        bufp->chgCData(oldp+450,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
        bufp->chgIData(oldp+451,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
        bufp->chgIData(oldp+452,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
        bufp->chgSData(oldp+453,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
        bufp->chgSData(oldp+454,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
        bufp->chgQData(oldp+455,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
        bufp->chgQData(oldp+457,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
        bufp->chgIData(oldp+459,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
        bufp->chgSData(oldp+460,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
        bufp->chgSData(oldp+461,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
        bufp->chgQData(oldp+462,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
        bufp->chgQData(oldp+464,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
        bufp->chgQData(oldp+466,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
        bufp->chgQData(oldp+468,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
        bufp->chgIData(oldp+470,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0]),26);
        bufp->chgIData(oldp+471,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1]),26);
        bufp->chgIData(oldp+472,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[2]),26);
        bufp->chgIData(oldp+473,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[3]),26);
        bufp->chgIData(oldp+474,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0]),26);
        bufp->chgIData(oldp+475,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1]),26);
        bufp->chgIData(oldp+476,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[2]),26);
        bufp->chgIData(oldp+477,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[3]),26);
        bufp->chgIData(oldp+478,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0]),26);
        bufp->chgIData(oldp+479,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1]),26);
        bufp->chgIData(oldp+480,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2]),26);
        bufp->chgIData(oldp+481,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3]),26);
        bufp->chgIData(oldp+482,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[4]),26);
        bufp->chgIData(oldp+483,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[5]),26);
        bufp->chgIData(oldp+484,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[6]),26);
        bufp->chgIData(oldp+485,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[7]),26);
        bufp->chgIData(oldp+486,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0]),26);
        bufp->chgIData(oldp+487,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1]),26);
        bufp->chgIData(oldp+488,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2]),26);
        bufp->chgIData(oldp+489,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3]),26);
        bufp->chgIData(oldp+490,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[4]),26);
        bufp->chgIData(oldp+491,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[5]),26);
        bufp->chgIData(oldp+492,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[6]),26);
        bufp->chgIData(oldp+493,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__3__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[7]),26);
        bufp->chgBit(oldp+494,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_en));
        bufp->chgIData(oldp+495,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_0),26);
        bufp->chgIData(oldp+496,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_1),26);
        bufp->chgIData(oldp+497,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_0),26);
        bufp->chgIData(oldp+498,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_1),26);
        bufp->chgCData(oldp+499,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter),4);
        bufp->chgCData(oldp+500,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter),4);
        bufp->chgCData(oldp+501,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__flush_counter),7);
        bufp->chgBit(oldp+502,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
        bufp->chgCData(oldp+503,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
        bufp->chgIData(oldp+504,(((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                  [0xfU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [7U])),26);
        bufp->chgIData(oldp+505,(((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                  [0xfU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [7U])),26);
        bufp->chgIData(oldp+506,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y0_re),26);
        bufp->chgIData(oldp+507,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y0_im),26);
        bufp->chgIData(oldp+508,(((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [7U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+509,(((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [7U] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+510,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y1_re),26);
        bufp->chgIData(oldp+511,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__y1_im),26);
        bufp->chgIData(oldp+512,(((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+513,(((8U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__3__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+514,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                 [7U]),26);
        bufp->chgIData(oldp+515,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                 [7U]),26);
        bufp->chgIData(oldp+516,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                 [0xfU]),26);
        bufp->chgIData(oldp+517,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                 [0xfU]),26);
        bufp->chgBit(oldp+518,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__butterfly_out_ready));
        bufp->chgQData(oldp+519,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
        bufp->chgQData(oldp+521,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
        bufp->chgIData(oldp+523,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
        bufp->chgIData(oldp+524,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
        bufp->chgIData(oldp+525,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
        bufp->chgIData(oldp+526,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
        bufp->chgIData(oldp+527,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
        bufp->chgIData(oldp+528,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
        bufp->chgIData(oldp+529,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
        bufp->chgIData(oldp+530,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
        bufp->chgCData(oldp+531,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
        bufp->chgIData(oldp+532,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
        bufp->chgIData(oldp+533,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
        bufp->chgSData(oldp+534,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
        bufp->chgSData(oldp+535,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
        bufp->chgQData(oldp+536,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
        bufp->chgQData(oldp+538,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
        bufp->chgIData(oldp+540,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
        bufp->chgSData(oldp+541,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
        bufp->chgSData(oldp+542,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
        bufp->chgQData(oldp+543,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
        bufp->chgQData(oldp+545,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
        bufp->chgQData(oldp+547,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
        bufp->chgQData(oldp+549,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
        bufp->chgIData(oldp+551,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0]),26);
        bufp->chgIData(oldp+552,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1]),26);
        bufp->chgIData(oldp+553,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[2]),26);
        bufp->chgIData(oldp+554,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[3]),26);
        bufp->chgIData(oldp+555,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[4]),26);
        bufp->chgIData(oldp+556,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[5]),26);
        bufp->chgIData(oldp+557,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[6]),26);
        bufp->chgIData(oldp+558,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[7]),26);
        bufp->chgIData(oldp+559,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0]),26);
        bufp->chgIData(oldp+560,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1]),26);
        bufp->chgIData(oldp+561,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[2]),26);
        bufp->chgIData(oldp+562,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[3]),26);
        bufp->chgIData(oldp+563,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[4]),26);
        bufp->chgIData(oldp+564,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[5]),26);
        bufp->chgIData(oldp+565,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[6]),26);
        bufp->chgIData(oldp+566,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[7]),26);
        bufp->chgIData(oldp+567,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0]),26);
        bufp->chgIData(oldp+568,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1]),26);
        bufp->chgIData(oldp+569,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2]),26);
        bufp->chgIData(oldp+570,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3]),26);
        bufp->chgIData(oldp+571,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[4]),26);
        bufp->chgIData(oldp+572,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[5]),26);
        bufp->chgIData(oldp+573,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[6]),26);
        bufp->chgIData(oldp+574,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[7]),26);
        bufp->chgIData(oldp+575,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[8]),26);
        bufp->chgIData(oldp+576,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[9]),26);
        bufp->chgIData(oldp+577,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[10]),26);
        bufp->chgIData(oldp+578,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[11]),26);
        bufp->chgIData(oldp+579,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[12]),26);
        bufp->chgIData(oldp+580,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[13]),26);
        bufp->chgIData(oldp+581,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[14]),26);
        bufp->chgIData(oldp+582,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[15]),26);
        bufp->chgIData(oldp+583,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0]),26);
        bufp->chgIData(oldp+584,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1]),26);
        bufp->chgIData(oldp+585,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2]),26);
        bufp->chgIData(oldp+586,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3]),26);
        bufp->chgIData(oldp+587,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[4]),26);
        bufp->chgIData(oldp+588,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[5]),26);
        bufp->chgIData(oldp+589,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[6]),26);
        bufp->chgIData(oldp+590,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[7]),26);
        bufp->chgIData(oldp+591,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[8]),26);
        bufp->chgIData(oldp+592,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[9]),26);
        bufp->chgIData(oldp+593,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[10]),26);
        bufp->chgIData(oldp+594,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[11]),26);
        bufp->chgIData(oldp+595,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[12]),26);
        bufp->chgIData(oldp+596,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[13]),26);
        bufp->chgIData(oldp+597,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[14]),26);
        bufp->chgIData(oldp+598,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__4__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[15]),26);
        bufp->chgBit(oldp+599,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_en));
        bufp->chgIData(oldp+600,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_0),26);
        bufp->chgIData(oldp+601,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_1),26);
        bufp->chgIData(oldp+602,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_0),26);
        bufp->chgIData(oldp+603,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_1),26);
        bufp->chgCData(oldp+604,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter),5);
        bufp->chgCData(oldp+605,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter),5);
        bufp->chgCData(oldp+606,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__flush_counter),7);
        bufp->chgBit(oldp+607,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
        bufp->chgCData(oldp+608,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
        bufp->chgIData(oldp+609,(((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                  [0x1fU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [0xfU])),26);
        bufp->chgIData(oldp+610,(((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                  [0x1fU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [0xfU])),26);
        bufp->chgIData(oldp+611,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y0_re),26);
        bufp->chgIData(oldp+612,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y0_im),26);
        bufp->chgIData(oldp+613,(((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [0xfU] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+614,(((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [0xfU] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+615,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y1_re),26);
        bufp->chgIData(oldp+616,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__y1_im),26);
        bufp->chgIData(oldp+617,(((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+618,(((0x10U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__4__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+619,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                 [0xfU]),26);
        bufp->chgIData(oldp+620,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                 [0xfU]),26);
        bufp->chgIData(oldp+621,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                 [0x1fU]),26);
        bufp->chgIData(oldp+622,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                 [0x1fU]),26);
        bufp->chgBit(oldp+623,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__butterfly_out_ready));
        bufp->chgQData(oldp+624,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
        bufp->chgQData(oldp+626,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
        bufp->chgIData(oldp+628,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
        bufp->chgIData(oldp+629,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
        bufp->chgIData(oldp+630,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
        bufp->chgIData(oldp+631,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
        bufp->chgIData(oldp+632,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
        bufp->chgIData(oldp+633,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
        bufp->chgIData(oldp+634,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
        bufp->chgIData(oldp+635,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
        bufp->chgCData(oldp+636,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
        bufp->chgIData(oldp+637,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
        bufp->chgIData(oldp+638,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
        bufp->chgSData(oldp+639,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
        bufp->chgSData(oldp+640,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
        bufp->chgQData(oldp+641,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
        bufp->chgQData(oldp+643,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
        bufp->chgIData(oldp+645,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
        bufp->chgSData(oldp+646,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
        bufp->chgSData(oldp+647,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
        bufp->chgQData(oldp+648,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
        bufp->chgQData(oldp+650,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
        bufp->chgQData(oldp+652,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
        bufp->chgQData(oldp+654,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
        bufp->chgIData(oldp+656,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0]),26);
        bufp->chgIData(oldp+657,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1]),26);
        bufp->chgIData(oldp+658,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[2]),26);
        bufp->chgIData(oldp+659,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[3]),26);
        bufp->chgIData(oldp+660,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[4]),26);
        bufp->chgIData(oldp+661,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[5]),26);
        bufp->chgIData(oldp+662,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[6]),26);
        bufp->chgIData(oldp+663,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[7]),26);
        bufp->chgIData(oldp+664,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[8]),26);
        bufp->chgIData(oldp+665,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[9]),26);
        bufp->chgIData(oldp+666,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[10]),26);
        bufp->chgIData(oldp+667,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[11]),26);
        bufp->chgIData(oldp+668,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[12]),26);
        bufp->chgIData(oldp+669,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[13]),26);
        bufp->chgIData(oldp+670,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[14]),26);
        bufp->chgIData(oldp+671,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[15]),26);
        bufp->chgIData(oldp+672,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0]),26);
        bufp->chgIData(oldp+673,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1]),26);
        bufp->chgIData(oldp+674,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[2]),26);
        bufp->chgIData(oldp+675,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[3]),26);
        bufp->chgIData(oldp+676,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[4]),26);
        bufp->chgIData(oldp+677,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[5]),26);
        bufp->chgIData(oldp+678,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[6]),26);
        bufp->chgIData(oldp+679,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[7]),26);
        bufp->chgIData(oldp+680,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[8]),26);
        bufp->chgIData(oldp+681,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[9]),26);
        bufp->chgIData(oldp+682,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[10]),26);
        bufp->chgIData(oldp+683,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[11]),26);
        bufp->chgIData(oldp+684,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[12]),26);
        bufp->chgIData(oldp+685,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[13]),26);
        bufp->chgIData(oldp+686,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[14]),26);
        bufp->chgIData(oldp+687,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[15]),26);
        bufp->chgIData(oldp+688,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[0]),26);
        bufp->chgIData(oldp+689,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[1]),26);
        bufp->chgIData(oldp+690,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[2]),26);
        bufp->chgIData(oldp+691,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[3]),26);
        bufp->chgIData(oldp+692,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[4]),26);
        bufp->chgIData(oldp+693,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[5]),26);
        bufp->chgIData(oldp+694,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[6]),26);
        bufp->chgIData(oldp+695,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[7]),26);
        bufp->chgIData(oldp+696,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[8]),26);
        bufp->chgIData(oldp+697,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[9]),26);
        bufp->chgIData(oldp+698,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[10]),26);
        bufp->chgIData(oldp+699,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[11]),26);
        bufp->chgIData(oldp+700,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[12]),26);
        bufp->chgIData(oldp+701,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[13]),26);
        bufp->chgIData(oldp+702,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[14]),26);
        bufp->chgIData(oldp+703,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[15]),26);
        bufp->chgIData(oldp+704,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[16]),26);
        bufp->chgIData(oldp+705,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[17]),26);
        bufp->chgIData(oldp+706,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[18]),26);
        bufp->chgIData(oldp+707,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[19]),26);
        bufp->chgIData(oldp+708,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[20]),26);
        bufp->chgIData(oldp+709,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[21]),26);
        bufp->chgIData(oldp+710,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[22]),26);
        bufp->chgIData(oldp+711,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[23]),26);
        bufp->chgIData(oldp+712,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[24]),26);
        bufp->chgIData(oldp+713,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[25]),26);
        bufp->chgIData(oldp+714,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[26]),26);
        bufp->chgIData(oldp+715,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[27]),26);
        bufp->chgIData(oldp+716,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[28]),26);
        bufp->chgIData(oldp+717,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[29]),26);
        bufp->chgIData(oldp+718,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[30]),26);
        bufp->chgIData(oldp+719,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re[31]),26);
        bufp->chgIData(oldp+720,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[0]),26);
        bufp->chgIData(oldp+721,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[1]),26);
        bufp->chgIData(oldp+722,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[2]),26);
        bufp->chgIData(oldp+723,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[3]),26);
        bufp->chgIData(oldp+724,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[4]),26);
        bufp->chgIData(oldp+725,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[5]),26);
        bufp->chgIData(oldp+726,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[6]),26);
        bufp->chgIData(oldp+727,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[7]),26);
        bufp->chgIData(oldp+728,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[8]),26);
        bufp->chgIData(oldp+729,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[9]),26);
        bufp->chgIData(oldp+730,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[10]),26);
        bufp->chgIData(oldp+731,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[11]),26);
        bufp->chgIData(oldp+732,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[12]),26);
        bufp->chgIData(oldp+733,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[13]),26);
        bufp->chgIData(oldp+734,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[14]),26);
        bufp->chgIData(oldp+735,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[15]),26);
        bufp->chgIData(oldp+736,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[16]),26);
        bufp->chgIData(oldp+737,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[17]),26);
        bufp->chgIData(oldp+738,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[18]),26);
        bufp->chgIData(oldp+739,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[19]),26);
        bufp->chgIData(oldp+740,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[20]),26);
        bufp->chgIData(oldp+741,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[21]),26);
        bufp->chgIData(oldp+742,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[22]),26);
        bufp->chgIData(oldp+743,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[23]),26);
        bufp->chgIData(oldp+744,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[24]),26);
        bufp->chgIData(oldp+745,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[25]),26);
        bufp->chgIData(oldp+746,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[26]),26);
        bufp->chgIData(oldp+747,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[27]),26);
        bufp->chgIData(oldp+748,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[28]),26);
        bufp->chgIData(oldp+749,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[29]),26);
        bufp->chgIData(oldp+750,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[30]),26);
        bufp->chgIData(oldp+751,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__5__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im[31]),26);
        bufp->chgBit(oldp+752,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_en));
        bufp->chgIData(oldp+753,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_0),26);
        bufp->chgIData(oldp+754,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_1),26);
        bufp->chgIData(oldp+755,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_0),26);
        bufp->chgIData(oldp+756,(vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_1),26);
        bufp->chgCData(oldp+757,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter),6);
        bufp->chgCData(oldp+758,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter),6);
        bufp->chgCData(oldp+759,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__flush_counter),7);
        bufp->chgBit(oldp+760,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
        bufp->chgCData(oldp+761,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
        bufp->chgIData(oldp+762,(((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                  [0x3fU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [0x1fU])),26);
        bufp->chgIData(oldp+763,(((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                  [0x3fU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [0x1fU])),26);
        bufp->chgIData(oldp+764,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y0_re),26);
        bufp->chgIData(oldp+765,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y0_im),26);
        bufp->chgIData(oldp+766,(((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [0x1fU] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+767,(((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [0x1fU] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+768,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y1_re),26);
        bufp->chgIData(oldp+769,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__y1_im),26);
        bufp->chgIData(oldp+770,(((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+771,(((0x20U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__5__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+772,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                 [0x1fU]),26);
        bufp->chgIData(oldp+773,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                 [0x1fU]),26);
        bufp->chgIData(oldp+774,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                 [0x3fU]),26);
        bufp->chgIData(oldp+775,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                 [0x3fU]),26);
        bufp->chgBit(oldp+776,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__butterfly_out_ready));
        bufp->chgQData(oldp+777,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
        bufp->chgQData(oldp+779,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
        bufp->chgIData(oldp+781,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
        bufp->chgIData(oldp+782,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
        bufp->chgIData(oldp+783,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
        bufp->chgIData(oldp+784,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
        bufp->chgIData(oldp+785,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
        bufp->chgIData(oldp+786,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
        bufp->chgIData(oldp+787,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
        bufp->chgIData(oldp+788,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
        bufp->chgCData(oldp+789,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
        bufp->chgIData(oldp+790,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
        bufp->chgIData(oldp+791,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
        bufp->chgSData(oldp+792,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
        bufp->chgSData(oldp+793,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
        bufp->chgQData(oldp+794,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
        bufp->chgQData(oldp+796,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
        bufp->chgIData(oldp+798,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
        bufp->chgSData(oldp+799,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
        bufp->chgSData(oldp+800,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
        bufp->chgQData(oldp+801,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
        bufp->chgQData(oldp+803,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
        bufp->chgQData(oldp+805,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
        bufp->chgQData(oldp+807,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
        bufp->chgIData(oldp+809,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[0]),26);
        bufp->chgIData(oldp+810,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[1]),26);
        bufp->chgIData(oldp+811,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[2]),26);
        bufp->chgIData(oldp+812,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[3]),26);
        bufp->chgIData(oldp+813,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[4]),26);
        bufp->chgIData(oldp+814,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[5]),26);
        bufp->chgIData(oldp+815,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[6]),26);
        bufp->chgIData(oldp+816,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[7]),26);
        bufp->chgIData(oldp+817,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[8]),26);
        bufp->chgIData(oldp+818,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[9]),26);
        bufp->chgIData(oldp+819,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[10]),26);
        bufp->chgIData(oldp+820,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[11]),26);
        bufp->chgIData(oldp+821,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[12]),26);
        bufp->chgIData(oldp+822,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[13]),26);
        bufp->chgIData(oldp+823,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[14]),26);
        bufp->chgIData(oldp+824,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[15]),26);
        bufp->chgIData(oldp+825,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[16]),26);
        bufp->chgIData(oldp+826,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[17]),26);
        bufp->chgIData(oldp+827,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[18]),26);
        bufp->chgIData(oldp+828,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[19]),26);
        bufp->chgIData(oldp+829,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[20]),26);
        bufp->chgIData(oldp+830,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[21]),26);
        bufp->chgIData(oldp+831,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[22]),26);
        bufp->chgIData(oldp+832,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[23]),26);
        bufp->chgIData(oldp+833,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[24]),26);
        bufp->chgIData(oldp+834,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[25]),26);
        bufp->chgIData(oldp+835,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[26]),26);
        bufp->chgIData(oldp+836,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[27]),26);
        bufp->chgIData(oldp+837,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[28]),26);
        bufp->chgIData(oldp+838,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[29]),26);
        bufp->chgIData(oldp+839,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[30]),26);
        bufp->chgIData(oldp+840,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re[31]),26);
        bufp->chgIData(oldp+841,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[0]),26);
        bufp->chgIData(oldp+842,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[1]),26);
        bufp->chgIData(oldp+843,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[2]),26);
        bufp->chgIData(oldp+844,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[3]),26);
        bufp->chgIData(oldp+845,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[4]),26);
        bufp->chgIData(oldp+846,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[5]),26);
        bufp->chgIData(oldp+847,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[6]),26);
        bufp->chgIData(oldp+848,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[7]),26);
        bufp->chgIData(oldp+849,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[8]),26);
        bufp->chgIData(oldp+850,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[9]),26);
        bufp->chgIData(oldp+851,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[10]),26);
        bufp->chgIData(oldp+852,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[11]),26);
        bufp->chgIData(oldp+853,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[12]),26);
        bufp->chgIData(oldp+854,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[13]),26);
        bufp->chgIData(oldp+855,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[14]),26);
        bufp->chgIData(oldp+856,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[15]),26);
        bufp->chgIData(oldp+857,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[16]),26);
        bufp->chgIData(oldp+858,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[17]),26);
        bufp->chgIData(oldp+859,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[18]),26);
        bufp->chgIData(oldp+860,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[19]),26);
        bufp->chgIData(oldp+861,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[20]),26);
        bufp->chgIData(oldp+862,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[21]),26);
        bufp->chgIData(oldp+863,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[22]),26);
        bufp->chgIData(oldp+864,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[23]),26);
        bufp->chgIData(oldp+865,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[24]),26);
        bufp->chgIData(oldp+866,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[25]),26);
        bufp->chgIData(oldp+867,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[26]),26);
        bufp->chgIData(oldp+868,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[27]),26);
        bufp->chgIData(oldp+869,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[28]),26);
        bufp->chgIData(oldp+870,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[29]),26);
        bufp->chgIData(oldp+871,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[30]),26);
        bufp->chgIData(oldp+872,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__6__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im[31]),26);
        bufp->chgCData(oldp+873,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter),7);
        bufp->chgCData(oldp+874,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter),7);
        bufp->chgCData(oldp+875,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__flush_counter),7);
        bufp->chgBit(oldp+876,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter_en));
        bufp->chgCData(oldp+877,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter),8);
        bufp->chgIData(oldp+878,(((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                  [0x7fU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [0x3fU])),26);
        bufp->chgIData(oldp+879,(((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                  [0x7fU] : vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [0x3fU])),26);
        bufp->chgIData(oldp+880,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y0_re),26);
        bufp->chgIData(oldp+881,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y0_im),26);
        bufp->chgIData(oldp+882,(((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                  [0x3fU] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+883,(((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_op_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                  [0x3fU] : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+884,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y1_re),26);
        bufp->chgIData(oldp+885,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__y1_im),26);
        bufp->chgIData(oldp+886,(((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_real_0)),26);
        bufp->chgIData(oldp+887,(((0x40U & (IData)(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__stride_segment_counter))
                                   ? vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_1
                                   : vlSelf->tb_radix2_top__DOT__dut__DOT____Vcellout__gen_stages__BRA__6__KET____DOT__stage_inst__output_imag_0)),26);
        bufp->chgIData(oldp+888,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_re
                                 [0x3fU]),26);
        bufp->chgIData(oldp+889,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db0__DOT__buf_im
                                 [0x3fU]),26);
        bufp->chgIData(oldp+890,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_re
                                 [0x7fU]),26);
        bufp->chgIData(oldp+891,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__gen_delay_buffers__DOT__db1__DOT__buf_im
                                 [0x7fU]),26);
        bufp->chgBit(oldp+892,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__butterfly_out_ready));
        bufp->chgQData(oldp+893,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__mr_full),39);
        bufp->chgQData(oldp+895,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__mi_full),39);
        bufp->chgIData(oldp+897,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ar_d0),26);
        bufp->chgIData(oldp+898,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ai_d0),26);
        bufp->chgIData(oldp+899,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ar_d1),26);
        bufp->chgIData(oldp+900,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ai_d1),26);
        bufp->chgIData(oldp+901,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ar_d2),26);
        bufp->chgIData(oldp+902,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ai_d2),26);
        bufp->chgIData(oldp+903,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ar_d3),26);
        bufp->chgIData(oldp+904,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__ai_d3),26);
        bufp->chgCData(oldp+905,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__valid_pipe),4);
        bufp->chgIData(oldp+906,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xr_s0),26);
        bufp->chgIData(oldp+907,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s0),26);
        bufp->chgSData(oldp+908,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s0),13);
        bufp->chgSData(oldp+909,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s0),13);
        bufp->chgQData(oldp+910,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s1),39);
        bufp->chgQData(oldp+912,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s1),39);
        bufp->chgIData(oldp+914,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__xi_s1),26);
        bufp->chgSData(oldp+915,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wr_s1),13);
        bufp->chgSData(oldp+916,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__wi_s1),13);
        bufp->chgQData(oldp+917,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_a_s2),39);
        bufp->chgQData(oldp+919,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_a_s2),39);
        bufp->chgQData(oldp+921,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__real_prod_b_s2),39);
        bufp->chgQData(oldp+923,(vlSelf->tb_radix2_top__DOT__dut__DOT__gen_stages__BRA__7__KET____DOT__stage_inst__DOT__b0__DOT__u_cmul__DOT__imag_prod_b_s2),39);
    }
    bufp->chgBit(oldp+925,(vlSelf->tb_radix2_top__DOT__clock));
}

void Vtb_radix2_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_radix2_top___024root__trace_cleanup\n"); );
    // Init
    Vtb_radix2_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_radix2_top___024root*>(voidSelf);
    Vtb_radix2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
