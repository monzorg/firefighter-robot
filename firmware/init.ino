/**
**   /\/\   ___  _ __  _______  _ __ __ _ 
**  /    \ / _ \| '_ \|_  / _ \| '__/ _` |
** / /\/\ \ (_) | | | |/ / (_) | | | (_| |
** \/    \/\___/|_| |_/___\___/|_|  \__, |
**                                  |___/ 
** Firefighter Robot
** Firefighter Robot firmware based on Arduino Board
** 
** @repo firefighter-robot
** @license MIT License
** @authors "Filipe Laíns" <filipe.lains@gmail.com>
** @authors "Luís Ferreira" <lsferreira169@gmail.com>
*/

// External Libraries
#include <FastLED.h>

#include "config.h"

CRGB rgb_strip[MRGBLN];

void setup() {
  Serial.begin(MSS);
}
