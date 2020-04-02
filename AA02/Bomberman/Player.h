#pragma once
#include "InputManager.h"

class Player {
private:
	char pChar;
	int score;

public:
	Position position;
	InputKey input;

	Player(char _pChar);

	//FUNCIONES
	void PrintScore() const;

	char GetpChar() const;
};
