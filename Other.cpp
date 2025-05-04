#include <iostream>
#include <fstream> 
#include <vector>
#include "Other.h"

std::istream& operator >> (std::istream& is, Map& map) {
    map.maze.clear();
    std::string line;
    std::getline(is, line);
    for (int i = 0; i <= map.getWidth(); i++)
    {
        std::string line2;
        std::getline(is, line2);
        std::vector<int> mazeRow;
        for (char c : line2)
        {
            if (c == ' ')
                mazeRow.push_back(0);
            if (c == '#')
                mazeRow.push_back(1);
            if (c == 'f')
                mazeRow.push_back(4);
        }
        map.maze.push_back(mazeRow);
    }
    return is;
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
                else {
                    if (cell == 4)
                        os << 'f';
                }
            }
        }
        os << std::endl;
    }// Output the maze
    return os;
}

std::ostream& operator << (std::ostream& os, Minion& minion) {
    // Start generating maze from (0, 0)
    os << minion.getX() << " " << minion.getY() << " " << minion.getLevel() << " " << minion.getLives();
    return os;
}

std::istream& operator >> (std::istream& is, Minion& minion) {
    int v[5], i;
    for (i = 0; i < 4; i++)
        is >> v[i];
    minion.initialize(v[0], v[1], v[2], v[3]);
    return is;
}
