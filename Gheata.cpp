#include "Gheata.h"

int Gheata::suma = 0;

void Gheata::power(Minion& minion) {
	if (minion.getPuncte() - 20 >= 0)
		suma = minion.getPuncte() - 20;
	else
		suma = -1;
	minion.setPuncte(suma);
	std::cout << suma << std::endl;
}