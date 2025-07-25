#include<systemc.h>

SC_MODULE(and_gate) {
        sc_in<bool> a,b;
        sc_out<bool>c;
        
        void func() {
        c.write(a.read() & b.read());
        }
        
        SC_CTOR(and_gate) {
                SC_METHOD(func);
                sensitive<<a<<b;
        }       
};    
