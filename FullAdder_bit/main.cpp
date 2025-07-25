#include <systemc.h>
#include "fa_bit.h"  

int sc_main(int argc, char* argv[]) {
  
  sc_signal<sc_bv<3>> in_signal;    // 3-bit input signal
  sc_signal<sc_bv<2>> out_signal;   // 2-bit output signal (Sum, Carry_out)
  
 
  fa_bit DUT("DUT");
  DUT.in(in_signal);
  DUT.out(out_signal);
  
  sc_trace_file *fp;
  fp = sc_create_vcd_trace_file("fa_vec_trace");
  fp->set_time_unit(1, SC_NS); 

  sc_trace(fp, in_signal, "in_signal");
  sc_trace(fp, out_signal, "out_signal");

  
  in_signal.write("000");  // A=0, B=0, Cin=0
  sc_start(10, SC_NS);  // Run for 10ns
  
 
  cout << "@ " << sc_time_stamp() << "in = " << in_signal.read() << " out = " << out_signal.read() << endl;
  
  in_signal.write("001");  // A=0, B=0, Cin=1
  sc_start(10, SC_NS);  // Run for 10ns
  

  cout << "@ " << sc_time_stamp() << " in = " << in_signal.read() << " out = " << out_signal.read() << endl;

  in_signal.write("010");  // A=0, B=1, Cin=0
  sc_start(10, SC_NS);  // Run for 10ns

  cout << "@ " << sc_time_stamp() <<" in = " << in_signal.read() << " out = " << out_signal.read() << endl;

  sc_stop();  // Stop the simulation
  sc_close_vcd_trace_file(fp);  // Close the VCD trace file

  return 0;
}
