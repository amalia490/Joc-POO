#include "Banane.h"

int Banane::getSpeed() {
	return speed;
}

void Banane::superPower(Minion& minion){
	std::cout << "NU" << std::endl;
	minion.jump(453, 550);
};

void Banane::increaseSpeed() {
	int y = 0;
}