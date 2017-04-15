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

/**
     Init Code
*/
void setup() {
  Serial.begin(MSS);
  FastLED.addLeds<NEOPIXEL, 13>(rgb_strip, MRGBLN);
}

/**
     Loop Code
*/
void loop() {
    int i;
    int j = 255;
    for(i = 0; i < 255; i++)
    {
        rgb_strip[0] = CRGB(i,0,0);
        rgb_strip[1] = CRGB(j,0,0);
        FastLED.show();
        j--;
    }
    for(int i = 255; i > 0; i--)
    {
        rgb_strip[0] = CRGB(i,0,0);
        rgb_strip[1] = CRGB(j,0,0);
        FastLED.show();
        j++;
    }
}
