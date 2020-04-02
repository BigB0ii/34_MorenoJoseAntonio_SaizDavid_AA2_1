#pragma once
struct Position {
	int x;
	int y;
};

enum class Cell{BLOC = 'X', MUR = '*', NOTHING = ' ', JUGADOR1 = '1', JUGADOR2 = '2' };

enum class InputKey { UP, DOWN, LEFT, RIGHT, W, A, S, D, ESC, COUNT };

