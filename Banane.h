#pragma once
#include "Fructe.h"

class Banane : virtual public Fructe{
private:
	int speed;
public:
	Banane(int x, int y, sf::Color culoare, int speed) :Fructe(x, y, culoare), speed(speed){};
	int getSpeed();
	void superPower(Minion& minion) override;
	void increaseSpeed();
};