#include <systemc.h>
#include "nand4.h"
#include<cstdlib>
#include<cstring>

using namespace sc_core;


int sc_main (int argc, char **argv) {
 sc_signal <bool> sig_in0, sig_in1, sig_in2, sig_in3, sig_out;
 
 sc_trace_file *fp;
 
 nand4 nand4 ("nand4");
 fp = sc_create_vcd_trace_file("4_1_bit_nand");
 fp -> set_time_unit(1.0, SC_NS);
 
  nand4.in0(sig_in0);
  nand4.in1(sig_in1);
  nand4.in2(sig_in2);
  nand4.in3(sig_in3);
  nand4.y(sig_out);
  
  //nand4.LIB = true;
  sc_trace(fp, sig_in0, "nand4_in0");
  sc_trace(fp, sig_in1, "nand4_in1");
  sc_trace(fp, sig_in2, "nand4_in2");
  sc_trace(fp, sig_in3, "nand4_in3");
  sc_trace(fp, sig_out, "nand4_out");
  
  sig_in0.write(true);
  sig_in1.write(true);
  sig_in2.write(false);
  sig_in3.write(true);
  sc_start(1.0, SC_NS);
  cout << "in0=1, in2=1, in3=0, in4=1, out=   "<<sig_in0.read() << sig_in1.read() << sig_in2.read() << sig_in3.read() << sig_out.read() << endl;
  
   sig_in0.write(false);
  sig_in1.write(true);
  sig_in2.write(true);
  sig_in3.write(true);
  sc_start(1.0, SC_NS);
  cout << "in0=0, in2=1, in3=1, in4=1, out=   "<<sig_in0.read() << sig_in1.read() << sig_in2.read() << sig_in3.read() << sig_out.read() << endl;
  
   sig_in0.write(true);
  sig_in1.write(true);
  sig_in2.write(false);
  sig_in3.write(false);
  sc_start(1.0, SC_NS);
  cout << "in0=1, in2=1, in3=0, in4=0, out=   "<<sig_in0.read() << sig_in1.read() << sig_in2.read() << sig_in3.read() << sig_out.read() << endl;
  
   sig_in0.write(false);
  sig_in1.write(false);
  sig_in2.write(false);
  sig_in3.write(false);
  sc_start(1.0, SC_NS);
  cout << "in0=0, in2=0, in3=0, in4=0, out=   "<<sig_in0.read() << sig_in1.read() << sig_in2.read() << sig_in3.read() << sig_out.read() << endl;
  
   sig_in0.write(true);
  sig_in1.write(true);
  sig_in2.write(true);
  sig_in3.write(true);
  sc_start(1.0, SC_NS);
  cout << "in0=1, in2=1, in3=1, in4=1, out=   "<<sig_in0.read() << sig_in1.read() << sig_in2.read() << sig_in3.read() << sig_out.read() << endl;
  
  sc_stop();
  sc_close_vcd_trace_file(fp);
  return 0;
  }

 

