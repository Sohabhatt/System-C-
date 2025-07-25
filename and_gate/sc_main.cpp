#include<systemc.h>
#include "and_gate.h"
#include "testbench.h"

int sc_main(int argc, char* argv[]){
	sc_signal<bool> sig_a, sig_b, sig_c;

	and_gate uut("and_gate");
	uut.a(sig_a);
	uut.b(sig_b);
	uut.c(sig_c);

	testbench tb("testbench");
	tb.a(sig_a);
	tb.b(sig_b);
	tb.c(sig_c);

	sc_start();
	return 0;
}
