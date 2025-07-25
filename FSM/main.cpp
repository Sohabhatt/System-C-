#include<systemc.h> 
#include "FSM.h" 
 
int sc_main(int argc, char **argv) { 
 sc_signal <bool> sig_clk, sig_reset, sig_start, sig_finished;
 
 sc_trace_file *fp; 
 
 FSM FSM("FSM"); 
 fp = sc_create_vcd_trace_file ("FSM"); 
 fp -> set_time_unit (1.0, SC_NS); 
 

 FSM.clk(sig_clk); 
 FSM.reset(sig_reset);
 FSM.start(sig_start); 
 FSM.finished(sig_finished);

 
 sc_trace(fp, sig_clk, "sig_clk");
 sc_trace(fp, sig_reset, "sig_reset"); 
 sc_trace(fp, sig_start, "sig_start"); 
 sc_trace(fp, sig_finished, "sig_finished");
   
 sig_reset = 1;  
 sig_start = 0;
 sig_clk = 0;
 sc_start(1, SC_NS);

 sig_reset = 0;
 sc_start(1, SC_NS);

    // Start FSM
 sig_start = 1;
 for (int i = 0; i < 5; ++i) {
        sig_clk = !sig_clk;
        sc_start(1, SC_NS);
    }

    // Deassert start, continue simulation
 sig_start = 0;
    for (int i = 0; i < 5; ++i) {
        sig_clk = !sig_clk;
        sc_start(1, SC_NS);
    }
 
 sc_stop(); 
 sc_close_vcd_trace_file(fp); 
 return 0;
 }

 
 
 
 
