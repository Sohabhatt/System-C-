#include <systemc.h>

SC_MODULE(full_adder)
{
  sc_in<bool>a,b,c;
  sc_out<bool>sum,cout;
  
  bool LIB;
  bool b0,b1,b2;
  
  void add_func()
  {
    while(1)
    {
      wait();
      if(LIB==1)
      {
        b0=a.read();
        b1=b.read();
        b2=c.read();
        
        sum.write(b0^b1^b2);
        cout.write((b0&b1)|(b1&b2)|(b2&b0));
      }
    }
  }
  
  SC_CTOR(full_adder)
  {
    SC_THREAD(add_func);
    sensitive<<a<<b<<c;
  }
  
  ~full_adder(){};
};
  
