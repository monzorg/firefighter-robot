//   /\/\   ___  _ __  _______  _ __ __ _  | @repo firefighter-robot
//  /    \ / _ \| '_ \|_  / _ \| '__/ _` | | Firefighter Robot firmware based on Arduino Board
// / /\/\ \ (_) | | | |/ / (_) | | | (_| | | @license MIT License
// \/    \/\___/|_| |_/___\___/|_|  \__, | | @authors "Luís Ferreira" <lsferreira169@gmail.com>
//                                  |___/  | @authors "Filipe Laíns" <filipe.lains@gmail.com>

///External Libraries
#include <FastLED.h>
#include <SharpIR.h>

///Includes
#include "PitchesNotes.h"

///Constants
#define DATA_LED_PIN   13 // D13
#define RGB_PIN        13 // D13
#define MOTOR_LEFT     7  // D7 ///TODO: Know if it's correct!
#define MOTOR_RIGHT    4  // D4 ///TODO: Know if it's correct!
#define PX_F 0  // A0 ///Front Side
#define PX_L 1  // A1 ///Left Side

#define IR_PROXIMITY_MODEL 430 // GP2YA41SK0F ///TODO: Need to be confirmed!
#define NUM_RGB_LEDS   2

///Objects
CRGB rgb_strip[NUM_RGB_LEDS];

void setup() {
  // put your setup code here, to run once:
  //pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  FastLED.addLeds<NEOPIXEL, RGB_PIN>(rgb_strip, NUM_RGB_LEDS);
  pinMode(MOTOR_LEFT, OUTPUT);
  pinMode(MOTOR_RIGHT, OUTPUT);
  digitalWrite(MOTOR_RIGHT, LOW);
  pinMode(NUM_RGB_LEDS, INPUT);
  Serial.begin(9600);
}

void loop() {
    if (analogRead(SENSOR_FRONT) > 300){
      if(analogRead(SENSOR_LEFT) > 150){
          
      } else {
        
      }
    }
    delay(200);
}

enum Direction{
  RIGHT,
  LEFT,
  FRONT
};

inline void rotate(Direction d){
  delay(300);
  switch(d){
    case RIGHT:
      digitalWrite(MOTOR_RIGHT, HIGH);
      digitalWrite(MOTOR_LEFT, LOW);
      break;
    case LEFT:
      digitalWrite(MOTOR_RIGHT, LOW);
      digitalWrite(MOTOR_LEFT, HIGH);
      break;
    case FRONT:
      digitalWrite(MOTOR_RIGHT, HIGH);
      digitalWrite(MOTOR_LEFT, HIGH);
      break;
  }
}

inline void walk(){
  analogWrite(MOTOR_RIGHT, 255);
  analogWrite(MOTOR_RIGHT, 255);
}
