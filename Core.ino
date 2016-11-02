#include <FastLED.h>
#include "PitchesNotes.h"

#define NUM_RGB_LEDS  2
#define DATA_LED_PIN  13
#define RGB_PIN       13
#define BUZZER_PIN    8

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
   for(int i = 1000 ; i < 2000; i++)
    {
      tone(8, i);
      delay(1);
    }
    for(int i = 2000 ; i > 1000; i--)
    {
      tone(8, i);
      delay(1);
    }
    Serial.println(analogRead(2));
    delay(300);
}
