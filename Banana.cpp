#include "Meniu.h"
#include "Map.h"
#include "Banana.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Config.hpp>
#include <SFML/Window/VideoMode.hpp>

/*Banana::Banana() {
    x = 0;
    y = 0;
    valoare = 0;
}
*/
Banana::Banana(int x, int y, int valoare) {
    this->x = x;
    this->y = y;
    this->valoare = valoare;
    //banane = new Banana[maxBananas];
}
/*
Banana::~Banana() {
    // Clean up dynamically allocated memory
    delete[] banane; 
}*/

