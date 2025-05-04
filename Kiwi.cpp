#include "Kiwi.h"


int Kiwi::getHalf_life() {
	return half_life;
}

int Kiwi::suma = 0;

void Kiwi::superPower(Minion& minion) {
	/*std::cout << "NU" << std::endl;
	minion.jump(453, 550);
	suma = 5 + minion.getKiwiP();
	minion.setKiwiP(suma);
	std::cout << suma << std::endl;*/
	Cocos::superPower(minion);
	Banane::superPower(minion);
	suma = 1 + minion.getKiwiP();
	minion.setKiwiP(suma);
	std::cout << suma << std::endl;
}

void Kiwi::increaseLives() {
	half_life = 0;
}