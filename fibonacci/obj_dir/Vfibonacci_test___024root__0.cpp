// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfibonacci_test.h for the primary calling header

#include "Vfibonacci_test__pch.h"

VlCoroutine Vfibonacci_test___024root___eval_initial__TOP__Vtiming__0(Vfibonacci_test___024root* vlSelf);
VlCoroutine Vfibonacci_test___024root___eval_initial__TOP__Vtiming__1(Vfibonacci_test___024root* vlSelf);

void Vfibonacci_test___024root___eval_initial(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___eval_initial\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vfibonacci_test___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vfibonacci_test___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vfibonacci_test___024root____VbeforeTrig_h24cec110__0(Vfibonacci_test___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vfibonacci_test___024root___eval_initial__TOP__Vtiming__0(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ fibonacci_test__DOT__i_test;
    fibonacci_test__DOT__i_test = 0;
    SData/*15:0*/ fibonacci_test__DOT__n1_fib_test;
    fibonacci_test__DOT__n1_fib_test = 0;
    SData/*15:0*/ fibonacci_test__DOT__n2_fib_test;
    fibonacci_test__DOT__n2_fib_test = 0;
    IData/*31:0*/ fibonacci_test__DOT__errors;
    fibonacci_test__DOT__errors = 0;
    IData/*31:0*/ fibonacci_test__DOT__unnamedblk1_1__DOT____Vrepeat0;
    fibonacci_test__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    // Body
    fibonacci_test__DOT__errors = 0U;
    vlSymsp->TOP____024unit.__VmonitorNum = 1U;
    vlSelfRef.fibonacci_test__DOT__rst_n = 0U;
    fibonacci_test__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    while (VL_LTS_III(32, 0U, fibonacci_test__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vfibonacci_test___024root____VbeforeTrig_h24cec110__0(vlSelf, 
                                                              "@(posedge fibonacci_test.clk)");
        co_await vlSelfRef.__VtrigSched_h24cec110__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge fibonacci_test.clk)", 
                                                             "fibonacci_test.sv", 
                                                             33);
        fibonacci_test__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (fibonacci_test__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "fibonacci_test.sv", 
                                         34);
    vlSelfRef.fibonacci_test__DOT__rst_n = 1U;
    fibonacci_test__DOT__n1_fib_test = 1U;
    fibonacci_test__DOT__n2_fib_test = 0U;
    vlSelfRef.fibonacci_test__DOT__f_test = 1U;
    Vfibonacci_test___024root____VbeforeTrig_h24cec110__0(vlSelf, 
                                                          "@(posedge fibonacci_test.clk)");
    co_await vlSelfRef.__VtrigSched_h24cec110__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge fibonacci_test.clk)", 
                                                         "fibonacci_test.sv", 
                                                         43);
    fibonacci_test__DOT__i_test = 1U;
    while ((0x13U >= (IData)(fibonacci_test__DOT__i_test))) {
        vlSelfRef.fibonacci_test__DOT__f_test = (0x0000ffffU 
                                                 & ((IData)(fibonacci_test__DOT__n1_fib_test) 
                                                    + (IData)(fibonacci_test__DOT__n2_fib_test)));
        fibonacci_test__DOT__n2_fib_test = fibonacci_test__DOT__n1_fib_test;
        fibonacci_test__DOT__n1_fib_test = vlSelfRef.fibonacci_test__DOT__f_test;
        Vfibonacci_test___024root____VbeforeTrig_h24cec110__0(vlSelf, 
                                                              "@(posedge fibonacci_test.clk)");
        co_await vlSelfRef.__VtrigSched_h24cec110__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge fibonacci_test.clk)", 
                                                             "fibonacci_test.sv", 
                                                             53);
        Vfibonacci_test___024root____VbeforeTrig_h24cec110__0(vlSelf, 
                                                              "@(posedge fibonacci_test.clk)");
        co_await vlSelfRef.__VtrigSched_h24cec110__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge fibonacci_test.clk)", 
                                                             "fibonacci_test.sv", 
                                                             54);
        co_await vlSelfRef.__VdlySched.delay(1ULL, 
                                             nullptr, 
                                             "fibonacci_test.sv", 
                                             55);
        if (((IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1) 
             != (IData)(vlSelfRef.fibonacci_test__DOT__f_test))) {
            VL_WRITEF_NX("[Time %0t] MISMATCH at Step %0d! Expected %0d, Got %0d\n",5, 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',5,(IData)(fibonacci_test__DOT__i_test)
                         , '#',16,vlSelfRef.fibonacci_test__DOT__f_test
                         , '#',16,(IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1));
            fibonacci_test__DOT__errors = ((IData)(1U) 
                                           + fibonacci_test__DOT__errors);
        } else {
            VL_WRITEF_NX("[Time %0t] MATCH Step %0d: F(%0d) = %0d\n",5, 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',5,(IData)(fibonacci_test__DOT__i_test)
                         , '#',32,((IData)(1U) + (IData)(fibonacci_test__DOT__i_test))
                         , '#',16,(IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1));
        }
        fibonacci_test__DOT__i_test = (0x0000001fU 
                                       & ((IData)(1U) 
                                          + (IData)(fibonacci_test__DOT__i_test)));
    }
    Vfibonacci_test___024root____VbeforeTrig_h24cec110__0(vlSelf, 
                                                          "@(posedge fibonacci_test.clk)");
    co_await vlSelfRef.__VtrigSched_h24cec110__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge fibonacci_test.clk)", 
                                                         "fibonacci_test.sv", 
                                                         68);
    Vfibonacci_test___024root____VbeforeTrig_h24cec110__0(vlSelf, 
                                                          "@(posedge fibonacci_test.clk)");
    co_await vlSelfRef.__VtrigSched_h24cec110__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge fibonacci_test.clk)", 
                                                         "fibonacci_test.sv", 
                                                         69);
    Vfibonacci_test___024root____VbeforeTrig_h24cec110__0(vlSelf, 
                                                          "@(posedge fibonacci_test.clk)");
    co_await vlSelfRef.__VtrigSched_h24cec110__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge fibonacci_test.clk)", 
                                                         "fibonacci_test.sv", 
                                                         70);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "fibonacci_test.sv", 
                                         71);
    if ((1U != (IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1))) {
        VL_WRITEF_NX("[Time %0t] Wrap-around failed! Expected f = 1 in START, Got %0d\n",3, 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',16,(IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1));
        fibonacci_test__DOT__errors = ((IData)(1U) 
                                       + fibonacci_test__DOT__errors);
    } else {
        VL_WRITEF_NX("[Time %0t] Wrap-around SUCCESS! Reset to f = %0d\n",3, 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',16,(IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1));
    }
    VL_WRITEF_NX("--------------------------------------------------\n",0);
    if ((0U == fibonacci_test__DOT__errors)) {
        VL_WRITEF_NX(">> ALL TESTS PASSED SUCCESSFULLY! (0 errors) <<\n",0);
    } else {
        VL_WRITEF_NX(">> SIMULATION FAILED with %0d error(s). <<\n",1
                     , '~',32,fibonacci_test__DOT__errors);
    }
    VL_WRITEF_NX("--------------------------------------------------\n",0);
    VL_FINISH_MT("fibonacci_test.sv", 88, "");
    co_return;
}

VlCoroutine Vfibonacci_test___024root___eval_initial__TOP__Vtiming__1(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.fibonacci_test__DOT__clk = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(0x000000000000000aULL, 
                                             nullptr, 
                                             "fibonacci_test.sv", 
                                             7);
        vlSelfRef.fibonacci_test__DOT__clk = (1U & 
                                              (~ (IData)(vlSelfRef.fibonacci_test__DOT__clk)));
    }
    co_return;
}

