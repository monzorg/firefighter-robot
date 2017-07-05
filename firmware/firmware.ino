/**
**   /\/\   ___  _ __  _______  _ __ __ _
**  /    \ / _ \| '_ \|_  / _ \| '__/ _` |
** / /\/\ \ (_) | | | |/ / (_) | | | (_| |
** \/    \/\___/|_| |_/___\___/|_|  \__, |
**                                    |___/
** Firefighter Robot
** Firefighter Robot firmware based on Arduino Board
**
** @repo firefighter-robot
** @license MIT License
** @authors "Filipe Laíns" <filipe.lains@gmail.com>
** @authors "Luís Ferreira" <lsferreira169@gmail.com>
*/

#include "config.h"
#include "init.h"
#include "fw_startled.h"
#include "Wire.h"

//#include <Scheduler.h>

/**
     Init Code
*/
void setup() {
    //First tone
    tone(8, 1000, 100);
    delay(100 * 1.30);
    noTone(8);

    //General initial code
    pinMode(MFP, OUTPUT);
    pinMode(MMLD, OUTPUT); //Temporary code fix
    pinMode(MLDL, INPUT);
    pinMode(MLDR, INPUT);
    analogButtons.add(sbtn);
    FastLED.addLeds<NEOPIXEL, 13>(rgb_strip, MRGBLN);
    Serial.begin(MSS);
    Wire.begin();
    //Scheduler.startLoop([]{Serial.println(c.read()[0]);});

    //Second Tone: Finish initial code loading
    tone(8, 1000, 300);
    delay(300 * 1.30);
    noTone(8);

    //Wait for button trigger
    while(!shouldStart) {
        callback_startled();
        analogButtons.check();
    }

    //When button triggered
    if(Debug || remoteDebug) {
        if(remoteDebug) {
            rgb_strip[0] = CRGB(50,50,0);
            rgb_strip[1] = CRGB(50,50,0);
        } else {
            rgb_strip[0] = CRGB(0,0,50);
            rgb_strip[1] = CRGB(0,0,50);
        }
    } else {
        rgb_strip[0] = CRGB(0,50,0);
        rgb_strip[1] = CRGB(0,50,0);
    }
    FastLED.show();

    //3rd tone
    if(Debug || remoteDebug) {
        if(remoteDebug) {
            //Remote Debug Tone
            tone(8, 2000, 600);
            delay(600 * 1.30);
            noTone(8);
        } else {
            //Debug Tone
            tone(8, 2000, 300);
            delay(300 * 1.30);
            tone(8, 2000, 300);
            delay(300 * 1.30);
            noTone(8);
        }
    }
    else {
        //Start Tone
        tone(8, 2000, 300);
        delay(300 * 1.30);
        noTone(8);
    }
    rgb_strip[0] = CRGB(0,0,0);
    rgb_strip[1] = CRGB(0,0,0);
    FastLED.show();
}

