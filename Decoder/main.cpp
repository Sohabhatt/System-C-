#include <systemc.h>
#include "Decoder.h"

int sc_main(int argc, char* argv[]) {
  sc_signal<sc_uint<2>> in_sig;
  sc_signal<sc_uint<4>> out_sig;

  decoder dut("decoder");
  dut.in(in_sig);
  dut.out(out_sig);

  sc_trace_file* tf = sc_create_vcd_trace_file("decoder");
  tf->set_time_unit(1, SC_NS);
  sc_trace(tf, in_sig, "in");
  sc_trace(tf, out_sig, "out");

  // Test all input values
  for (int i = 0; i < 4; i++) {
    in_sig.write(i);
    sc_start(10, SC_NS);
    std::cout << "@ " << sc_time_stamp() << " Input: " << in_sig.read() << " Output: " << out_sig.read() << std::endl;
  }

  sc_close_vcd_trace_file(tf);
  return 0;
}
