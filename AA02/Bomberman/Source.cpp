#include "Player.h"
#include "Map.h"
#include "InputManager.h"

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

		if (input.keys[(int)InputKey::UP]) {
			std::cout << "INPUT OK" << std::endl;

			if (map.CheckMove(p1.GetPos(), InputKey::UP)) {

				Position nextMove = p1.NextMove(InputKey::UP);

				//Cambiar posición tablero
				map.Move(p1, nextMove);


				//Cambiar posición del player
				p1.SetPos(nextMove);



			}

		}

		//Print
		system("cls");
		map.Print();


	}
	return 0;
}