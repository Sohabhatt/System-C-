#ifndef MULTIPLEXER_H
#define MULTIPLEXER_H
#include<systemc.h>

SC_MODULE(multiplexer) {
   sc_in<bool> I1, I0, Sel;
   sc_out<bool> Y;
   
   void func() {
     Y.write(Sel.read() ? I1.read() : I0.read());
     }
     
  SC_CTOR(multiplexer) {
    SC_METHOD(func);
    sensitive<<I1<<I0<<Sel;
    }
};
#endif
