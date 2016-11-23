/**
     /\/\   ___  _ __  _______  _ __ __ _ 
    /    \ / _ \| '_ \|_  / _ \| '__/ _` |
   / /\/\ \ (_) | | | |/ / (_) | | | (_| |
   \/    \/\___/|_| |_/___\___/|_|  \__, |
                                    |___/ 
  Firefighter Robot
  Core.ino
  Firefighter Robot firmware based on Arduino Board
  
  @repo firefighter-robot
  @license MIT License
  @authors "Filipe Laíns" <filipe.lains@gmail.com>
  @authors "Luís Ferreira" <lsferreira169@gmail.com>
  @version ALPHA 0.5 23/11/2016
*/

// External Libraries
#include <FastLED.h>
#include <SharpIR.h>
//#include <Wire.h>

#define DATA_LED_PIN 13
#define RGB_PIN 13

#define PX_F 0  // A0 - Front Side
#define PX_L 1  // A1 - Left Side
#define COMPASS_ADDRESS 0x60 //defines address of compass
#define NUM_RGB_LEDS   2

enum Direction {
  RIGHT,
  LEFT
};

// Objects
CRGB rgb_strip[NUM_RGB_LEDS];

/**
     Setup Code
*/
void setup() {
  Motor m(7, 4, 6, 5);
  Serial.begin(9600);
}

/**
     Loop Code
*/
void loop() {
  
}
