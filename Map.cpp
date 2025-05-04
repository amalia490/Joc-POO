#include "Map.h"
#include "Cocos.h"
#include "Kiwi.h"
#include "Fructe.h"
#include "Banane.h"
#include "Game.h"

Map::Map() {
    generateMaze(0, 0);
    randomFructe();
    obstacole();
}

void Map::generateMaze(int startX = 0, int startY = 0) {
    
    cellStack.push({ startX, startY });
    maze[startY][startX] = 0; 

    while (!cellStack.empty()) {
        auto current = cellStack.top();
        int x = current.first;
        int y = current.second;

        
        std::vector<std::pair<int, int>> neighbors;
       
        if (x > 1 && maze[y][x - 2] == 1) neighbors.push_back({ x - 2, y });
        if (x < WIDTH - 2 && maze[y][x + 2] == 1) neighbors.push_back({ x + 2, y });
        if (y > 1 && maze[y - 2][x] == 1) neighbors.push_back({ x, y - 2 });
        if (y < HEIGHT - 2 && maze[y + 2][x] == 1) neighbors.push_back({ x, y + 2 });

        
        if (!neighbors.empty()) {
            
            int randIndex = rand() % neighbors.size();
            auto next = neighbors[randIndex];

            
            maze[(y + next.second) / 2][(x + next.first) / 2] = 0; 
            maze[next.second][next.first] = 0; 

            cellStack.push(next); 
        }
        else {
            cellStack.pop(); 
        }
    }
    maze[WIDTH - 1][HEIGHT - 1] = 4;
    maze[WIDTH - 1][HEIGHT - 2] = 0;
    maze[WIDTH - 1][HEIGHT - 3] = 0;
    maze[WIDTH - 1][HEIGHT - 4] = 0;
}
//void Map::randomFructe() {
//    for (int i = 0; i < WIDTH; i++)
//    {
//        int k = 1;
//        for (int j = 1; j < HEIGHT; j++)
//            if (maze[i][j] != 1 && k >= 0 && maze[i][j] != 4)
//            {
//                if (rand() % 100 > 10 && (j > 10 && j < 15 || j > 2 && j < 7) && k > 0 && rand() % 100 < 15)
//                {
//                    Fructe* f = static_cast<Fructe*>(new Banane(j * 45, i * 45, sf::Color::Yellow, 15));
//                    fruits.push_back(f);
//                    //fruits.push_back(new Banane(j*45, i*45, sf::Color::Yellow, 15));
//                    maze[i][j] = 2;
//                    k--;
//                }
//                else {
//                    if (rand() % 100 > 45 && rand() % 100 < 65)
//                    {
//                        Fructe* f = static_cast<Fructe*>(new Cocos(j * 45, i * 45, sf::Color::White, 10));
//                        fruits.push_back(f);
//                        //fruits.push_back(new Cocos(j*45, i*45, sf::Color::White, 10));
//                        maze[i][j] = 5;
//                        //k--;
//                    }
//                    else {
//                        if (rand() % 100 > 85 && j < 18 && rand() % 100 < 90)
//                        {
//                            Fructe* f = static_cast<Fructe*>(new Kiwi(j * 45, i * 45, sf::Color::Green, 10, 15, 1));
//                            fruits.push_back(f);
//                            //fruits.push_back(new Kiwi(j*45, i*45, sf::Color::Green, 10, 15, 1));
//                            maze[i][j] = 6;
//                            //k--;
//                        }
//                    }
//                }
//            }
//    }
//}

void Map::randomFructe() {
    try {
        for (int i = 0; i < WIDTH; i++) {
            int k = 1;
            for (int j = 1; j < HEIGHT; j++) {
                if (maze[i][j] != 1 && k >= 0 && maze[i][j] != 4) {
                    if (rand() % 100 > 10 && (j > 10 && j < 15 || j > 2 && j < 7) && k > 0 && rand() % 100 < 15) {
                        // Attempt to allocate a new fruit
                        Fructe* f = new Banane(j * 45, i * 45, sf::Color::Yellow, 15);
                        //Fructe* f = nullptr;
                        if (!f) throw std::bad_alloc();
                        fruits.push_back(f);
                        maze[i][j] = 2;
                        k--;
                    }
                    else if (rand() % 100 > 45 && rand() % 100 < 65) {
                        Fructe* f = new Cocos(j * 45, i * 45, sf::Color::White, 10);
                        if (!f) throw std::bad_alloc();
                        fruits.push_back(f);
                        maze[i][j] = 5;
                    }
                    else if (rand() % 100 > 85 && j < 18 && rand() % 100 < 90) {
                        Fructe* f = new Kiwi(j * 45, i * 45, sf::Color::Green, 10, 15, 1);
                        if (!f) throw std::bad_alloc();
                        fruits.push_back(f);
                        maze[i][j] = 6;
                    }
                }
            }
        }
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Error in randomFructe: Memory allocation failed - " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error in randomFructe: " << e.what() << std::endl;
    }
}


