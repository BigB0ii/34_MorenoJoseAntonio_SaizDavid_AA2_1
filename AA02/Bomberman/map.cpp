#include "Map.h"

Map::Map() {
	std::ifstream myFile("config.txt");
	if (myFile.is_open())
	{
		if (!myFile.eof())
		{
			myFile >> numRows;
			myFile.ignore();
			myFile >> numColumns;

			map = new Cell *[numRows];

			for (int i = 0; i < numRows; i++) {
				map[i] = new Cell[numColumns];
			}

			myFile.ignore();
			char temp;

			for (int i = 0; i < numRows; i++) {
				for (int j = 0; j < numColumns; j++) {
					myFile.get(temp) >> std::noskipws;
					map[i][j] = static_cast<Cell>(temp);
				}
				myFile.ignore();
			}

		}
		myFile.close();
	}
	else std::cout << "Unable to open file";

}

bool Map::CheckMove(const Position &pPos,const InputKey &movement) const {
	switch (movement)
	{
	case InputKey::UP:
	case InputKey::W:
		if (map[pPos.y - 1][pPos.x] == Cell::NOTHING) {
			return true;
		}
		else {
			return false;
		}
		break;
	case InputKey::DOWN:
	case InputKey::S:
		if (map[pPos.y + 1][pPos.x] == Cell::NOTHING) {
			return true;
		}
		else {
			return false;
		}
		break;
	case InputKey::LEFT:
	case InputKey::A:
		if (map[pPos.y][pPos.x - 1] == Cell::NOTHING) {
			return true;
		}
		else {
			return false;
		}
		break;
	case InputKey::RIGHT:
	case InputKey::D:
		if (map[pPos.y][pPos.x + 1] == Cell::NOTHING) {
			return true;
		}
		else {
			return false;
		}
		break;
	default:
		return false;
		break;
	}
}
Position Map::MovePlayer(const Position &pPos,const InputKey &nextMove,const char &pChar){
	Position nextPos = pPos;
	//LA POSICIÓN ANTERIOR DEL PLAYER LA BORRA
	map[pPos.y][pPos.x] = Cell::NOTHING;


	//SEGÚN EL INPUT MODIFICA LA nextPos
	switch (nextMove)
	{
	case InputKey::UP:
	case InputKey::W:
		nextPos.y--;
		break;
	case InputKey::DOWN:
	case InputKey::S:
		nextPos.y++;
		break;
	case InputKey::LEFT:
	case InputKey::A:
		nextPos.x--;
		break;
	case InputKey::RIGHT:
	case InputKey::D:
		nextPos.x++;
		break;
	default:
		return nextPos;
		break;
	}

	//SI ES EL PLAYER 1 CAMBIA LA POS DEL P1 y SI ES DEL 2 LA DEL 2
	if (pChar == '1') {
		map[nextPos.y][nextPos.x] = Cell::JUGADOR1;
	}
	else if (pChar == '2') {
		map[nextPos.y][nextPos.x] = Cell::JUGADOR2;
	}
	return nextPos;

}

void Map::FindPlayer(Player &player) const{
	char _pChar = player.GetpChar();
	bool stop = false;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numColumns; j++) {
			if (static_cast<char>(map[i][j]) == _pChar) {
				player.position.y = i;
				player.position.x = j;
				stop = true;
			}
			if (stop) break;
		}
	}
}

void Map::Print() const{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numColumns; j++) {
			switch (map[i][j])
			{
			case Cell::BLOC:
				SetConsoleTextAttribute(hConsole, 255);
				std::cout << ' ';
				break;
			case Cell::MUR:
				SetConsoleTextAttribute(hConsole, 200);
				std::cout << ' ';
				break;
			case Cell::NOTHING:
				SetConsoleTextAttribute(hConsole, 0);
				std::cout << ' ';
				break;
			case Cell::JUGADOR1:
				SetConsoleTextAttribute(hConsole, 80);
				std::cout << ' ';
				break;
			case Cell::JUGADOR2:
				SetConsoleTextAttribute(hConsole, 170);
				std::cout << ' ';
				break;
			default:
				break;
			}

		}
		SetConsoleTextAttribute(hConsole, 0);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
