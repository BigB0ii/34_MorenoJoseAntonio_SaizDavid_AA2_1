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
	void print() {
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numColumns; j++) {
				std::cout << static_cast<char>(map[i][j]);
			}
			std::cout << std::endl;
		}
	}


};