void Map::obstacole() {
    obs.push_back(new Piatra(0, 770));
    obs.push_back(new Piatra(810, 505));
    obs.push_back(new Piatra(135, 450));
    obs.push_back(new Gheata(45, 630));
    obs.push_back(new Gheata(315, 450));
    obs.push_back(new Metal(450, 190));
    obs.push_back(new Metal(630, 0));
    obs.push_back(new Metal(585, 540));
}

void Map::draw(sf::RenderWindow* gameWindow) {
        // draw everything here...
        //gameWindow->clear(sf::Color::Blue);
       
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++)
            {
                

                if (maze[i][j] == 1)
                {
                    float cellSize = 55.0f;
                    cell.setFillColor(sf::Color::Black);
                    cell.setSize(sf::Vector2f(45.0f, 45.0f));
                    cell.setPosition(sf::Vector2f(j * 45.0f, i * 45.0f));
                    celule.push_back(Cells(j * 45, i * 45, sf::Color::Black));
                }
                else {
                    if (maze[i][j] == 0)
                    {
                        float cellSize = 55.0f;
                        cell.setFillColor(sf::Color(165, 42, 42));
                        cell.setSize(sf::Vector2f(45.0f, 45.0f));
                        cell.setPosition(sf::Vector2f(j * 45.0f, i * 45.0f));
                    }
                    
                }
                gameWindow->draw(cell);

            }
        }
        for (Fructe* f : fruits) {
            int j = f->getY(), i = f->getX();
            shape.setRadius(15.0f);
            shape.setFillColor(f->getCuloare());
            shape.setPosition(sf::Vector2f(i, j));
            gameWindow->draw(shape);
        }

        for (Obstacole* o : obs) {
            if (auto* c = dynamic_cast<Metal*>(o)) {
                int j = o->getY();
                int i = o->getX();
                wall.setFillColor(sf::Color(128, 128, 128));
                wall.setSize(sf::Vector2f(45.0f, 45.0f));
                wall.setPosition(sf::Vector2f(i, j));
            }
            else {
                if (auto* p = dynamic_cast<Gheata*>(o)) {
                    int j = o->getY();
                    int i = o->getX();
                    wall.setFillColor(sf::Color::Blue);
                    wall.setSize(sf::Vector2f(45.0f, 45.0f));
                    wall.setPosition(sf::Vector2f(i, j));
                }
                else {
                    if (auto* o2 = dynamic_cast<Piatra*>(o)) {
                        int j = o->getY();
                        int i = o->getX();
                        //wall.setTexture(&texture);
                        wall.setFillColor(sf::Color::White);
                        wall.setSize(sf::Vector2f(45.0f, 45.0f));
                        wall.setPosition(sf::Vector2f(i, j));
                    }
                }
            }
            gameWindow->draw(wall);
        }
        gameWindow->display();

}

bool Map::isFruitLeft(int x, int y,  size_t& i) {
    for (i = 0; i < fruits.size(); i++) {
        if (fruits[i] != nullptr)
        {
            Fructe* fruit = fruits[i];
            if (x - fruit->getX() <= 10 && x-fruit->getX() > 0 && abs(y - fruit->getY()) <= 30) {                
                return true;
            }            
        }
    }
    return false;
}

bool Map::isFruitRight(int x, int y, size_t& i) {
    std::cout << "Fruit Right" << std::endl;
    for (i = 0; i < fruits.size(); i++) {
        if (fruits[i] != nullptr)
        {
            Fructe* fruit = fruits[i];
            if (fruit->getX() - x <= 10 && fruit->getX() - x > 0 && abs(y - fruit->getY()) <= 30) {
                 return true;
            }          
        }
    }
    return false;
}

