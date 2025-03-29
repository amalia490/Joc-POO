#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Map.h"
#include "Game.h"

class Meniu {
private:
	sf::RenderWindow* window{};
	sf::VideoMode videoMode;
	//Map maze;
	//sf::Event ev();
	sf::View view;
	bool isPaused;
	bool isRunning;
	bool isRestarting;
	bool isResume;
	bool Begin;
	Game game;
	char ok[10];
	vector<vector<int>> labirint;
	char optiune[20], raspuns[20];
public:
	Meniu();
	void setRun(bool Run);
	void init();
	void initWindow();
	void rend();
	void draw();
	void events();
	void update();
	bool running();
	void handleInput();
	bool getRun();
	static Meniu& getInstance();
	
};
