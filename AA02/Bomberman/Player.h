#pragma once
#include "Types.h"
class Player {
private:
	char pChar;
	int score;
	Position position;

public:
	

	Player(char _pChar) {
		pChar = _pChar;
		position.x = 0;
		position.y = 0;
		score = 0;
	}


	//FUNCIONES

	//Recibe el proximo movimiento y devuelve su proxima pos
	Position NextMove(InputKey movement) {
		Position newPos = position;
			switch (movement)
			{
			case InputKey::UP:
			case InputKey::W:
				newPos.y++;
				return newPos;
				break;
			case InputKey::DOWN:
			case InputKey::S:
				newPos.y--;
				return newPos;
				break;
			case InputKey::LEFT:
			case InputKey::A:
				newPos.x--;
				return newPos;
				break;
			case InputKey::RIGHT:
			case InputKey::D:
				newPos.x++;
				return newPos;
				break;
			default:
				return newPos;
				break;
			}
	}


	void SetPos(Position _position) {
		position = _position;
	}

	void SetPos(int x, int y) {
		position.x = x;
		position.y = y;
	}

	Position GetPos() {
		return position;
	}

	char GetpChar();
};
