#pragma once

#include "motor.h"
#include "px.h"
#include "tpa81.h"
#include "global.h"

enum Map {
	KNOWN, //1
	KNOWN_RETURN, //2
	UNKNOWN //3
};

class AI {
	bool room;
	bool candle;
    Map map;

public:
	AI(Map );
	~AI();
	void init(Motor , PX , TPASensor );

private:
    void update();
	void FollowWalls(PX );
	void FollowWall(PX , Direction );
	void InsideRoom(Motor );
	void searchCandle(Motor , TPASensor );
	void searchRoom(Motor );
	bool isInsideRoom();

	//dependencies
    void checkCandle(Motor , TPASensor );
	bool detectColoredSpace(Motor );
};
