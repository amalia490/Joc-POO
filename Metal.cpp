#include "Metal.h"

int Metal::suma = 0;

void Metal::power(Minion& minion) {
	Gheata::power(minion);
	if (minion.getKiwiP() - 1 >= 0)
		suma = minion.getKiwiP() - 1;
	else
		suma = -1;
	minion.setKiwiP(suma);
	std::cout << suma << std::endl;
}