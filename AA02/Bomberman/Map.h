#pragma once
#include <iostream>
#include <fstream>
#include "Types.h"


class Map {
private:
	char **map;
	int numRows, numColumns;

public:
	//CONSTRUCTOR
	Map() {
		
		std::ifstream myFile("config.txt");
		

		if (myFile.is_open())
		{
			if (!myFile.eof())
			{
				myFile >> numRows;
				myFile.ignore();
				myFile >> numColumns;

				map = new char*[numRows];

				for (int i = 0; i < numRows; i++) {
					map[i] = new char[numColumns];
				}

				myFile.ignore();

					for (int i = 0; i < numRows; i++) {
						for (int j = 0; j < numColumns; j++) {
							myFile.get(map[i][j]) >> std::noskipws;
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
				std::cout << map[i][j];
			}
			std::cout << std::endl;
		}
	}


};