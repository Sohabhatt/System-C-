#include <systemc.h>

SC_MODULE(FSM) {
    sc_in<bool> clk;
    sc_in<bool> reset;
    sc_in<bool> start;
    sc_out<bool> finished;

     enum State {IDLE, WORK, DONE};
    State current_state, next_state;

       void fsm_method() {
        if (reset.read()) {
            current_state = IDLE;
        } else {
            current_state = next_state;
        }
    }

       void logic_method() {
        switch (current_state) {
            case IDLE:
                finished.write(false);
                if (start.read())
                    next_state = WORK;
                else
                    next_state = IDLE;
                break;
            case WORK:
                finished.write(false);
                next_state = DONE;
                break;
            case DONE:
                finished.write(true);
                next_state = IDLE;
                break;
        }
    }


    SC_CTOR(FSM) {
        current_state = IDLE;
        SC_METHOD(fsm_method);
        sensitive << clk.pos();
        dont_initialize();

        SC_METHOD(logic_method);
        sensitive << start;
        dont_initialize();
    }
};
