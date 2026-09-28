// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfibonacci_test.h for the primary calling header

#ifndef VERILATED_VFIBONACCI_TEST___024UNIT_H_
#define VERILATED_VFIBONACCI_TEST___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vfibonacci_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfibonacci_test___024unit final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __VmonitorOff;
    QData/*63:0*/ __VmonitorNum;

    // INTERNAL VARIABLES
    Vfibonacci_test__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vfibonacci_test___024unit();
    ~Vfibonacci_test___024unit();
    void ctor(Vfibonacci_test__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vfibonacci_test___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
