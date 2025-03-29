#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Banana.h"
#include <stack>
#include "Player.h"

using namespace std;

class Map {
private:
    int n, m, nrBanane = 0;
    vector<Banana> bananas;
    static const int WIDTH = 20;
    static const int HEIGHT = 20;
    vector<vector<int>> maze = vector<vector<int>>(HEIGHT, vector<int>(WIDTH, 1));
    stack<pair<int, int>> cellStack;
    int randIndex;
    int x, y, val, mini, comanda;
    int shouldExit = 0;
    friend std::ostream& operator << (std::ostream& os, Map& map);
    friend std::istream& operator >> (std::istream&, Map& maze);
    //Player& player;
    char c;
public:
    Map();
    void generateMaze(int startX, int startY);
    void randomBanane();
    void initialize();
    int getWidth();
    int getHeight();
    void initializare();
    void MiscareCaracter();
    vector<vector<int>> getMaze();
    void setMaze(vector<vector<int>> labir);
    void render(sf::RenderWindow& window);
};
