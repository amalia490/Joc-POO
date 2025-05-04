#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stack>
#include "Fructe.h"
#include "Cells.h"
#include "Obstacole.h"
#include "Piatra.h"
#include "Gheata.h"
#include "Metal.h"

class Map {
private:
    int n, m, nrBanane = 0;
    std::vector<Fructe*> fruits;
    static const int WIDTH = 20;
    static const int HEIGHT = 20;
    std::vector<std::vector<int>> maze = std::vector<std::vector<int>>(HEIGHT, std::vector<int>(WIDTH, 1));
    std::vector<Cells> celule;
    std::stack<std::pair<int, int>> cellStack;
    std::vector<Obstacole*> obs;
    int randIndex;
    sf::CircleShape shape;
    sf::Texture texture, texture1, texture2;
    sf::RectangleShape cell, wall;
    int x, y, val, mini, comanda;
    friend std::ostream& operator << (std::ostream& os, Map& map);
    friend std::istream& operator >> (std::istream&, Map& maze);
public:
    Map();
    bool isSpaceUp(int x, int y);
    bool isSpaceDown(int x, int y);
    bool isSpaceLeft(int x, int y);
    bool isSpaceRight(int x, int y);
    int isWallUp(int x, int y);
    int isWallDown(int x, int y);
    int isWallLeft(int x, int y);
    int isWallRight(int x, int y);
    void powerWall(int c, Minion& minion);
    bool isFruitLeft(int x, int y, size_t& i);
    bool isFruitRight(int x, int y, size_t& i);
    bool isFruitDown(int x, int y, size_t& i);
    bool isFruitUp(int x, int y, size_t& i);
    void deleteFruit(const size_t& i, Minion& minion);
    void generateMaze(int startX, int startY);
    void obstacole();
    void randomFructe();
    void initialize();
    int getWidth();
    int getHeight();
    void initializare();
    void MiscareCaracter();
    std::vector<std::vector<int>> getMaze();
    void setMaze(std::vector<std::vector<int>> labir);
    void render(sf::RenderWindow& window);
    int getBanane(int i, int j);
    void draw(sf::RenderWindow* gameWindow);
    ~Map();
};
