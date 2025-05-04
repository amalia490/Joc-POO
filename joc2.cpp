#pragma once 
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Meniu.h"
#include "Minion.h"
#include "Game.h"
#include "Map.h"

int main() {
	Meniu &meniu = Meniu::getInstance();
	//int ok = meniu.getok();
	while (meniu.getok() == 0) {
		while (meniu.running())
		{
			meniu.update();
			//meniu.render();
		}
		//ok = meniu.getok();
		//game->update();
	}
}