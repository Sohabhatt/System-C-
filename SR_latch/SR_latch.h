#include <systemc.h>

SC_MODULE(sr_latch) {
    sc_in<bool> S, R;
    sc_out<bool> Q, Qbar;

    void process() {
        if (S.read() == 1 && R.read() == 0) {
            Q.write(1);
            Qbar.write(0);
        } else if (S.read() == 0 && R.read() == 1) {
            Q.write(0);
            Qbar.write(1);
        } else if (S.read() == 0 && R.read() == 0) {
            // Hold previous state (do nothing)
            Q.write(Q.read());      // optional - Q holds state
            Qbar.write(Qbar.read());
        } else {
            // Invalid condition (S=1, R=1)
            SC_REPORT_WARNING("sr_latch", "Invalid input: S=1, R=1");
        }
    }

    SC_CTOR(sr_latch) {
        SC_METHOD(process);
        sensitive << S << R;
    }
};
