#include<systemc.h>

SC_MODULE(half_adder) {
 sc_in<bool> a,b;
 sc_out<bool> s,carry;
 
 void func() {
  s.write(a.read() ^ b.read());
  carry.write(a.read() & b.read());
  }
  
  SC_CTOR(half_adder) {
   SC_METHOD(func);
   sensitive<<a<<b;
   }
};   
