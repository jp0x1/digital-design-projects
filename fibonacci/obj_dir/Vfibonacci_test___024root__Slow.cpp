// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfibonacci_test.h for the primary calling header

#include "Vfibonacci_test__pch.h"

void Vfibonacci_test___024root___ctor_var_reset(Vfibonacci_test___024root* vlSelf);

Vfibonacci_test___024root::Vfibonacci_test___024root(Vfibonacci_test__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vfibonacci_test___024root___ctor_var_reset(this);
}

void Vfibonacci_test___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vfibonacci_test___024root::~Vfibonacci_test___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
