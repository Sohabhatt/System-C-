#ifndef _ALU_H
#define _ALU_H

#include <systemc.h>

template <int WIDTH> 
//const int WIDTH = 8;

SC_MODULE (ALU) {
 sc_in < sc_uint<WIDTH>  > a,b;
 sc_out < sc_uint<WIDTH> > result;
 sc_in < sc_uint<7> > opcode;
 
 
void ALU_func() {
  switch (opcode.read()) {
   case 0x0: result.write (a.read() + b.read()); break;
   case 0x1: result.write (a.read() - b.read()); break;
   case 0x2: result.write (a.read() * b.read()); break;
   case 0x3: result.write (a.read() / b.read()); break;
   case 0x4: result.write (a.read() & b.read()); break;
   case 0x5: result.write (a.read() ^ b.read()); break;
   case 0x6: result.write (a.read() | b.read()); break;
   default: result.write (0); break;
   }
  }
  
SC_CTOR (ALU) {
    SC_METHOD (ALU_func);
    sensitive << a << b <<opcode;
    }
 
 ~ ALU (){} 
 
 };     
 
 #endif
