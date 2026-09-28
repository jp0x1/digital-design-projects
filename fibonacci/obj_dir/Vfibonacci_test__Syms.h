// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VFIBONACCI_TEST__SYMS_H_
#define VERILATED_VFIBONACCI_TEST__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vfibonacci_test.h"

// INCLUDE MODULE CLASSES
#include "Vfibonacci_test___024root.h"
#include "Vfibonacci_test___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vfibonacci_test__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vfibonacci_test* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vfibonacci_test___024root      TOP;
    Vfibonacci_test___024unit      TOP____024unit;

    // CONSTRUCTORS
    Vfibonacci_test__Syms(VerilatedContext* contextp, const char* namep, Vfibonacci_test* modelp);
    ~Vfibonacci_test__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
