#include "Map.h"

bool Map::CheckMove(Position pPos, InputKey movement) {
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
Position Map::MovePlayer(Position pPos, InputKey nextMove) {
	Position nextPos = pPos;
	map[pPos.y][pPos.x] = Cell::NOTHING;
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
	if (nextMove == InputKey::UP || nextMove == InputKey::DOWN || nextMove == InputKey::LEFT || nextMove == InputKey::RIGHT) {
		map[nextPos.y][nextPos.x] = Cell::JUGADOR1;
	}
	else if (nextMove == InputKey::W || nextMove == InputKey::S || nextMove == InputKey::A || nextMove == InputKey::D) {
		map[nextPos.y][nextPos.x] = Cell::JUGADOR2;
	}
	return nextPos;

}

void Map::FindPlayer(Player &player) {
	char _pChar = player.GetpChar();
	bool stop = false;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numColumns; j++)
			if (static_cast<char>(map[i][j]) == _pChar) {
				player.SetPos(j, i);
				stop = true;
			}
		if (stop)
			break;
	}
}

void Map::Print() {
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
		std::cout << std::endl;
	}
}
}