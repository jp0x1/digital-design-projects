// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfibonacci_test.h for the primary calling header

#include "Vfibonacci_test__pch.h"

void Vfibonacci_test___024unit___ctor_var_reset(Vfibonacci_test___024unit* vlSelf);

Vfibonacci_test___024unit::Vfibonacci_test___024unit() = default;
Vfibonacci_test___024unit::~Vfibonacci_test___024unit() = default;

void Vfibonacci_test___024unit::ctor(Vfibonacci_test__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vfibonacci_test___024unit___ctor_var_reset(this);
}

void Vfibonacci_test___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vfibonacci_test___024unit::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
