#include "Map.h"
#include "Banana.h"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <widemath.h>


Map::Map() {

}

int Map::getWidth() {
    return WIDTH;
    }

int Map::getHeight() {
    return HEIGHT;
}

vector<vector<int>> Map::getMaze() {
    return maze;
}
    
void Map::generateMaze(int startX=0, int startY=0){
    cellStack.push({ startX, startY });
    maze[startY][startX] = 0; // Mark start cell as path

    while (!cellStack.empty()) {
        auto current = cellStack.top();
        int x = current.first;
        int y = current.second;

        // Find unvisited neighbors
        vector<pair<int, int>> neighbors;
        // Check four directions
        if (x > 1 && maze[y][x - 2] == 1) neighbors.push_back({ x - 2, y });
        if (x < WIDTH - 2 && maze[y][x + 2] == 1) neighbors.push_back({ x + 2, y });
        if (y > 1 && maze[y - 2][x] == 1) neighbors.push_back({ x, y - 2 });
        if (y < HEIGHT - 2 && maze[y + 2][x] == 1) neighbors.push_back({ x, y + 2 });

        // If there are unvisited neighbors
        if (!neighbors.empty()) {
            // Randomly select a neighbor
            int randIndex = rand() % neighbors.size();
            auto next = neighbors[randIndex];

            // Remove the wall between current cell and the chosen neighbor
            maze[(y + next.second) / 2][(x + next.first) / 2] = 0; // Clear wall
            maze[next.second][next.first] = 0; // Mark neighbor as path

            cellStack.push(next); // Move to the neighbor
        }
        else {
            cellStack.pop(); // Backtrack
        }
    }
    maze[WIDTH - 1][HEIGHT - 1] = 0;
    maze[0][0] = 3;
}
void Map::randomBanane() {
    for (int i = 0; i < WIDTH; i++)
    {
        int k = 0;
        for (int j = 1; j < HEIGHT; j++)
            if (maze[i][j] != 1 && k < 3)
                if (rand() % 100 > 70)
                {
                    bananas.push_back(Banana(i, j, val));
                    maze[i][j] = 2;
                    k++;
                }
    }

}

void Map::render(sf::RenderWindow& window) {
    // draw everything here...
    float cellSize = 30.0f;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++)
        {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition({ i * cellSize, j * cellSize });
            if (maze[i][j] == 1)
                cell.setFillColor(sf::Color::Black);
            else if (maze[i][j] == 2)
                cell.setFillColor(sf::Color::Yellow);
            else if (maze[i][j] == 3)
                cell.setFillColor(sf::Color::Blue);
            else
                cell.setFillColor(sf::Color::White);
            window.draw(cell);
                
        }
    }

}
  
  

std::ostream& operator << (std::ostream& os, Map& map) {
    // Start generating maze from (0, 0)
    for (const auto& row : map.maze) {
        for (int cell : row) {
            if (cell == 1)
                os << '#';
            else
            {
                if (cell == 0)
                    os << ' ';
                else
                    if (cell == 2)
                        os << 'b';
                    else
                        if (cell == 3)
                            os << 'm';
            }
        }
        os << endl;
    }// Output the maze
    return os;
}

void Map::setMaze(vector<vector<int>> labir) {
    maze = labir;
}

std::istream& operator >> (std::istream& is, Map& map) {
    map.maze.clear();
    for (int i = 0; i <= map.getWidth(); i++)
    {
        std::string line;
        std::getline(is, line);
        vector<int> mazeRow;
        for (char c : line)
        {
            if (c == ' ')
                mazeRow.push_back(0);
            if (c == '#')
                mazeRow.push_back(1);
            if (c == 'm')
                mazeRow.push_back(3);
            if (c == 'b')
                mazeRow.push_back(2);
        }
        map.maze.push_back(mazeRow);
    }
    return is;
}

void Map::initialize() {
    generateMaze(0, 0);
    randomBanane();
}
