#include <systemc.h> //System C header file to be included in every program
 using namespace sc_core; //"Namespace" is a C++ construct to prevent naming conflicts and for organizing codes
 
 /*Declare Module name -> and4 is the module name*/
SC_MODULE (and4) {    //SC_MODULE is a building block for modeling hardware components and design hierarchy
 sc_in<bool> in0, in1, in2, in3; //Input ports declaration in System C
 sc_out<bool> out; //Output ports in System C
 
 bool b0, b1, b2, b3, b4; //Some variables declaration using bool. We can use any other variables instead of bool like int, fixed etc
 bool LIB; //Same as prev. LIB is an OpenSparc T2 microprocessor environment variable, set here to value ‘true’ at a start of simulation
 
/*Declare the function which ur code will do*/ 
 void func(){ // Function declaration
   while(1) { //while loop -> if the condition is true, then wait
    wait(); // wait
    if (LIB = 1) { // if LIB is true, do the next work
   b0 = in0.read(); // instantiate b0 to in0
   b1 = in1.read(); // instantiate b1 to in1
   b2 = in2.read(); // instantiate b2 to in2
   b3 = in3.read(); // instantiate b3 to in3
   b4 = (in0 & in1 & in2 & in3); // do the same for b4
   out.write(b4); // write the output with b4
   }
  }
}   
/*Declare the constructor. Here u should declare the process*/   
 SC_CTOR(and4) { // A systemC constructor where and4 is the module name
   SC_THREAD(func); // SC_THREAD is a process because it contains wait statement. So, SC_THREAD contains the function which has been declared 
   sensitive <<in0<<in1<<in2<<in3; // sensitivity list based on in0, in1, in2, in3
  }
  
/*Declare the Destructor. You can declare it or not. It's upto you.*/  
 ~and4() {} // A systemC/C++ Destructor. It means that when an and4 object is destroyed, nothing special happens—no extra cleanup is needed. A Destructor is used release dynamically allocated memory to prevent memory leaks. This is an empty destructor.
  
 };   // Always use semicolon (;) in your header files to close the definition of a class, struct, or module in C++ and SystemC.
   
  
