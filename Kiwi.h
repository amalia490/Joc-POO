#pragma once
#include "Fructe.h"
#include "Banane.h"
#include "Cocos.h"

class Kiwi: virtual public Banane, virtual public Cocos{
private:
	int half_life;
	static int suma;
public:
	Kiwi(int x, int y, sf::Color culoare, int valoare, int speed, int half_life) :Fructe(x, y, culoare), Banane(x, y, culoare, speed), Cocos(x, y, culoare, valoare), half_life(half_life) {};
	int getHalf_life();
	void superPower(Minion& minion);
	void increaseLives();
};