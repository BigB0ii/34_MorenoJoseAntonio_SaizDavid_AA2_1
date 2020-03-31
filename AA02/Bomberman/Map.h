#pragma once
#include <iostream>
#include <fstream>
#include "Types.h"


class Map {
private:
	Cell **map;
	int numRows, numColumns;

public:
	//CONSTRUCTOR static_cast<int>(...lo que se quiere transformar en int)

	Map() {
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

	//FUNCIONES
	bool CheckMove(Position pPos, InputKey movement) {
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
			if (map[pPos.y][pPos.x- 1] == Cell::NOTHING) {
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


	/*
	if (input) {
		if (checkMove(player, input)) {
			
			pos nextMove = p.nextMove()

			//Cambiar posición tablero
				map.move(Player player){	
					map[player.getPos().x][player.getPos().y] = NOTHING

			//Cambiar posición del player
			player.setPos(nextMove);
			
			
		}
	}
	*/

	void Move(Player player, Position nextMove) {
		map[player.GetPos().y][player.GetPos().x] = Cell::NOTHING;
		map[nextMove.y][nextMove.x] = static_cast<Cell>(player.GetpChar());
	}


	void FindPlayer(Player player) {
		char _pChar = player.GetpChar();

		for (int i = 0; i < numRows; i++)
			for (int j = 0; j < numColumns; j++)
				if (static_cast<char>(map[i][j]) == _pChar) {
					player.SetPos(j, i);
				}
	}
	

	


	void Print() {
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numColumns; j++) {
				std::cout << static_cast<char>(map[i][j]);
			}
			std::cout << std::endl;
		}
	}


};