#include "Obstacole.h"

Obstacole::Obstacole(int x, int y):x(x), y(y){
	coordonate.push_back(Coordonate(x, y));
    std::cout << x << " " << y << std::endl;
}

int Obstacole::getX() {
    return x;
}

int Obstacole::getY() {
    return y;

}
