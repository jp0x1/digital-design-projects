// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfibonacci_test.h for the primary calling header

#ifndef VERILATED_VFIBONACCI_TEST___024ROOT_H_
#define VERILATED_VFIBONACCI_TEST___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vfibonacci_test___024unit;


class Vfibonacci_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfibonacci_test___024root final {
  public:
    // CELLS
    Vfibonacci_test___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ fibonacci_test__DOT__clk;
    CData/*0:0*/ fibonacci_test__DOT__rst_n;
    CData/*4:0*/ fibonacci_test__DOT__DUT__DOT__n;
    CData/*1:0*/ fibonacci_test__DOT__DUT__DOT__state;
    CData/*0:0*/ __Vtrigprevexpr___TOP__fibonacci_test__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__fibonacci_test__DOT__rst_n__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    SData/*15:0*/ fibonacci_test__DOT__f_test;
    SData/*15:0*/ fibonacci_test__DOT__DUT__DOT__f_n1;
    SData/*15:0*/ fibonacci_test__DOT__DUT__DOT__f_n2;
    SData/*15:0*/ __Vtrigprevexpr___TOP__fibonacci_test__DOT__DUT__DOT__f_n1__0;
    SData/*15:0*/ __Vtrigprevexpr___TOP__fibonacci_test__DOT__f_test__0;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlTriggerScheduler __VtrigSched_h24cec110__0;
    VlDelayScheduler __VdlySched;

    // INTERNAL VARIABLES
    Vfibonacci_test__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vfibonacci_test___024root(Vfibonacci_test__Syms* symsp, const char* namep);
    ~Vfibonacci_test___024root();
    VL_UNCOPYABLE(Vfibonacci_test___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
