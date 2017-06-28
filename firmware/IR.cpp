#include "IR.h"

IR::IR() {
    TCCR1A = 0x00;
    TCCR1B = 0x03;
    TIMSK1 = 0x00;
    pinMode(MIRP, INPUT);
}

int IR::read(void (*wait_func)() = [](){}) {
    int data[12];
    while(pulseIn(MIRP, LOW) < MIRSB) { wait_func();
    }

    for(int i=0;i<11;i++) data[i] = pulseIn(MIRP, LOW);

    for(int i=0;i<11;i++) {              //Parse them
    if(data[i] > MIRB1) {              //is it a 1?
     data[i] = 1;
    }  else {
     if(data[i] > MIRB0) {            //is it a 0?
       data[i] = 0;
     } else {
      data[i] = 2;                    //Flag the data as invalid; I don't know what it is!
     }
    }
    }
    for(int i=0;i<11;i++) {              //Pre-check data for errors
   if(data[i] > 1) {
     return -1;                       //Return -1 on invalid data
   }
 }

 int result = 0;
 int seed = 1;
 for(int i=0;i<11;i++) {              //Convert bits to integer
   if(data[i] == 1) {
     result += seed;
   }
   seed = seed * 2;
 }
 return result;
}