bool Map::isFruitDown(int x, int y, size_t& i) {
    std::cout << "Fruit Right" << std::endl;
    for (i = 0; i < fruits.size(); ++i) {
        if (fruits[i] != nullptr)
        {
            Fructe* fruit = fruits[i];
            if (abs(fruit->getX() - x) <= 30 && fruit->getY()-y <= 35 && fruit->getY()-y > 0) {
                 return true;
            }           
        }
    }
    return false;
}

bool Map::isFruitUp(int x, int y, size_t& i) {
    std::cout << "Fruit Right" << std::endl;
    for (i = 0; i < fruits.size(); ++i) {
        if (fruits[i] != nullptr)
        {
            Fructe* fruit = fruits[i];
            if (abs(fruit->getX() - x) <= 30 && y - fruit->getY() <= 35 && y - fruit->getY() > 0) {
                return true;
            }          
        }
    }
    return false;
}

void Map::deleteFruit(const size_t& i, Minion& minion) {
    fruits[i]->superPower(minion);
    std::cout << fruits[i]->getX() << std::endl;
    delete fruits[i];        
    fruits.erase(fruits.begin() + i);
}

bool Map::isSpaceUp(int x, int y) {
    
    for (auto cel : celule) {
        if (x >= cel.getX() and x <= (cel.getX()+45) and y >= cel.getY() and y <= cel.getY() + 45) {
            return false;
        }
    }
  
    return true;
}

bool Map::isSpaceDown(int x, int y) {

    for (auto cel : celule) {
        if (x >= cel.getX() and x <= (cel.getX() + 45) and y <= cel.getY() and y + 30 >= cel.getY()) {
            return false;
        }
    }
    return true;
}


bool Map::isSpaceLeft(int x, int y) {

    for (auto cel : celule) {
        if (x >= cel.getX() and x <= cel.getX()+45 and y >= cel.getY() and y<= cel.getY() + 45) {
            return false;
        }
    }
   
    return true;
}

bool Map::isSpaceRight(int x, int y) {

    for (auto cel : celule) {
        if (x <= cel.getX() and x + 30 >= cel.getX() and y >= cel.getY() and y <= cel.getY() + 45) {
            return false;
        }
    }
   
    return true;
}

int Map::isWallLeft(int x, int y) {
    for (size_t i = 0; i < obs.size(); ++i) {
        Obstacole* o = obs[i];
        if (x >= o->getX() and x <= o->getX() + 45 and y >= o->getY() and y <= o->getY() + 45) {
            return static_cast<int>(i);
        }
    }
    return false;
}

int Map::isWallRight(int x, int y) {
    for (size_t i = 0; i < obs.size(); ++i) {
        Obstacole* o = obs[i];
        if (x <= o->getX() and x + 30 >= o->getX() and y >= o->getY() and y <= o->getY() + 45) {
            return static_cast<int>(i);
        }
    }
    return false;
}

int Map::isWallDown(int x, int y) {
    for (size_t i = 0; i < obs.size(); ++i) {
        Obstacole* o = obs[i];
        if (x >= o->getX() and x <= (o->getX() + 45) and y <= o->getY() and y + 30 >= o->getY()) {
            return static_cast<int>(i);
        }
    }
    return 0;
}

int Map::isWallUp(int x, int y) {
   
    for (size_t i = 0; i < obs.size(); ++i) {
        Obstacole* o = obs[i];
        if (x >= o->getX() and x <= (o->getX() + 45) and y >= o->getY() and y <= o->getY() + 45)
            return static_cast<int>(i);
    }
    return 0;
}

void Map::powerWall(int c, Minion& minion) {
    Obstacole* o = obs[c];
    o->power(minion);
}

//int Map::getBanane(int i, int j) {
//    for (int k = 0; k < bananas.size(); k++)
//        if (bananas[k].getX() == i && bananas[k].getY() == j)
//            return bananas[k].getValue();
//    return 0;
//}

void Map::setMaze(std::vector<std::vector<int>> labir) {
    maze = labir;
}


int Map::getWidth() {
    return WIDTH;
}

int Map::getHeight() {
    return HEIGHT;
}

std::vector<std::vector<int>> Map::getMaze() {
    return maze;
}

Map::~Map() {
    for (Fructe* f : fruits)
        delete f;
    fruits.clear();
    for (Obstacole* o : obs) {
        delete o;
    }
    obs.clear();
}