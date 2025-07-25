#include<systemc.h>

SC_MODULE(testbench) {
  sc_in<bool> s, carry;
  sc_out<bool> a,b;
  
  void stim_gen() {
     a.write(0);
     b.write(0);
     wait(5,SC_NS);
     cout<<"a=0, b=0, s= "<<s.read()<<", carry = "<<carry.read()<<endl;
    
     a.write(0);
     b.write(1);
     wait(5,SC_NS);
     cout<<"a=0, b=1, s= "<<s.read()<<",carry="<<carry.read()<<endl;
          
     a.write(1);
     b.write(0);
     wait(5,SC_NS);
     cout<<"a=1, b=0, s= "<<s.read()<<",carry="<<carry.read()<<endl;
          
     a.write(1);
     b.write(1);
     wait(5,SC_NS);
     cout<<"a=1, b=1, s= "<<s.read()<<",carry="<<carry.read()<<endl;
     
     sc_stop();
     }
     
     SC_CTOR(testbench){
       SC_THREAD(stim_gen);
      }
};       
         
  
