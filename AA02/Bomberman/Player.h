#pragma once
#include "Types.h"
class Player {
private:
	int score;
	Position position;
public:
	Player(){}
	Player(Position _position) :position(_position), score(0) {}
};
