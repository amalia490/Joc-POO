#include "Cocos.h"

int Cocos::getValoare() {
	return valoare;
}

int Cocos::suma = 0;

void Cocos::superPower(Minion& minion) {
	suma = 5 + minion.getPuncte();
	minion.setPuncte(suma);
	std::cout << suma << std::endl;

};
