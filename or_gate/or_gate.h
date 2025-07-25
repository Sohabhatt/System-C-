#include<systemc.h>

SC_MODULE(or_gate) {
 sc_in<bool> a,b;
 sc_out<bool> c;
 
 void func () {
   c.write(a.read() | b.read());
   }
   
 SC_CTOR(or_gate){
    SC_METHOD(func);
    sensitive<<a<<b;
    }
};      
