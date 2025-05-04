#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stack>

class Cells {
private:
	float x, y;
public:
	Cells(int x, int y, sf::Color);
	int getX();
	int getY();
};
