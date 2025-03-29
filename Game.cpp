#include "Game.h"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>


/*Game::Game() {
	this->window = sf::RenderWindow(sf::VideoMode({800, 600}), "Maze Game");

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		while (const std::optional event = window.pollEvent())
		{
			// "close requested" event: we close the window
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		window.clear();
		
		// end the current frame
		window.display(); 
		}
	
}*/

Game::Game() {
	run = true;
}


void Game::start() {
	std::ifstream file("joc.txt");
	file >> player;
	std::cout << std::endl;
	std::cout << "           The fun just begun!    " << std::endl;
	std::cout << "               Game loading..." << std::endl;
	std::cout << "            You are at level " << player.getLevel() << std::endl;
	std::cout << "             READY TO PLAY!" << std::endl;
	player.setX(0);
	player.setY(0);
	map.initialize();
	std::cout << map;
	std::ofstream g("restart.txt");
	g << player << std::endl;
	g << map << std::endl;
	run = true;
	while (run == true)
		Miscare();
}

/*void Game::render() {
	window.clear();
	map.render(window);
	//player.render(window);
	window.display();
}*/

void Game::saveState() {
	std::cout << "Game pause. Saving state..." << std::endl;
	std::cout << "If you want to continue please select the option resume by writing here:" << std::endl;
	std::ofstream g("joc.txt");
	g << player << std::endl;
	g << map << std::endl;
	run = false;
}

void Game::loadState() {
	std::cout << "Resuming game. Loading saved state..." << std::endl;
	std::ifstream file("joc.txt");
	file >> player;
	file >> map;
	std::cout << map;
	run = true;
	while (run == true)
		MiscareResume();
}

void Game::restart() {
	std::ifstream file("restart.txt");
	file >> player;
	file >> map;
	std::cout << map;
	run = true;
	while (run == true)
		MiscareResume();
}

void Game::restart2() {
	std::cout << map;
}

void Game::exit() {
	std::cout << "Goodbye! Hope you had fun!" << std::endl;
	std::cout << "Wait for saving your state" << std::endl;
	std::ofstream g("joc.txt");
	g << player << std::endl;
	g << map << std::endl;
}

void Game::Miscare() {

	lastX = player.getX();
	lastY = player.getY();
	playerX = player.getX();
	playerY = player.getY();
	labir = map.getMaze();
	std::cin >> c;
	if (c == 'w')
		if (playerX > 0 && labir[playerX - 1][playerY] == 0)
			playerX--;
	if (c == 's')
		if (playerX < 19 && labir[playerX + 1][playerY] == 0)
			playerX++;
	if (c == 'a')
		if (playerY > 0 && labir[playerX][playerY - 1] == 0)
			playerY--;
	if (c == 'd')
		if (playerY < 19 && labir[playerX][playerY + 1] == 0)
			playerY++;
	if (c == 'm')
		run = false;
	else {
		player.setX(playerX);
		player.setY(playerY);
		labir[lastX][lastY] = 0;
		labir[playerX][playerY] = 3;
		map.setMaze(labir);
		std::cout << map;
	}

}

void Game::MiscareResume() {

	lastX = player.getX()+1;
	lastY = player.getY();
	playerX = player.getX()+1;
	playerY = player.getY();
	labir = map.getMaze();
	std::cin >> c;
	if (c == 'w')
		if (playerX > 0 && labir[playerX - 1][playerY] == 0)
			playerX--;
	if (c == 's')
		if (playerX < 19 && labir[playerX + 1][playerY] == 0)
			playerX++;
	if (c == 'a')
		if (playerY > 0 && labir[playerX][playerY - 1] == 0)
			playerY--;
	if (c == 'd')
		if (playerY < 19 && labir[playerX][playerY + 1] == 0)
			playerY++;
	if (c == 'm')
		run = false;
	else {
		player.setX(playerX);
		player.setY(playerY);
		labir[lastX][lastY] = 0;
		labir[playerX][playerY] = 3;
		map.setMaze(labir);
		std::cout << map;
	}

}


int Game::getC() {
	return c;
}
