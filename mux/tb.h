#include <systemc.h>
#include "multiplexer.h"

SC_MODULE(tb) {
    sc_out<bool> I1, I0, Sel;
    sc_in<bool> Y;

    void stim_gen() {
       
        Sel.write(0);
        I1.write(1);
        I0.write(1);
        wait(10, SC_NS);
        cout << "I1 = " << I1.read()
             << ", I0 = " << I0.read()
             << ", Sel = " << Sel.read()
             << ", Y = " << Y.read() << endl;

        // Add more test vectors if desired
        // Example:
        Sel.write(1);
        I1.write(0);
        I0.write(1);
        wait(10, SC_NS);
        cout << "I1 = " << I1.read()
             << ", I0 = " << I0.read()
             << ", Sel = " << Sel.read()
             << ", Y = " << Y.read() << endl;

        sc_stop();
    }

    SC_CTOR(tb) {
        SC_THREAD(stim_gen);
    }
};
