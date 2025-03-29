#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Map.h"

class Player {
private:
    char name;
    int lvl, lives, x, y;
    friend std::ostream& operator << (std::ostream& os, Player& player);
    friend std::istream& operator >> (std::istream&, Player& player);
public:
    Player();
    Player(const Player& other);
    void initialize(int x, int y, int lvl, int lives);
    int getPlayer();
    int getX();
    int getY();
    int getLevel();
    int getLives();
    void setX(int playerX);
    void setY(int playerY);
    void setChange(int change);
    int getChange();
    void render(sf::RenderWindow& window);
};