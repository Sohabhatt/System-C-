#include<systemc.h> // Declare the systemC header file
#include "and4.h" // Declare your own file -> and4.H
#include<cstdlib> // Declare the standard library in system C
#include<cstring> // Declare the string in System C

/* Declare the main function with the arguments, just like C++*/
int sc_main(int argc, char **argv) { // argc and argv are the arguments which we use in C++
 sc_signal <bool> sig_in0, sig_in1, sig_in2, sig_in3, sig_out; // Declare the signal according to your previous header file -> and4.h
 
 sc_trace_file *fp; // Declare a pointer for the VCD trace file to store 
 
 and4 and4("and"); //Instantiate the 'and4' module with the instance name "and" 
 fp = sc_create_vcd_trace_file ("and_gate"); //Create a VCD trace file
 fp -> set_time_unit (1.0, SC_NS); // Set the time unit for the trace file to 1ns. You can set according to your specs.
 
 and4.LIB == true; // LIB is discussed before in the previous file. Please check
 and4.in0(sig_in0); // Connect the 'sig_in0' signal to the 'in0' input port of the 'and4' module instance.
 and4.in1(sig_in1); // Same as prev.
 and4.in2(sig_in2); // Same as prev.
 and4.in3(sig_in3); // Same as prev.
 and4.out(sig_out); // Same as prev.
 
 sc_trace(fp, sig_in0, "sig_in0"); //Add 'sig_in0' to the VCD trace file with the name "sig_in0" for waveform viewing.
 sc_trace(fp, sig_in1, "sig_in1"); // Same as prev.
 sc_trace(fp, sig_in2, "sig_in2"); // Same as prev.
 sc_trace(fp, sig_in3, "sig_in3"); // Same as prev.
 sc_trace(fp, sig_out, "sig_out"); // Same as prev.
 
 sig_in0.write(false); // Give your logic just like the stimulus in Verilog
 sig_in1.write(false); // Same as prev.
 sig_in2.write(false); // Same as prev.
 sig_in3.write(false); // Same as prev.
 sc_start(1.0, SC_NS); // Start the simulation and run it for 1ns.
 cout<<"in0= 0, in1 = 0, in2 = 0, in3 = 0, out = "<<sig_in0<< sig_in1<<sig_in2<<sig_in3<<endl; // For printing your outputs and inputs in C++ as well as SystemC.
 
 /*Same as before stim*/
 sig_in0.write(false); 
 sig_in1.write(false);
 sig_in2.write(false);
 sig_in3.write(true);
 sc_start(1.0, SC_NS);
 cout<<"in0= 0, in1 = 0, in2 = 0, in3 = 1, out = "<<sig_in0<< sig_in1<<sig_in2<<sig_in3<<endl;
 
 sig_in0.write(false);
 sig_in1.write(false);
 sig_in2.write(true);
 sig_in3.write(false);
 sc_start(1.0, SC_NS);
 cout<<"in0= 0, in1 = 0, in2 = 1, in3 = 0, out = "<<sig_in0<< sig_in1<<sig_in2<<sig_in3<<endl;
 
 sig_in0.write(false);
 sig_in1.write(true);
 sig_in2.write(false);
 sig_in3.write(false);
 sc_start(1.0, SC_NS);
 cout<<"in0= 0, in1 = 1, in2 = 0, in3 = 0, out = "<<sig_in0<< sig_in1<<sig_in2<<sig_in3<<endl;
 
 
 sig_in0.write(true);
 sig_in1.write(false);
 sig_in2.write(false);
 sig_in3.write(false);
 sc_start(1.0, SC_NS);
 cout<<"in0= 1, in1 = 0, in2 = 0, in3 = 0, out = "<<sig_in0<< sig_in1<<sig_in2<<sig_in3<<endl;
 
 sig_in0.write(true);
 sig_in1.write(true);
 sig_in2.write(true);
 sig_in3.write(true);
 sc_start(1.0, SC_NS);
 cout<<"in0= 1, in1 = 1, in2 = 1, in3 = 1, out = "<<sig_in0<< sig_in1<<sig_in2<<sig_in3<<endl;
 
 
 sig_in0.write(true);
 sig_in1.write(true);
 sig_in2.write(false);
 sig_in3.write(false);
 sc_start(1.0, SC_NS);
 cout<<"in0= 1, in1 = 1, in2 = 0, in3 = 0, out = "<<sig_in0<< sig_in1<<sig_in2<<sig_in3<<endl;
 
 
 sig_in0.write(true);
 sig_in1.write(false);
 sig_in2.write(true);
 sig_in3.write(false);
 sc_start(1.0, SC_NS);
 cout<<"in0= 1, in1 = 0, in2 = 1, in3 = 0, out = "<<sig_in0<< sig_in1<<sig_in2<<sig_in3<<endl;
 
 
 sig_in0.write(true);
 sig_in1.write(false);
 sig_in2.write(false);
 sig_in3.write(true);
 sc_start(1.0, SC_NS);
 cout<<"in0= 1, in1 = 0, in2 = 0, in3 = 1, out = "<<sig_in0<< sig_in1<<sig_in2<<sig_in3<<endl;
 
 
 sig_in0.write(false);
 sig_in1.write(true);
 sig_in2.write(true);
 sig_in3.write(false);
 sc_start(1.0, SC_NS);
 cout<<"in0= 0, in1 = 1, in2 = 1, in3 = 0, out = "<<sig_in0<< sig_in1<<sig_in2<<sig_in3<<endl;
 
 
 sig_in0.write(false);
 sig_in1.write(true);
 sig_in2.write(false);
 sig_in3.write(true);
 sc_start(1.0, SC_NS);
 cout<<"in0= 0, in1 = 1, in2 = 0, in3 = 1, out = "<<sig_in0<< sig_in1<<sig_in2<<sig_in3<<endl;
 
 sc_stop(); // Stop the simulation
 sc_close_vcd_trace_file(fp); //Closes the VCD trace file
 return 0;//To end the sc_main function and returns 0 to the operating system. 
 }

 
 
 
 
