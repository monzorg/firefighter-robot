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
#define BUZZER         8  // D8
#define LEFT_MOTOR     7  // D7 ///TODO: Know if it's correct!
#define RIGHT_MOTOR    4  // D4 ///TODO: Know if it's correct!
#define IR_PROXIMITY_1 0  // A0 ///Front Side
#define IR_PROXIMITY_2 1  // A1 ///Left Side

#define IR_PROXIMITY_MODEL 430 // GP2YA41SK0F ///TODO: Need to be confirmed!
#define NUM_RGB_LEDS   2

///Objects
SharpIR proximity1(IR_PROXIMITY_1, IR_PROXIMITY_MODEL);
SharpIR proximity2(IR_PROXIMITY_2, IR_PROXIMITY_MODEL);
CRGB rgb_strip[NUM_RGB_LEDS];

void setup() {
  // put your setup code here, to run once:
  //pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  FastLED.addLeds<NEOPIXEL, RGB_PIN>(rgb_strip, NUM_RGB_LEDS);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  analogWrite(6, 255);
  analogWrite(5, 200);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  /*// put your main code here, to run repeatedly:
  leds[0].setRGB( 10, 10, 10);
  FastLED.show();
  delay(300);
  leds[1].setRGB( 10, 10, 10);
  FastLED.show();
  digitalWrite(13,HIGH);
  delay(300);
  digitalWrite(13,LOW);
  delay(300);*/
   /*for(int i = 1000 ; i < 2000; i++)
    {
      tone(8, i);
      delay(1);
    }
    for(int i = 2000 ; i > 1000; i--)
    {
      tone(8, i);
      delay(1);
  }*/
    /*Serial.println(analogRead(2));
    delay(300);*/

    //Serial.println(analogRead(A0)); //lim 300
    //Serial.println(analogRead(A1)); //lim 150

    if (analogRead(IR_PROXIMITY_1) > 300){
      if(analogRead(IR_PROXIMITY_2) > 150){
        delay(300);

      }
    }
    delay(200);
}

enum Direction{
  RIGHT,
  LEFT
};

inline void rotate(Direction d){
  switch(d){
    case RIGHT:
      digitalWrite(4, HIGH);
      digitalWrite(7, LOW);
      break;
    case LEFT:
      digitalWrite(4, LOW);
      digitalWrite(7, HIGH);
      break;
  }
}
