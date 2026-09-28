// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfibonacci_test__pch.h"

//============================================================
// Constructors

Vfibonacci_test::Vfibonacci_test(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfibonacci_test__Syms(contextp(), _vcname__, this)}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vfibonacci_test::Vfibonacci_test(const char* _vcname__)
    : Vfibonacci_test(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfibonacci_test::~Vfibonacci_test() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vfibonacci_test___024root___eval_debug_assertions(Vfibonacci_test___024root* vlSelf);
#endif  // VL_DEBUG
void Vfibonacci_test___024root___eval_static(Vfibonacci_test___024root* vlSelf);
void Vfibonacci_test___024root___eval_initial(Vfibonacci_test___024root* vlSelf);
void Vfibonacci_test___024root___eval_settle(Vfibonacci_test___024root* vlSelf);
void Vfibonacci_test___024root___eval(Vfibonacci_test___024root* vlSelf);

void Vfibonacci_test::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfibonacci_test::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfibonacci_test___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vfibonacci_test___024root___eval_static(&(vlSymsp->TOP));
        Vfibonacci_test___024root___eval_initial(&(vlSymsp->TOP));
        Vfibonacci_test___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vfibonacci_test___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vfibonacci_test::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vfibonacci_test::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vfibonacci_test::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vfibonacci_test___024root___eval_final(Vfibonacci_test___024root* vlSelf);

VL_ATTR_COLD void Vfibonacci_test::final() {
    contextp()->executingFinal(true);
    Vfibonacci_test___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfibonacci_test::hierName() const { return vlSymsp->name(); }
const char* Vfibonacci_test::modelName() const { return "Vfibonacci_test"; }
unsigned Vfibonacci_test::threads() const { return 1; }
void Vfibonacci_test::prepareClone() const { contextp()->prepareClone(); }
void Vfibonacci_test::atClone() const {
    contextp()->threadPoolpOnClone();
}
