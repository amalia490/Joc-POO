#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Map.h"
#include "Player.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;
	Map map;
	int starting = 0, playerX = 0, playerY = 0, lastX, lastY, nrBanane;
	vector<vector<int>> labir = vector<vector<int>>(20, vector<int>(20, 1));
	bool run = true;
	char c;
public:
	Game();
	int getStart();
	int running();
	void start();
	void update();
	void render();
	void saveState();
	void loadState();
	void restart();
	void restart2();
	void exit();
	void Miscare();
	void MiscareResume();
	int getC();
};
