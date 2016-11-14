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
  @version BETA 0.4 14/11/2016
*/

// External Libraries
#include <FastLED.h>

// Constants
#define DATA_LED_PIN   13 // D13
#define RGB_PIN        13 // D13
#define MOTOR_LEFT     7  // D7 - TODO: Know if it's correct!
#define MOTOR_RIGHT    4  // D4 - TODO: Know if it's correct!
#define PX_F 0  // A0 - Front Side
#define PX_L 1  // A1 - Left Side
#define NUM_RGB_LEDS   2

// Objects
CRGB rgb_strip[NUM_RGB_LEDS];

// Direction
enum Direction{
  RIGHT,
  LEFT,
  FRONT
};

/**
     Setup Code
*/
void setup() {
  //pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  FastLED.addLeds<NEOPIXEL, RGB_PIN>(rgb_strip, NUM_RGB_LEDS);
  pinMode(MOTOR_LEFT, OUTPUT);
  pinMode(MOTOR_RIGHT, OUTPUT);
  pinMode(NUM_RGB_LEDS, INPUT);
  Serial.begin(9600);
}

/**
     Loop Code
*/
void loop() {
    if (analogRead(SENSOR_FRONT) > 300){
      if(analogRead(SENSOR_LEFT) > 150){
          stop();
          rotate(RIGHT);
          walk();
      } else {
          stop();
          rotate(LEFT);
          walk();
      }
    } else {
      walk();
    }
    delay(200);
}

/**
     Rotates
     
     @param direction
*/
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

/**
     Walks
*/
inline void walk(){
  digitalWrite(MOTOR_RIGHT, HIGH);
  digitalWrite(MOTOR_LEFT, HIGH);
}

/**
     Walks
     
     @param speed
*/
inline void walk(int speed){
  analogWrite(MOTOR_RIGHT, speed);
  analogWrite(MOTOR_LEFT, speed);
}

/**
     Stops
*/
inline void stop(){
  digitalWrite(MOTOR_RIGHT, LOW);
  digitalWrite(MOTOR_LEFT, LOW);
}
