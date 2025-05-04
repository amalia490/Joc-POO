#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Audio.hpp>
#include "Map.h"
#include "Minion.h"

class Game{
private:
	//Coordonate coordonate;
	int starting = 0, playerX, playerY, lastX, lastY, punctaj = 0, ok;
	static int step, nrMiscariSpeed;
	size_t i;
	std::vector<std::vector<int>>labir = std::vector<std::vector<int>>(20, std::vector<int>(20, 1));
	bool run = true, castigat = false;
	char c;
	sf::VideoMode videoMode;
	sf::View view;
	sf::Font font;
	sf::Text text, finished, Coco, Kiwi;
	sf::Texture texture3, texture2, texture, texture4;
	sf::CircleShape cocos, kiwi;
	sf::RectangleShape pauza;
	//vector<Banana> bananas2;
	sf::RectangleShape resume;
	sf::RenderWindow* gameWindow;
	std::vector<Minion*> minioni;
	std::vector<Map*> maps;
public:
	Game();
	void setStep(int step);
	void timpSpeed();
	int getStep();
	void initializare();
	void initializareWindow();
	void addMinioni();
	void addMap();
	void draw();
	void lost(int& ok);
	void nrCocos();
	void nrKiwi();
	int getStart();
	bool running(int& ok);
	void start();
	void update();
	void pollEvents(sf::RenderWindow& gameWindow);
	void render();
	void pause();
	void windowPause();
	void restart();
	void windowResume();
	void exit();
	void Miscare();
	void Resume();
	void Finish(int& ok);
	int getC();
	~Game();
};