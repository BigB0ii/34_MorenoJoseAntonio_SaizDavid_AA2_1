#pragma once
#include "Types.h"
#include <iostream>
class Player {
private:
	char pChar;
	int score;
	Position position;
	InputKey input;

public:
	
	Player(char _pChar) {
		pChar = _pChar;
		position.x = 0;
		position.y = 0;
		score = 0;
	}

	//FUNCIONES

	void SetInput(InputKey _input);

	InputKey GetInput();

	void SetPos(Position _position); 

	void SetPos(int x, int y);

	Position GetPos();

	void PrintScore();

	char GetpChar();
};
