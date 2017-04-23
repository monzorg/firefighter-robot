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
    analogButtons.add(sbtn);
    FastLED.addLeds<NEOPIXEL, 13>(rgb_strip, MRGBLN);
    Serial.begin(MSS);
    //Scheduler.startLoop([]{Serial.println(c.read());});

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
        Serial.print("Compass: ");
        Serial.println(c.val);
        if(px.Front >= MPXDV) Serial.print("*");
        Serial.print("Front PX: ");
        Serial.println(px.Front);
        if(px.Left >= MPXDV) Serial.print("*");
        Serial.print("Left PX: ");
        Serial.println(px.Left);
        if(px.Right >= MPXDV) Serial.print("*");
        Serial.print("Right PX: ");
        Serial.println(px.Right);
    }
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
                const unsigned int cv = c.read();

                if(px.Left >= MPXDV) {
                    while(abs(c.read() - cv) <= 90) {
                        m.forward(LEFT, 255);
                        m.backward(RIGHT, 255);
                    }
                } else if(px.Right >= MPXDV) {
                    while(abs(c.read() - cv) <= 90) {
                        m.backward(LEFT, 255);
                        m.forward(RIGHT, 255);
                    }
                }
            } else {
                const unsigned int cv = c.val;

                if(px.Left >= MPXDV) {
                    while(abs(c.read() - cv) <= 90) {
                        m.forward(LEFT, 255);
                        m.backward(RIGHT, 255);
                    }
                } else if(px.Right >= MPXDV) {
                    while(abs(c.read() - cv) <= 90) {
                        m.backward(LEFT, 255);
                        m.forward(RIGHT, 255);
                    }
                }
            }
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
    } else m.forward(255);
}
