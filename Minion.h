#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Minion{
private:
    static const char name;
    int lvl = 1, lives = 3, x=0, y=5, puncte = 0, kiwiP = 0;
    friend std::ostream& operator << (std::ostream& os, Minion& minion);
    friend std::istream& operator >> (std::istream& is, Minion& minion);
    sf::CircleShape jucator;
    sf::CircleShape cerc;
public:
    Minion();
    Minion(const Minion& other);
    void initialize(int x, int y, int lvl, int lives);
    int getPlayer();
    int getX();
    int getY();
    int getLevel();
    int getLives();
    int getPuncte();
    void setPuncte(int p);
    int getKiwiP();
    void setKiwiP(int p);
    sf::CircleShape getJucator();
    void jump(const int i, const int j);
    void moveUp(int step);
    void moveDown(int step);
    void moveLeft(int step);
    void moveRight(int step);
    void setX(int playerX);
    void setY(int playerY);
    void setChange(int change);
    int getChange();
    void caracter();
    void draw(sf::RenderWindow* window);
    //~Minion();
};