#pragma once
#include "Fructe.h"

class Cocos: virtual public Fructe{
private:
	int valoare;
	static int suma;
public:
	Cocos(int x, int y, sf::Color culoare, int valoare) :Fructe(x, y, culoare), valoare(valoare) {};
	int getValoare();
	void superPower(Minion& minion) override;
	void increaseValue(int valoare);
};