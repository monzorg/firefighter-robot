#include "AI.h"
#include "config.h"
#include "arduinoConfig.h"

AI::AI() {
	room = false;
}

AI::~AI() {

}

void AI::FollowWalls(int l, int r) {

}

inline bool AI::isInsideRoom() {
	return room;
}

void AI::InsideRoom(Motor m) {
	if(digitalRead(MLDL) != MLDI && digitalRead(MLDR) != MLDI) {
		if(room == false) room = true;
		else room = false;
		while(digitalRead(MLDL) != MLDI && digitalRead(MLDR) != MLDI) m.forward();
	}
}