bool Vfibonacci_test___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vfibonacci_test___024root___timing_ready(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___timing_ready\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h24cec110__0.ready("@(posedge fibonacci_test.clk)");
    }
}

void Vfibonacci_test___024root___timing_resume(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___timing_resume\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h24cec110__0.moveToResumeQueue(
                                                          "@(posedge fibonacci_test.clk)");
    vlSelfRef.__VtrigSched_h24cec110__0.resume("@(posedge fibonacci_test.clk)");
    if ((0x0000000000000010ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vfibonacci_test___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfibonacci_test___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vfibonacci_test___024root___eval_phase__act(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___eval_phase__act\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                          << 4U) 
                                                         | (((((~ (IData)(vlSelfRef.fibonacci_test__DOT__rst_n)) 
                                                               & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__rst_n__0)) 
                                                              << 3U) 
                                                             | (((IData)(vlSelfRef.fibonacci_test__DOT__clk) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__clk__0))) 
                                                                << 2U)) 
                                                            | ((((IData)(vlSelfRef.fibonacci_test__DOT__f_test) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__f_test__0)) 
                                                                << 1U) 
                                                               | ((IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1) 
                                                                  != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__DUT__DOT__f_n1__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__DUT__DOT__f_n1__0 
            = vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1;
        vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__f_test__0 
            = vlSelfRef.fibonacci_test__DOT__f_test;
        vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__clk__0 
            = vlSelfRef.fibonacci_test__DOT__clk;
        vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__rst_n__0 
            = vlSelfRef.fibonacci_test__DOT__rst_n;
    }
    Vfibonacci_test___024root___timing_ready(vlSelf);
    Vfibonacci_test___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfibonacci_test___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vfibonacci_test___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vfibonacci_test___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vfibonacci_test___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vfibonacci_test___024root___eval_phase__inact(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___eval_phase__inact\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("fibonacci_test.sv", 11, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vfibonacci_test___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vfibonacci_test___024root___eval_phase__nba(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___eval_phase__nba\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vfibonacci_test___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    if (VL_UNLIKELY((((~ (IData)(vlSymsp->TOP____024unit.__VmonitorOff)) 
                                      & (1U == vlSymsp->TOP____024unit.__VmonitorNum))))) {
                        VL_WRITEF_NX("%d DUT f: %0d | Test Model: %0d\n",3
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',16,(IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1)
                                     , '#',16,vlSelfRef.fibonacci_test__DOT__f_test);
                    }
                }
            }
            if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__1
                    CData/*1:0*/ __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__state;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__state = 0;
                    SData/*15:0*/ __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__f_n1;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__f_n1 = 0;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__state 
                        = vlSelfRef.fibonacci_test__DOT__DUT__DOT__state;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__f_n1 
                        = vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1;
                    if (vlSelfRef.fibonacci_test__DOT__rst_n) {
                        if ((2U & (IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__state))) {
                            __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__state 
                                = (3U & (1U & (- (IData)(
                                                         (1U 
                                                          & (~ (IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__state)))))));
                            if ((1U & (IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__state))) {
                                vlSelfRef.fibonacci_test__DOT__DUT__DOT__n 
                                    = (0x0000001fU 
                                       & (IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__n));
                                __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__f_n1 
                                    = (0x0000ffffU 
                                       & (IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1));
                                vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n2 
                                    = vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n2;
                            } else {
                                vlSelfRef.fibonacci_test__DOT__DUT__DOT__n 
                                    = (0x0000001fU 
                                       & ((IData)(1U) 
                                          + (IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__n)));
                                __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__f_n1 
                                    = (0x0000ffffU 
                                       & ((IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1) 
                                          + (IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n2)));
                                vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n2 
                                    = vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1;
                            }
                        } else {
                            if ((1U & (IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__state))) {
                                __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__state 
                                    = (3U & (2U | (- (IData)(
                                                             (0x13U 
                                                              == (IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__n))))));
                                __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__f_n1 
                                    = (0x0000ffffU 
                                       & (IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1));
                            } else {
                                __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__state 
                                    = (3U & 1U);
                                __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__f_n1 
                                    = (0x0000ffffU 
                                       & 1U);
                            }
                            vlSelfRef.fibonacci_test__DOT__DUT__DOT__n 
                                = (0x0000001fU & ((IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__n) 
                                                  & (- (IData)(
                                                               (1U 
                                                                & (IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__state))))));
                            vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n2 
                                = ((IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n2) 
                                   & (- (IData)((1U 
                                                 & (IData)(vlSelfRef.fibonacci_test__DOT__DUT__DOT__state)))));
                        }
                    } else {
                        __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__state = 0U;
                        vlSelfRef.fibonacci_test__DOT__DUT__DOT__n = 0U;
                        __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__f_n1 = 1U;
                        vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n2 = 0U;
                    }
                    vlSelfRef.fibonacci_test__DOT__DUT__DOT__f_n1 
                        = __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__f_n1;
                    vlSelfRef.fibonacci_test__DOT__DUT__DOT__state 
                        = __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__fibonacci_test__DOT__DUT__DOT__state;
                }
            }
        }
        Vfibonacci_test___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vfibonacci_test___024root___eval(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___eval\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vfibonacci_test___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("fibonacci_test.sv", 11, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("fibonacci_test.sv", 11, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vfibonacci_test___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("fibonacci_test.sv", 11, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vfibonacci_test___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vfibonacci_test___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vfibonacci_test___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vfibonacci_test___024root____VbeforeTrig_h24cec110__0(Vfibonacci_test___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root____VbeforeTrig_h24cec110__0\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)((((IData)(vlSelfRef.fibonacci_test__DOT__clk) 
                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__clk__0))) 
                                  << 2U)));
    vlSelfRef.__Vtrigprevexpr___TOP__fibonacci_test__DOT__clk__0 
        = vlSelfRef.fibonacci_test__DOT__clk;
    if ((4ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h24cec110__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h24cec110__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h24cec110__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h24cec110__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h24cec110__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h24cec110__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h24cec110__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vfibonacci_test___024root___eval_debug_assertions(Vfibonacci_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_test___024root___eval_debug_assertions\n"); );
    Vfibonacci_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
