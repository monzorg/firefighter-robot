#pragma once

#include "motor.h"

class AI {
	bool room;
public:
	AI();
	~AI();
	void FollowWalls(int ,int );
	void FollowRightWall();
	void FollowLeftWall();
	void InsideRoom(Motor );
	bool isInsideRoom();
};
