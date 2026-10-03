import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer
# gemini created ts
async def mcp3008_responder(dut, return_byte: int):
    """Accurate SPI Mode 0,0 responder for MCP3008."""
    # 1. Wait for CS to assert active-low
    while dut.cs_n.value == 1:
        await RisingEdge(dut.clk)

    # 2. Drive MSB (bit 7) immediately before the first rising edge of dclk
    bit_idx = 7
    dut.cipo.value = (return_byte >> bit_idx) & 0x1

    # 3. For every subsequent bit (6 down to 0), update cipo on the falling edge of dclk
    while bit_idx > 0:
        await FallingEdge(dut.dclk)
        bit_idx -= 1
        dut.cipo.value = (return_byte >> bit_idx) & 0x1

    # 4. Wait for the final bit's clock pulse to finish, then release cipo
    await RisingEdge(dut.dclk)
    await FallingEdge(dut.dclk)
    dut.cipo.value = 0

@cocotb.test()
async def test_spi (dut):
  # start 100Mhz clock (10 ns period)
  cocotb.start(Clock(dut.clk, 10, units="ns").start())

  # config spi test controller
  # initialize inputs and assert reset
  # https://ww1.microchip.com/downloads/aemDocuments/documents/MSLD/ProductDocuments/DataSheets/MCP3004-MCP3008-Data-Sheet-DS20001295.pdf
  # simulate transactions
  dut.rst_n.value = 0
  dut.trigger.value = 0
  dut.data_in.value = 0x18 # simulate access to channel 0
  # test send byte(s)
  # test reset in middle of transfer
  await RisingEdge(dut.clk)
  dut.rst_n.value = 1 # hold reset
  await RisingEdge(dut.clk)

  print("Testing a byte")
  # start the spi device
  expected_val = 0x67
  cocotb.start_soon(mcp3008_responder(dut, expected_val))

  
  dut.trigger.value = 1 # assert the trigger
  await RisingEdge(dut.clk)
  dut.trigger.value = 0 # place the trigger back to low
  # wait for the transaction to start (cs_n drops low)
  while (dut.cs_n.value == 1):
    await RisingEdge(dut.clk)
  # wait until device asserts DONE (cs_n becomes 1 again)
  while (dut.cs_n.value == 0):
    await RisingEdge(dut.clk)
  
  received_data = dut.data_out.value
  assert received_data == expected_val, f"expected {hex(expected_val)}, got {hex(received_data)}"

  await RisingEdge(dut.clk)
  ## test diff value
  # give new value to spi thing
  print("Sending a new value")
  expected_val = 0xAA
  cocotb.start_soon(mcp3008_responder(dut, expected_val))

  
  dut.trigger.value = 1 # assert the trigger
  await RisingEdge(dut.clk)
  dut.trigger.value = 0 # place the trigger back to low
  # wait for the transaction to start (cs_n drops low)
  while (dut.cs_n.value == 1):
    await RisingEdge(dut.clk)
  # wait until device asserts DONE (cs_n becomes 1 again)
  while (dut.cs_n.value == 0):
    await RisingEdge(dut.clk)
  
  received_data = dut.data_out.value
  assert received_data == expected_val, f"expected {hex(expected_val)}, got {hex(received_data)}"

  # test reset
  print("Testing Reset")
  dut.rst_n.value = 0
  await RisingEdge(dut.clk)
  # immediately check 
  assert dut.cs_n.value == 1, "cs_n failed to return high (idle) during reset"
  assert dut.dclk.value == 0, "dclk failed to pull low (idle) during reset"
  assert dut.data_valid.value == 0, "data_valid asserted spuriously during reset"
  await RisingEdge(dut.clk) # wait a cycle or two
  await RisingEdge(dut.clk)
  # deassert the reset so it can run as normal?  
  dut.rst_n.value = 1
  expected_val = 0x4E
  cocotb.start_soon(mcp3008_responder(dut, expected_val))

  
  dut.trigger.value = 1 # assert the trigger
  await RisingEdge(dut.clk)
  dut.trigger.value = 0 # place the trigger back to low
  # wait for the transaction to start (cs_n drops low)
  while (dut.cs_n.value == 1):
    await RisingEdge(dut.clk)
  # wait until device asserts DONE (cs_n becomes 1 again)
  while (dut.cs_n.value == 0):
    await RisingEdge(dut.clk)
  
  received_data = dut.data_out.value
  assert received_data == expected_val, f"expected {hex(expected_val)}, got {hex(received_data)}"
