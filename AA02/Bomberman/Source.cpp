#include "Player.h"
#include "Map.h"
#include "InputManager.h"
#include <Windows.h>

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
			p1.SetInput(InputKey::UP);
			if (map.CheckMove(p1.GetPos(), p1.GetInput())) {
				p1.SetPos(map.MovePlayer(p1.GetPos(), p1.GetInput()));
				



			}

		}
		if (input.keys[(int)InputKey::RIGHT]) {
			p1.SetInput(InputKey::RIGHT);
			if (map.CheckMove(p1.GetPos(), p1.GetInput())) {
				p1.SetPos(map.MovePlayer(p1.GetPos(), p1.GetInput()));




			}

		}
		if (input.keys[(int)InputKey::LEFT]) {
			p1.SetInput(InputKey::LEFT);
			if (map.CheckMove(p1.GetPos(), p1.GetInput())) {
				p1.SetPos(map.MovePlayer(p1.GetPos(), p1.GetInput()));




			}

		}
		if (input.keys[(int)InputKey::DOWN]) {
			p1.SetInput(InputKey::DOWN);
			if (map.CheckMove(p1.GetPos(), p1.GetInput())) {
				p1.SetPos(map.MovePlayer(p1.GetPos(), p1.GetInput()));




			}
		}
		#pragma endregion
		#pragma region PLAYER 2
		if (input.keys[(int)InputKey::W]) {
			p2.SetInput(InputKey::W);
			if (map.CheckMove(p2.GetPos(), p2.GetInput())) {
				p2.SetPos(map.MovePlayer(p2.GetPos(), p2.GetInput()));




			}

		}if (input.keys[(int)InputKey::A]) {
			p2.SetInput(InputKey::A);
			if (map.CheckMove(p2.GetPos(), p2.GetInput())) {
				p2.SetPos(map.MovePlayer(p2.GetPos(), p2.GetInput()));




			}

		}
		if (input.keys[(int)InputKey::S]) {
			p2.SetInput(InputKey::S);
			if (map.CheckMove(p2.GetPos(), p2.GetInput())) {
				p2.SetPos(map.MovePlayer(p2.GetPos(), p2.GetInput()));




			}

		}
		if (input.keys[(int)InputKey::D]) {
			p2.SetInput(InputKey::D);
			if (map.CheckMove(p2.GetPos(), p2.GetInput())) {
				p2.SetPos(map.MovePlayer(p2.GetPos(), p2.GetInput()));




			}

		}
		#pragma endregion
		//Print
		system("cls");
		map.Print();
		p1.PrintScore();
		p2.PrintScore();
		Sleep(50);
    }
	return 0;
} 
