#include<systemc.h>
#include"half_adder.h"
#include"testbench.h"

int sc_main(int argc, char* argv[]) {
  sc_signal<bool> sig_a, sig_b, sig_s, sig_carry;
  
  half_adder uut("half_adder");
  uut.a(sig_a);
  uut.b(sig_b);
  uut.s(sig_s);
  uut.carry(sig_carry);
  
  testbench tb("testbench");
  tb.a(sig_a);
  tb.b(sig_b);
  tb.s(sig_s);
  tb.carry(sig_carry);
  
  sc_start();
  return 0;
}  
