#include <systemc.h>

SC_MODULE(decoder) {
  sc_in<sc_uint<2>> in;       
  sc_out<sc_uint<4>> out;    

  void function() {
    sc_uint<4> result = 0;

    switch (in.read()) {
      case 0x0: result = 0b0001; break; //'0b' forbinary literal just like 0x for hex
      case 0x1: result = 0b0010; break;
      case 0x2: result = 0b0100; break;
      case 0x3: result = 0b1000; break;
      default: result = 0b0000; 
    }

    out.write(result);
  }

  SC_CTOR(decoder) {
    SC_METHOD(function);
    sensitive << in;
  }
};

