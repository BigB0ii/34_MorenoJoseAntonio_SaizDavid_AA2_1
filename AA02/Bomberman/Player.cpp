#include "Player.h"

void Player::SetInput(InputKey _input){
	input = _input;
}
InputKey Player::GetInput()
{
	return InputKey();
}
void Player::SetPos(Position _position)
{
	position = _position;
}
void Player::SetPos(int x, int y) 
{
	position.x = x;
	position.y = y;
}
Position Player::GetPos() ç
{
	return position;
}
void Player::PrintScore() 
{
	std::cout << "SCORE PLAYER" << pChar << ": " << score << std::endl;
}
char Player::GetpChar()
{
	return pChar;
}

