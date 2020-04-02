#pragma once
#include <fstream>
#include "Player.h"

class Map {
private:
	Cell **map;
	int numRows, numColumns;

public:
	Map();

	//FUNCIONES

	//Comprueva que el jugador pueda moverse según su posición y el input que recibe
	bool CheckMove(const Position &pPos,const InputKey &movement) const;

	//Mueve al jugador en el mapa y devuelve su nueva posición
	Position MovePlayer(const Position &pPos, const InputKey &nextMove, const char &pChar);

	//Encuentra al player en el mapa y le iguala su posición a la del mapa
	void FindPlayer(Player &player) const;

	void Print() const;

};