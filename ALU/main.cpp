#include<systemc.h>
#include "ALU.h"

int sc_main (int argc, char* argv[]) {
 const int WIDTH = 8;
 
 sc_signal < sc_uint<WIDTH> > sig_a, sig_b, sig_result;
 sc_signal < sc_uint<7> > sig_opcode;
 
 ALU<WIDTH> alu("ALU");
 sc_trace_file *fp = sc_create_vcd_trace_file ("ALU"); 
 fp -> set_time_unit (1.0, SC_NS);
 
 alu.a(sig_a);
 alu.b(sig_b);
 alu.result(sig_result);
 alu.opcode(sig_opcode);
 
 sc_trace(fp, sig_a, "sig_a");
 sc_trace(fp, sig_b, "sig_b"); 
 sc_trace(fp, sig_result, "sig_result"); 
 sc_trace(fp, sig_opcode, "sig_opcode");
 
 sig_a = 15;
 sig_b = 10;
 
 for (int i=0; i < 7; i++) {
  sig_opcode = i;
  sc_start(1.0, SC_NS);
  cout << "OPCODE: "<< i << "A: "<<sig_a.read() <<"B: "<<sig_b.read() << "Result: "<<sig_result.read() << endl;
  
  }
 sc_stop();
 sc_close_vcd_trace_file(fp);
 return 0;
 } 
