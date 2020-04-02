#include "InputManager.h"

InputData::InputData() {
	keys[(int)InputKey::COUNT] = {};
}

void InputData::Update() {
	keys[(int)InputKey::ESC] = GetAsyncKeyState(VK_ESCAPE);

	//PLAYER 2
	keys[(int)InputKey::W] = GetAsyncKeyState('W');
	keys[(int)InputKey::A] = GetAsyncKeyState('A');
	keys[(int)InputKey::S] = GetAsyncKeyState('S');
	keys[(int)InputKey::D] = GetAsyncKeyState('D');

	//PLAYER 1
	keys[(int)InputKey::UP] = GetAsyncKeyState(VK_UP);
	keys[(int)InputKey::DOWN] = GetAsyncKeyState(VK_DOWN);
	keys[(int)InputKey::LEFT] = GetAsyncKeyState(VK_LEFT);
	keys[(int)InputKey::RIGHT] = GetAsyncKeyState(VK_RIGHT);




}