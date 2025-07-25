#include "systemc.h"

using namespace sc_core;

SC_MODULE (nand4) {
  sc_in <bool> in0, in1, in2, in3;
  sc_out <bool> y;
  
  bool b0, b1, b2, b3, b4; 
  bool LIB;
  
  void func () {
   while(1) {
       wait();
       if (LIB == true) {
        b0 = in0.read();
        b1 = in1.read();
        b2 = in2.read();
        b3 = in3.read();
        b4 = !(b0 & b1 & b2 & b3);
        y.write(b4);
        
        }
       } 
    }    
  SC_CTOR(nand4) {
      SC_THREAD(func);
      sensitive <<in0 <<in1 <<in2 <<in3;
     }
     
 ~nand4() {};
 
}; 
 
