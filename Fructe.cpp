#include "Fructe.h"
#include <iostream>

Fructe::Fructe(int x, int y, sf::Color culoare):x(x), y(y), culoare(culoare) {
    std::cout << x << " " << y << std::endl;
};

int Fructe::getX() {
    return x;
}

int Fructe::getY() {
    return y;

}

sf::Color Fructe::getCuloare() {
    return culoare;
}
