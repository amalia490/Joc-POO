#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Minion.h"

class Fructe {
private:
    int x = 0, y = 0;
    sf::Color culoare;
public:
    Fructe(int x, int y, sf::Color culoare);
    virtual void superPower(Minion& minion)=0;
    int getX();
    int getY();
    sf::Color getCuloare();
    virtual ~Fructe(){}
};
