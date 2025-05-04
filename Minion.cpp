#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Minion.h"
#include <iostream>
#include <fstream>


Minion::Minion() {
	initialize(x, y, lvl, lives);
	caracter();
}

Minion::Minion(const Minion& other) {
	this->x = other.x;
	this->y = other.y;
	this->lvl = other.lvl;
	this->lives = other.lives;
}

void Minion::initialize(int x = 0, int y = 5, int lvl = 1, int lives = 3) {
	this->x = x;
	this->y = y;
	this->lvl = lvl;
	this->lives = lives;
}

int Minion::getX() { return x; }
int Minion::getY() { return y; }
int Minion::getLevel() { return lvl; }
int Minion::getLives() { return lives; }
sf::CircleShape Minion::getJucator() { return jucator; };

int Minion::getPuncte() {
	return puncte;
}

void Minion::setPuncte(int p) {
	puncte = p;
}

int Minion::getKiwiP() {
	return kiwiP;
}

void Minion::setKiwiP(int p) {
	kiwiP = p;
}

void Minion::setX(int playerX) {
	x = playerX;
}
void Minion::setY(int playerY) {
	y = playerY;
}


void Minion::caracter() {

	float x2 = static_cast<float>(x);
	float y2 = static_cast<float>(y);
	this->jucator.setPosition(sf::Vector2f( x2, y2 ));
	std::cout << "Minion position: " << x2 << ", " << y2 << std::endl;
	this->jucator.setRadius(15.f);
	this->jucator.setFillColor(sf::Color::Yellow);
	this->jucator.setOutlineColor(sf::Color::Black);
	this->jucator.setOutlineThickness(2.f);
}

void Minion::moveUp(int step) {
	float x2 = static_cast<float>(x);
	float y2 = static_cast<float>(y);
	this->jucator.move(sf::Vector2f(0, -step));
	y = y - step;
	this->cerc.setPosition(sf::Vector2f(x2, y2));
	this->cerc.setRadius(15.f);
	this->cerc.setFillColor(sf::Color(165, 42, 42));
	this->cerc.setOutlineColor(sf::Color(165, 42, 42));
	this->cerc.setOutlineThickness(2.f);
	
}

void Minion::jump(const int i, const int j) {
	float x2 = static_cast<float>(x);
	float y2 = static_cast<float>(y);
	cerc.setPosition(sf::Vector2f(x2, y2));
	cerc.setRadius(15.f);
	cerc.setFillColor(sf::Color(165, 42, 42));
	cerc.setOutlineColor(sf::Color(165, 42, 42));
	cerc.setOutlineThickness(2.f);
	this->jucator.setPosition(sf::Vector2f(i, j));
	x = i;
	y = j;
}

void Minion::moveDown(int step) {

	float x2 = static_cast<float>(x);
	float y2 = static_cast<float>(y);
	this->jucator.move(sf::Vector2f(0, step));
	y = y + step;
	this->cerc.setPosition(sf::Vector2f(x2, y2));
	this->cerc.setRadius(15.f);
	this->cerc.setFillColor(sf::Color(165, 42, 42));
	this->cerc.setOutlineColor(sf::Color(165, 42, 42));
	this->cerc.setOutlineThickness(2.f);
	
}

void Minion::moveLeft(int step) {
	this->jucator.move(sf::Vector2f(-step, 0));
	float x2 = static_cast<float>(x);
	float y2 = static_cast<float>(y);
	x = x - step;
	this->cerc.setPosition(sf::Vector2f(x2, y2));
	this->cerc.setRadius(15.f);
	this->cerc.setFillColor(sf::Color(165, 42, 42));
	this->cerc.setOutlineColor(sf::Color(165, 42, 42));
	this->cerc.setOutlineThickness(2.f);
	
}

void Minion::moveRight(int step) {
	this->jucator.move(sf::Vector2f(step, 0));
	float x2 = static_cast<float>(x);
	float y2 = static_cast<float>(y);
	x = x + step;
	this->cerc.setPosition(sf::Vector2f(x2, y2));
	this->cerc.setRadius(15.f);
	this->cerc.setFillColor(sf::Color(165, 42, 42));
	this->cerc.setOutlineColor(sf::Color(165, 42, 42));
	this->cerc.setOutlineThickness(2.f);
}

/*Minion::~Minion() {
	std::cout << "Minion at the position (" << x << ", " << y << ") is being destroyed." << std::endl;
}*/

void Minion :: draw(sf::RenderWindow* window) {
	std::cout << x << " , " << y << std::endl;
	window->draw(cerc);
	window->draw(jucator);
	window->display();
 }

