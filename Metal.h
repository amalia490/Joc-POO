#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stack>
#include "Gheata.h"
#include "Coordonate.h"

class Metal:public Gheata{
private:
	static int suma;
public:
	Metal(int x, int y) : Gheata(x, y){};
	void power(Minion& minion) override;
};
