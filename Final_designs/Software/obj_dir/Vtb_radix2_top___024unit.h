// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_radix2_top.h for the primary calling header

#ifndef VERILATED_VTB_RADIX2_TOP___024UNIT_H_
#define VERILATED_VTB_RADIX2_TOP___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_radix2_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_radix2_top___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtb_radix2_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_radix2_top___024unit(Vtb_radix2_top__Syms* symsp, const char* v__name);
    ~Vtb_radix2_top___024unit();
    VL_UNCOPYABLE(Vtb_radix2_top___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