/**
     Loop Code
*/
void loop() {
    px.read();
    c.read();
    if(Debug) {
      /*
        if(px.Front >= MPXDV) Serial.print("*");
        Serial.print("Front PX: ");
        Serial.println(px.Front);
        if(px.Left >= MPXDV) Serial.print("*");
        Serial.print("Left PX: ");
        Serial.println(px.Left);
        if(px.Right >= MPXDV) Serial.print("*");
        Serial.print("Right PX: ");
        Serial.println(px.Right);

        long num = 0;
        for(int i=0; i<1000; i++) {
          px.read();
          num += px.Left;
        }
        Serial.println(num);
        num = num / 1000;
        Serial.println(num);
        */

        /*int key = ir.read([](){
        }); Serial.println(key);*/

        //Compass
        Serial.print("C\t");
        Serial.println(c.val[0]);

        //Line Detector
        Serial.print("LD\tL");
        Serial.print(digitalRead(MLDL));
        Serial.print("\tR");
        Serial.println(digitalRead(MLDR));

        //PX
        Serial.print("PX \tF");
        Serial.print(px.Front);
        Serial.print("\tL");
        Serial.print(px.Left);
        Serial.print("\tR");
        Serial.println(px.Right);

        //TPA81
        Serial.print("\nTS \tA");
        Serial.println(ts.read(0));
        Serial.print("TS2 \t");
        Serial.print(ts.read(1));
        Serial.print("\t");
        Serial.println(ts.read(2));
        Serial.print("TS4 \t");
        Serial.print(ts.read(3));
        Serial.print("\t");
        Serial.println(ts.read(4));
        Serial.print("TS6 \t");
        Serial.print(ts.read(5));
        Serial.print("\t");
        Serial.println(ts.read(6));
        Serial.print("TS8 \t");
        Serial.print(ts.read(7));
        Serial.print("\t");
        Serial.println(ts.read(8));

        //delay(1000);
        delay(400);
        Serial.write(27);
        Serial.print("[2J"); // clear screen
        Serial.write(27); // ESC
        Serial.print("[H");
        return;
    }

    m.forward(LEFT, 50);
    m.backward(RIGHT, 50);
    const unsigned int cv = c.read()[0];
    const unsigned int acv = cv + 120;
    bool bcv = false;
    int pang;
    int ang;
    if(acv > 360) {
        pang = acv - 360;
        bcv = true;
    }
    else pang = acv;
    while(ang < 120 && ang != 359) {
        if(bcv && cv > c.read()[0]) {
            ang = 360 - abs(cv - c.read()[0]);
        }
        else ang = c.read()[0] - cv;
        Serial.print(c.read()[0]);
        Serial.print("\t");
        Serial.println(ang);
    }
    m.forward(0);
    delay(100);
    //ai.isInsideRoom(m);
    //m.forward(0);

    /*
    if(px.Front >= MPXDV) {
        if(px.Left >= MPXDV || px.Right >= MPXDV) {
            if(px.Left >= MPXDV && px.Right >= MPXDV) {
                while(px.Left >= MPXDV && px.Right >= MPXDV) {
                    if(px.Left > px.Right) {
                        m.backward(LEFT, 128);
                        m.backward(RIGHT, 255);
                    } else if (px.Left < px.Right) {
                        m.backward(LEFT, 255);
                        m.backward(RIGHT, 128);
                    }
                    else m.backward(255);

                    px.read();
                }
                delay(MPXMLV);
                const unsigned int cv = c.read()[0];

                if(px.Left >= MPXDV) {
                    while(abs(c.read()[0] - cv) <= 90) {
                        m.forward(LEFT, 255);
                        m.backward(RIGHT, 255);
                    }
                } else if(px.Right >= MPXDV) {
                    while(abs(c.read()[0] - cv) <= 90) {
                        m.backward(LEFT, 255);
                        m.forward(RIGHT, 255);
                    }
                }
            } else {
                const unsigned int cv = c.val;

                if(px.Left >= MPXDV) {
                    while(abs(c.read()[0] - cv) <= 90) {
                        m.forward(LEFT, 255);
                        m.backward(RIGHT, 255);
                    }
                } else if(px.Right >= MPXDV) {
                    while(abs(c.read()[0] - cv) <= 90) {
                        m.backward(LEFT, 255);
                        m.forward(RIGHT, 255);
                    }
                }
            }
        } else {
            m.backward(LEFT, 128);
            m.backward(RIGHT, 255);
        }
    } else if(px.Left >= MPXDV || px.Right >= MPXDV) {
        if(px.Left >= MPXDV && px.Right >= MPXDV) {
            if(px.Left > px.Right) {
                m.forward(LEFT, 255);
                m.forward(RIGHT, 128);
            } else if (px.Left < px.Right) {
                m.forward(LEFT, 128);
                m.forward(RIGHT, 255);
            }
            else m.forward(255);
        } else if(px.Left >= MPXDV) {
            m.forward(LEFT, 255);
            m.forward(RIGHT, MMMIN);
        } else if(px.Right >= MPXDV) {
            m.forward(LEFT, MMMIN);
            m.forward(RIGHT, 255);
        }
    } else m.forward(255);*/
}
