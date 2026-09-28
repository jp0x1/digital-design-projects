// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfibonacci_test.h for the primary calling header

#include "Vfibonacci_test__pch.h"

void Vfibonacci_test___024root___timing_ready(Vfibonacci_test___024root* vlSelf);

VL_ATTR_COLD void Vfibonacci_test___024root___eval_static(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___eval_static\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (1ULL | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (2ULL | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__DUT__DOT__f_n1__0 
        = vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1;
    vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__f_test__0 
        = vlSelfRef.fibonacci_test__DOT__f_test;
    vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__clk__0 
        = vlSelfRef.fibonacci_test__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__rst_n__0 
        = vlSelfRef.fibonacci_test__DOT__rst_n;
    Vfibonacci_test___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vfibonacci_test___024root___eval_final(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___eval_final\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vfibonacci_test___024root___eval_settle(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___eval_settle\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vfibonacci_test___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfibonacci_test___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vfibonacci_test___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( fibonacci_test.DUT.f_n1)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( fibonacci_test.f_test)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge fibonacci_test.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(negedge fibonacci_test.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfibonacci_test___024root___ctor_var_reset(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___ctor_var_reset\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->fibonacci_test__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14722914717052762457ull);
    vlSelf->fibonacci_test__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8911136127116206819ull);
    vlSelf->fibonacci_test__DOT__f_test = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13200099230573212080ull);
    vlSelf->fibonacci_test__DOT__DUT__DOT__n = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9938293254671555029ull);
    vlSelf->fibonacci_test__DOT__DUT__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15867832839417948217ull);
    vlSelf->fibonacci_test__DOT__DUT__DOT__f_n1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4254773941282297389ull);
    vlSelf->fibonacci_test__DOT__DUT__DOT__f_n2 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16898054816026111975ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__fibonacci_test__DOT__DUT__DOT__f_n1__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__fibonacci_test__DOT__f_test__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__fibonacci_test__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__fibonacci_test__DOT__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
