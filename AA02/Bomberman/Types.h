#pragma once
class Position {
private:
	int x;
	int y;
public:
	Position() {}
	Position(int _x, int _y) {
		x = _x;
		y = _y;
	}
};

enum class Cell{BLOC = 'X', MUR = '*', NOTHING = ' ', JUGADOR1 = '1', JUGADOR2 = '2' };

