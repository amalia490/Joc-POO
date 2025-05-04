#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stack>
#include "Coordonate.h"
#include "Obstacole.h"
class Piatra: public Obstacole {
private:
	int s;
public:
	Piatra(int x, int y) : Obstacole(x, y) {};
	void power(Minion& minion) override;
};
