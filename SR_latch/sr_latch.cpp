#include<systemc.h>
#include"sr_latch.h"

void sr_latch::process() {
  if(!S.read() && !R.read()) {
     //Hold state
     }
  else if (!S.read() && R.read()) {
      q_state = "0";
      }
  else if (S.read() && !R.read()) {
      q_state = "1";
      }    
  else {
      q_state = "0";
      }
    Q.write(q_state);
    Qbar.write(!q_state);
 }   
