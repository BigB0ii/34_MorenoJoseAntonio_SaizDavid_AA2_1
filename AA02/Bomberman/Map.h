#pragma once
#include <fstream>
#include "Player.h"

class Map {
private:
	Cell **map;
	int numRows, numColumns;

public:
	//CONSTRUCTOR static_cast<int>(...lo que se quiere transformar en int)

	Map();

	//FUNCIONES
	bool CheckMove(const Position &pPos,const InputKey &movement) const;

	Position MovePlayer(const Position &pPos, const InputKey &nextMove, const char &pChar);

	void FindPlayer(Player &player) const;

	void Print() const;

};