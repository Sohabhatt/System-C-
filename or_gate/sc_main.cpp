#include<systemc.h>
#include "or_gate.h"
#include "testbench.h"

int sc_main(int argc, char* argv[]) {
sc_signal<bool> sig_a, sig_b, sig_c;

or_gate uut("or_gate");
uut.a(sig_a);
uut.b(sig_b);
uut.c(sig_c);

testbench tb("testbench");
tb.a(sig_a);
tb.b(sig_b);
tb.c(sig_c);

sc_trace_file *tf = sc_create_vcd_trace_file("wave");
sc_trace(tf, sig_a, "sig_a");
sc_trace(tf, sig_b, "sig_b");
sc_trace(tf, sig_c, "sig_c");
sc_start();
sc_close_vcd_trace_file(tf);
return 0;

}


