#include <systemc.h>
#include "sr_latch.h"  // Include your module header if separated

int sc_main(int argc, char* argv[]) {
    // Signals to connect to the SR latch
    sc_signal<bool> s_sig, r_sig;
    sc_signal<bool> q_sig, qbar_sig;

    // Instantiate the module
    sr_latch sr("SR_Latch");
    sr.S(s_sig);
    sr.R(r_sig);
    sr.Q(q_sig);
    sr.Qbar(qbar_sig);

    // Open trace file (for waveform viewing in GTKWave or similar)
    sc_trace_file *tf = sc_create_vcd_trace_file("sr_latch_trace");
    sc_trace(tf, s_sig, "S");
    sc_trace(tf, r_sig, "R");
    sc_trace(tf, q_sig, "Q");
    sc_trace(tf, qbar_sig, "Qbar");

    // Test stimulus
    cout << "Time\tS R | Q Qbar" << endl;
    
    s_sig = 0; r_sig = 0;
    sc_start(5, SC_NS);
    cout << sc_time_stamp() << "\t" << s_sig << " " << r_sig << " | " << q_sig << " " << qbar_sig << endl;

    s_sig = 1; r_sig = 0;
    sc_start(5, SC_NS);
    cout << sc_time_stamp() << "\t" << s_sig << " " << r_sig << " | " << q_sig << " " << qbar_sig << endl;

    s_sig = 0; r_sig = 1;
    sc_start(5, SC_NS);
    cout << sc_time_stamp() << "\t" << s_sig << " " << r_sig << " | " << q_sig << " " << qbar_sig << endl;

    s_sig = 0; r_sig = 0;
    sc_start(5, SC_NS);
    cout << sc_time_stamp() << "\t" << s_sig << " " << r_sig << " | " << q_sig << " " << qbar_sig << endl;

    s_sig = 1; r_sig = 1;  // Invalid case
    sc_start(5, SC_NS);
    cout << sc_time_stamp() << "\t" << s_sig << " " << r_sig << " | " << q_sig << " " << qbar_sig << endl;

    // Close trace file
    sc_close_vcd_trace_file(tf);

    return 0;
}
