#include<systemc.h>

SC_MODULE(testbench) {
	sc_out<bool> a,b;
	sc_in<bool> c;

	void stim_gen() {
		a.write(0);
		b.write(0);
		wait(10, SC_NS);
		cout<<"a=0, b=0, c="<<c.read()<<endl;

	        a.write(0);
                b.write(1);
                wait(10, SC_NS);
                cout<<"a=0, b=1, c="<<c.read()<<endl;

		a.write(1);
                b.write(0);
                wait(10, SC_NS);
                cout<<"a=1, b=0, c="<<c.read()<<endl;

		a.write(1);
                b.write(1);
                wait(10, SC_NS);
                cout<<"a=1, b=1, c="<<c.read()<<endl;

		sc_stop();
		}
		
		SC_CTOR(testbench) {
		  SC_THREAD(stim_gen);
	}
};
