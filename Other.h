#pragma once
#include "Minion.h"
#include "Game.h"
#include "Meniu.h"
#include "Map.h"

class Other {
public:
	friend std::ostream& operator << (std::ostream& os, Minion& minion);
	friend std::istream& operator >> (std::istream& is, Minion& minion);
	friend std::ostream& operator << (std::ostream& os, Map& map);
	friend std::istream& operator >> (std::istream&, Map& map);
};