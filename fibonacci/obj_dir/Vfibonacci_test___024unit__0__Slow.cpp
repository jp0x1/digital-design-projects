// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfibonacci_test.h for the primary calling header

#include "Vfibonacci_test__pch.h"

VL_ATTR_COLD void Vfibonacci_test___024unit___ctor_var_reset(Vfibonacci_test___024unit* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vfibonacci_test___024unit___ctor_var_reset\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__VmonitorNum = 0;
    vlSelf->__VmonitorOff = 0;
}
