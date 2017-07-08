#include "AI.h"
#include "config.h"
#include "arduinoConfig.h"
#include "global.h"
#include "tpa81.h"

#include <FastLED.h>
extern CRGB rgb_strip[MRGBLN];

AI::AI(Map m) {
	map = m;
	room = false;
	candle = false;
}

AI::~AI() {

}

void AI::init(Motor m, PX px, TPASensor ts) {
	update();
	InsideRoom(m);
	if(this->isInsideRoom()) searchRoom(m);
	else searchCandle(m, ts);
}

void AI::update() {
	//...
}

bool AI::detectColoredSpace(Motor m) {
	m.forward(127);
    delay(750);
	if(digitalRead(MLDL) != MLDI && digitalRead(MLDR) != MLDI) {
		if(candle) {
			m.forward(200);
			while(digitalRead(MLDL) != MLDI && digitalRead(MLDR) != MLDI) {
			}
			m.backward(127);
			delay(550);
			m.forward(0);
			rgb_strip[0] = CRGB(0,50,50);
	        rgb_strip[1] = CRGB(0,50,50);
			FastLED.show();
			tone(8, 2300, 300);
		    delay(300 * 1.30);
		    noTone(8);
			rgb_strip[0] = CRGB(0,0,0);
		    rgb_strip[1] = CRGB(0,0,0);
		    FastLED.show();
		    tone(8, 2500, 100);
		    delay(100 * 1.30);
		    noTone(8);
			rgb_strip[0] = CRGB(0,50,50);
	        rgb_strip[1] = CRGB(0,50,50);
			FastLED.show();
		    tone(8, 2600, 100);
		    delay(100 * 1.30);
		    noTone(8);
			rgb_strip[0] = CRGB(0,0,0);
		    rgb_strip[1] = CRGB(0,0,0);
		    FastLED.show();
		    tone(8, 2500, 200);
		    delay(200 * 1.30);
		    noTone(8);
			rgb_strip[0] = CRGB(0,50,50);
	        rgb_strip[1] = CRGB(0,50,50);
			FastLED.show();
		    tone(8, 2600, 500);
		    delay(500 * 1.30);
		    noTone(8);
			rgb_strip[0] = CRGB(0,0,0);
		    rgb_strip[1] = CRGB(0,0,0);
		    FastLED.show();
		    delay(2000);
			asm volatile ( "jmp 0");
		}
		m.rrotate(RIGHT, 2);
		return true;
	} else {
		return false;
	}
}

void AI::FollowWalls(PX px) {

}

void AI::FollowWall(PX px, Direction wd) {

}

inline bool AI::isInsideRoom() {
	return room;
}

void AI::searchCandle(Motor m, TPASensor ts) {
	uint32_t resetTime;

	m.forward(LEFT, 127);
	m.backward(RIGHT, 127);
	resetTime = millis() + (unsigned long)(1 * MMRRD);
	while ( resetTime > millis()) {
		checkCandle(m, ts);
	}
	m.forward(RIGHT, 127);
	m.backward(LEFT, 127);
	resetTime = millis() + (unsigned long)(2 * MMRRD);
	while ( resetTime > millis()) {
		checkCandle(m, ts);
	}
	m.forward(LEFT, 127);
	m.backward(RIGHT, 127);
	resetTime = millis() + (unsigned long)(1 * MMRRD);
	while ( resetTime > millis()) {
		checkCandle(m, ts);
	}
}

void AI::checkCandle(Motor m, TPASensor ts) {
	if(abs(ts.read(1) - ts.read(0)) > 45) {
		m.forward(RIGHT, 30);
	    m.backward(LEFT, 30);
	}
	else if(abs(ts.read(8) - ts.read(0)) > 45) {
		m.forward(LEFT, 30);
	    m.backward(RIGHT, 30);
	}
	else return;
	candle = true;
}

void AI::searchRoom(Motor m) {

}

void AI::InsideRoom(Motor m) {
	if(digitalRead(MLDL) != MLDI && digitalRead(MLDR) != MLDI) {
		if(this->detectColoredSpace(m)) return;
		if(room == false) room = true;
		else room = false;
		while(digitalRead(MLDL) != MLDI && digitalRead(MLDR) != MLDI) m.forward();
	}
}
