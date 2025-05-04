#pragma once
#include "Coordonate.h"
#include "Minion.h"

class Obstacole {
private:
	std::vector<Coordonate> coordonate;
	int x, y;
public:
	Obstacole(int x, int y);
	virtual void power(Minion& minion)=0;
	int getX();
	int getY();
	//virtual ~Obstacole();
};
