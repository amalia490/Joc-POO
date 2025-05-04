#include "Cells.h"

Cells::Cells(int x, int y, sf::Color){
	this->x = x;
	this->y = y;
}

int Cells::getX() {
	return x;
}

int Cells::getY() {
	return y;
}