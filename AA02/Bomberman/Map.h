#pragma once
#include <iostream>
#include <fstream>
#include "Types.h"
#include <Windows.h>
#include "Player.h"

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
	bool CheckMove(Position pPos, InputKey movement);

	Position MovePlayer(Position pPos, InputKey nextMove);

	void FindPlayer(Player &player);

	void Print();

};