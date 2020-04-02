#include "Player.h"

Player::Player(char _pChar) {
	pChar = _pChar;
	position.x = 0;
	position.y = 0;
	score = 0;
}


void Player::PrintScore() const{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 87);
	std::cout << "SCORE PLAYER" << pChar << ": " << score << std::endl;
	SetConsoleTextAttribute(hConsole, 0);
}
char Player::GetpChar() const{
	return pChar;
}

