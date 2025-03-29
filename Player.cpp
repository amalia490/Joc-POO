#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Map.h"
#include "Player.h"
#include <fstream>


Player::Player() {
	initialize(x, y, lvl, lives);
}

Player::Player(const Player& other) {
	this->x = other.x;
	this->y = other.y;
	this->lvl = other.lvl;
	this->lives = other.lives;
}

void Player::initialize(int x, int y, int lvl, int lives) {
	this->x = x;
	this->y = y;
	this->lvl = lvl;
	this->lives = lives;
}

int Player::getX() { return x; }
int Player::getY() { return y; }
int Player::getLevel() { return lvl; }
int Player::getLives() { return lives; }

void Player::setX(int playerX) {
	x = playerX;
}
void Player::setY(int playerY) {
	y = playerY;
}


std::ostream& operator << (std::ostream& os, Player& player) {
	// Start generating maze from (0, 0)
	os << player.getX() << " " << player.getY()<< " " << player.getLevel()<< " " << player.getLives();
	return os;
}

std::istream& operator >> (std::istream& is, Player& player) {
	int v[5], i;
	for (i = 0; i < 4; i++)
		is >> v[i];
	player.initialize(v[0], v[1], v[2], v[3]);
	return is;
}


//void Player::render(sf::RenderWindow& window) {
	//window.draw();
//}