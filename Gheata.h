#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stack>
#include "Piatra.h"

class Gheata:public Piatra{
private:
	static int suma;
public:
	Gheata(int x, int y) :Piatra(x, y) {};
	void power(Minion& minion) override;
};
