#include <systemc.h>
#include "full_adder.h"
int sc_main(int argc,char* argv[])
{
  sc_signal<bool>in0,in1,in2,s,cout;

sc_trace_file *fp = sc_create_vcd_trace_file("full_adder");
 fp -> set_time_unit(1.0, SC_NS);

  full_adder DUT("DUT");
  DUT.a(in0);
  DUT.b(in1);
  DUT.cin(in2);
  DUT.sum(s);
  DUT.cout(cout);

  sc_trace(fp, in0, "in0"); 
  sc_trace(fp, in1, "in1"); 
  sc_trace(fp, in2, "in2"); 
  sc_trace(fp, s, "s"); 
  sc_trace(fp, cout, "cout");

  
  DUT.LIB=true;
  
  in0.write(true);
  in1.write(false);
  in2.write(true);
  
  sc_start(5,SC_NS);
  
  cout<<"@ "<<sc_time_stamp()<<" a = "<<in0.read()<<" b = "<<in1.read()<<" c = "<<in2.read()<<" result = "<<s.read()<<cout.read()<<endl;
  
  sc_stop();
  sc_close_vcd_trace_file(fp);
  return 0;
}
