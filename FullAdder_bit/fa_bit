#include<systemc.h>
SC_MODULE (fa_bit) {
 sc_in < sc_bv<3> > in; //a,b,c
 sc_out < sc_bv<2> > out; //s,cout
 
 sc_bv<3> a,b,c; //temp signals
 sc_bv<2> s,cout; // temp signals
 sc_bv<2> result;
 
 void function() {
  a = in.read().range(2,2); //a is the MSB (bit 2)
  b = in.read().range(1,1); // b is the mid-bit (bit 1)
  c = in.read().range(0,0); // c is the LSB (bit 0)
  
  s = a ^ b ^ c; //sum
  cout = (a & b) | (b & c) | (c & a); //carry
  

  result[0] = s[0];     // sum bit
  result[1] = cout[0];  // carry bit

  out.write(result);//Concatenation of the sum and carry to get the 2-bit output
  }
  
 SC_CTOR (fa_bit) {   //constructor
   SC_METHOD (function);
   sensitive <<in;
   }
 
 ~fa_bit(){} //destructor
 };   
 
