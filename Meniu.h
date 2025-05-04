#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include "Game.h"

class Meniu {
private:
	int ok = 0;
	sf::RenderWindow*  window;
	sf::VideoMode videoMode;
	sf::Font font;
	sf::Text title;
	sf::Text Start;
	sf::Text Setari;
	sf::Text Audio;
	sf::View view;
	std::vector<Game*> games;
	//Game* game;
public:
	Meniu();
	static Meniu& getInstance();
	void addGame(Game* game);
	void pozitieMinion();
	void render();
	void draw();
	int getok();
	void initializareWindow();
	void initializare();
	void initText();
	void update();
	void pollEvents(sf::RenderWindow &window);
	bool running();
};