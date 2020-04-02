#include "Map.h"
#include "Constants.h"


int main() {
	Map map;
	Player p1('1');
	Player p2('2');

	bool endgame = false;
	InputData input;

	map.FindPlayer(p1);
	map.FindPlayer(p2);

	//primer print
	map.Print();

	//GAME LOOP
	while (!endgame)
	{
			//Input
		input.Update();
		
			//Update --> game logic
		#pragma region PLAYER 1
		if (input.keys[(int)InputKey::UP]) {
			p1.input = InputKey::UP;
			if (map.CheckMove(p1.position, p1.input)) {
				p1.position = map.MovePlayer(p1.position, p1.input, p1.GetpChar());
			}

		}
		if (input.keys[(int)InputKey::RIGHT]) {
			p1.input = InputKey::RIGHT;
			if (map.CheckMove(p1.position, p1.input)) {
				p1.position = map.MovePlayer(p1.position, p1.input, p1.GetpChar());
			}

		}
		if (input.keys[(int)InputKey::LEFT]) {
			p1.input = InputKey::LEFT;
			if (map.CheckMove(p1.position, p1.input)) {
				p1.position = map.MovePlayer(p1.position, p1.input, p1.GetpChar());
			}

		}
		if (input.keys[(int)InputKey::DOWN]) {
			p1.input = InputKey::DOWN;
			if (map.CheckMove(p1.position, p1.input)) {
				p1.position = map.MovePlayer(p1.position, p1.input, p1.GetpChar());
			}
		}
		#pragma endregion
		#pragma region PLAYER 2
		if (input.keys[(int)InputKey::W]) {
			p2.input = InputKey::W;
			if (map.CheckMove(p2.position, p2.input)) {
				p2.position = map.MovePlayer(p2.position, p2.input, p2.GetpChar());
			}

		}if (input.keys[(int)InputKey::A]) {
			p2.input = InputKey::A;
			if (map.CheckMove(p2.position, p2.input)) {
				p2.position = map.MovePlayer(p2.position, p2.input, p2.GetpChar());
			}

		}
		if (input.keys[(int)InputKey::S]) {
			p2.input = InputKey::S;
			if (map.CheckMove(p2.position, p2.input)) {
				p2.position = map.MovePlayer(p2.position, p2.input, p2.GetpChar());
			}

		}
		if (input.keys[(int)InputKey::D]) {
			p2.input = InputKey::D;
			if (map.CheckMove(p2.position, p2.input)) {
				p2.position = map.MovePlayer(p2.position, p2.input, p2.GetpChar());
			}

		}
		#pragma endregion
		
			//Print
		system("cls");
		map.Print();
		p1.PrintScore();
		p2.PrintScore();
		Sleep(frameTime);
    }
	return 0;
} 
