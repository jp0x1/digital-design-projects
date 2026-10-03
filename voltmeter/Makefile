SIM ?= verilator
TOPLEVEL_LANG ?= verilog

# Export current working directory so Python finds test_spi.py
export PYTHONPATH := $(PWD)

# Point to your SystemVerilog source file
VERILOG_SOURCES += $(PWD)/spi_con.sv

# Enable VCD trace generation in Verilator
EXTRA_ARGS += --trace --trace-structs

TOPLEVEL = spi_con
MODULE = spicon_test

include $(shell cocotb-config --makefiles)/Makefile.sim