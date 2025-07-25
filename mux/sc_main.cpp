#include<systemc.h>
#include"multiplexer.h"
#include"tb.h"

int sc_main(int argc, char* argv[]) {
 sc_signal<bool> sig_I0, sig_I1, sig_Sel, sig_Y;
 
 multiplexer uut("multiplexer");
  uut.I0(sig_I0);
  uut.I1(sig_I1);
  uut.Sel(sig_Sel);
  uut.Y(sig_Y);

tb tb("tb");
  tb.I0(sig_I0);
  tb.I1(sig_I1);
  tb.Sel(sig_Sel);
  tb.Y(sig_Y);
  
sc_trace_file *tf = sc_create_vcd_trace_file("wave");
sc_trace(tf, sig_I0, "sig_IO");
sc_trace(tf, sig_I1, "sig_I1");
sc_trace(tf, sig_Sel, "sig_Sel");
sc_trace(tf, sig_Y, "sig_Y");
sc_start();
sc_close_vcd_trace_file(tf);
return 0;
  
}  
