#include "Game.h"
#include "Minion.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <fstream>


Game::Game() : text(font), finished(font), Coco(font), Kiwi(font){

    this->initializare();
    this->initializareWindow();
    this->addMinioni();
    this->addMap();
    this->pause();
    //this->Resume();
    this->nrCocos();
    this->nrKiwi();
    this->render();
    this->draw();
};

int Game::step = 10;
int Game::nrMiscariSpeed = 5;


void Game::initializare() {
    this->gameWindow = nullptr;
}

void Game::addMinioni() {
    auto* minion1 = new Minion;
    minioni.emplace_back(minion1);
}

void Game::addMap() {
    auto* map = new Map;
    maps.emplace_back(map);
}

void Game::setStep(int step) {
    //this->step = step;
}

void Game::initializareWindow() {

    this->videoMode.size.x = 1050;
    this->videoMode.size.y = 900;
    this->gameWindow = new sf::RenderWindow(this->videoMode,
        "My Game", sf::Style::Titlebar | sf::Style::Close);
    this->gameWindow->setFramerateLimit(144);
    // Create a view with the same size as the window
    view.setSize({ static_cast<float>(gameWindow->getSize().x), static_cast<float>(gameWindow->getSize().y) });
    view.setCenter(view.getSize() / 2.f);
    // Set the view to be displayed in the window
    gameWindow->setView(view);

}

void Game::update() {

    pollEvents(*this->gameWindow);
}

void Game::pollEvents(sf::RenderWindow& gameWindow) {
    auto* minion1 = minioni[0];
    auto* map = maps[0];
    if (this->gameWindow != nullptr) {
        while (const std::optional event2 = gameWindow.pollEvent()) {
            //std::cout << "m";
            if (gameWindow.hasFocus()) {
                if (event2->is<sf::Event::Closed>())
                {
                    gameWindow.close();
                }
                else {
                    if (event2->is<sf::Event::KeyPressed>()) {
                        //std::cout << "Merge";
                        if (event2->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Up) {
                            //std::cout << "M";
                            sf::FloatRect minionBounds = minion1->getJucator().getGlobalBounds(); 
                            sf::Vector2f minionPos = minion1->getJucator().getPosition();
                            sf::Vector2u windowSize = gameWindow.getSize();
                            if ((minionPos.y - (minionBounds.size.y)/2 + 10) >= 0)
                            {
                                if (map->isSpaceUp(minionPos.x, minionPos.y - step)) {
                                    lastX = minionPos.x;
                                    lastY = minionPos.y;
                                    if (map->isFruitUp(minionPos.x, minionPos.y, i))
                                    {
                                        std::cout << "gresit " << i << std::endl;
                                        map->deleteFruit(i, *minion1);
                                        render();
                                       
                                    }
                                    if (int c = map->isWallUp(minionPos.x, minionPos.y - step)) {
                                        map->powerWall(c, *minion1);
                                    }
                                    else {
                                        if (lastX == minionPos.x and lastY == minionPos.y)
                                        {

                                            minion1->moveUp(step);
                                        }
                                    }
                                    std::cout << minion1->getPuncte() << std::endl;
                                    Coco.setString(std::to_string(minion1->getPuncte()));
                                    Kiwi.setString(std::to_string(minion1->getKiwiP()));
                                    draw();
                                }
                            }
                        }
                        else {
                            if (event2->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Down) {
                                //std::cout << "M";
                                sf::FloatRect minionBounds = minion1->getJucator().getGlobalBounds();
                                sf::Vector2f minionPos = minion1->getJucator().getPosition();
                                sf::Vector2u windowSize = gameWindow.getSize();
                                if ((minionPos.y + (minionBounds.size.y) / 2 + 25) < windowSize.y)
                                {
                                    if (map->isSpaceDown(minionPos.x, minionPos.y + step)) {
                                        lastX = minionPos.x;
                                        lastY = minionPos.y;
                                        
                                        if (map->isFruitDown(minionPos.x, minionPos.y, i))
                                        {
                                            std::cout << "gresit " << i << std::endl;
                                            map->deleteFruit(i, *minion1);
                                            render();
                                            
                                        }
                                        if (int c = map->isWallDown(minionPos.x, minionPos.y + step)) {
                                            map->powerWall(c, *minion1);
                                        }
                                        else {
                                            if (lastX == minionPos.x and lastY == minionPos.y)
                                            {

                                                minion1->moveDown(step);
                                            }
                                        }
                                        std::cout << minion1->getPuncte() << std::endl;
                                        Coco.setString(std::to_string(minion1->getPuncte()));
                                        Kiwi.setString(std::to_string(minion1->getKiwiP()));
                                        draw();
                                    }
                                }
                            }
                            else {
                                if (event2->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Left) {
                                    //std::cout << "M";
                                    sf::FloatRect minionBounds = minion1->getJucator().getGlobalBounds();
                                    sf::Vector2f minionPos = minion1->getJucator().getPosition();
                                    sf::Vector2u windowSize = gameWindow.getSize();

                                    if ((minionPos.x - (minionBounds.size.x) / 2 + 5) >= 0)
                                    {
                                        if (map->isSpaceLeft(minionPos.x - step, minionPos.y)) {
                                            lastX = minionPos.x;
                                            lastY = minionPos.y;
                                           
                                            if (map->isFruitLeft(minionPos.x, minionPos.y, i))
                                            {
                                                
                                                map->deleteFruit(i, *minion1);
                                                render();
                                                
                                            }
                                            if (int c = map->isWallLeft(minionPos.x - step, minionPos.y)) {
                                                map->powerWall(c, *minion1);
                                            }
                                            else {
                                                if (lastX == minionPos.x and lastY == minionPos.y)
                                                {

                                                    minion1->moveLeft(step);

                                                }
                                            }
                                            std::cout << minion1->getPuncte() << std::endl;
                                            Coco.setString(std::to_string(minion1->getPuncte()));
                                            Kiwi.setString(std::to_string(minion1->getKiwiP()));
                                            draw();
                                        }
                                    }
                                }
                                else {
                                    if (event2->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Right) {
                                        //std::cout << "M";
                                        sf::FloatRect minionBounds = minion1->getJucator().getGlobalBounds();
                                        sf::Vector2f minionPos = minion1->getJucator().getPosition();
                                        sf::Vector2u windowSize = gameWindow.getSize();
                                        if ((minionPos.x + (minionBounds.size.x) / 2 + 25) < windowSize.x)
                                        {
                                            if (map->isSpaceRight(minionPos.x + step, minionPos.y)) {
                                                lastX = minionPos.x;
                                                lastY = minionPos.y;
                                                if (map->isFruitRight(minionPos.x, minionPos.y, i))
                                                {
                                                    
                                                    std::cout << "gresit " << i << std::endl;
                                                    map->deleteFruit(i, *minion1);
                                                    render();
                                                    
                                                }
                                                if (int c = map->isWallRight(minionPos.x + step, minionPos.y)) {
                                                    map->powerWall(c, *minion1);
                                                }
                                                else {
                                                    if (lastX == minionPos.x and lastY == minionPos.y)
                                                    {

                                                        minion1->moveRight(step);
                                                    }
                                                }
                                                std::cout << minion1->getPuncte() << std::endl; 
                                                Coco.setString(std::to_string(minion1->getPuncte()));
                                                Kiwi.setString(std::to_string(minion1->getKiwiP()));
                                                draw();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else {
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                            sf::Vector2i position = sf::Mouse::getPosition(gameWindow);
                            if (position.x >= 900 && position.y <= 60 && position.x <= 1000 && position.y >= 0) {
                                windowPause();
                            }
                            else {
                                if (position.x >= 390 && position.y >= 300 && position.x <= 600 && position.y <= 500) {
                                    windowResume();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


void Game::Finish(int& ok) {
    auto* minion1 = minioni[0];
    sf::Vector2f minionPos = minion1->getJucator().getPosition();
    if (minionPos.x >= 860 && minionPos.y >= 860)
    {
        gameWindow->clear(sf::Color::Green);
        font.openFromFile("D:\\project\\joc2\\arial.ttf");
        finished.setString("Congratulations! You won!");
        finished.setFont(font);
        finished.setCharacterSize(40);
        finished.setPosition({ 300, 300 });
        finished.setFillColor(sf::Color::Black);
        ok = 1;
        gameWindow->draw(finished);
        gameWindow->display();
    }
}

void Game::start() {
    auto* minion1 = minioni[0];
    auto* map = maps[0];
    std::ofstream g("restartt.txt");
    g << *minion1 << std::endl;
    g << *map << std::endl;
    pollEvents(*this->gameWindow);
}

void Game::nrCocos() {
    if (!texture3.loadFromFile("D:\\project\\joc2\\coconut.png")) {
        std::cout << "Nu se incarca imaginea" << std::endl;
    }
    cocos.setTexture(&texture3);
    cocos.setRadius(30.0f);
    cocos.setPosition(sf::Vector2f(910.0f, 70.0f));
    font.openFromFile("D:\\project\\joc2\\arial.ttf");
    Coco.setString("0");
    Coco.setFont(font);
    Coco.setCharacterSize(25);
    Coco.setPosition({ 980, 90 });
    Coco.setFillColor(sf::Color::Black);
}

void Game::nrKiwi() {
    if (!texture4.loadFromFile("D:\\project\\joc2\\kiwi.png")) {
        std::cout << "Nu se incarca imaginea" << std::endl;
    }
    kiwi.setTexture(&texture4);
    kiwi.setRadius(30.0f);
    kiwi.setPosition(sf::Vector2f(910.0f, 150.0f));
    font.openFromFile("D:\\project\\joc2\\arial.ttf");
    Kiwi.setString("0");
    Kiwi.setFont(font);
    Kiwi.setCharacterSize(25);
    Kiwi.setPosition({ 980, 175 });
    Kiwi.setFillColor(sf::Color::Black);
}

void Game::pause() {
    if (!texture.loadFromFile("D:\\project\\joc2\\pause.png")) {
        std::cout << "Nu se incarca imaginea" << std::endl;
    }
    pauza.setTexture(&texture);
    pauza.setSize(sf::Vector2f(70.0f, 60.0f));
    pauza.setPosition(sf::Vector2f(910.0f, 5.0f));
    std::cout << "Pauza";
}

void Game::windowPause() {
    std::ofstream g("joc.txt");
    auto* minion1 = minioni[0];
    auto* map = maps[0];
    g << *minion1 << std::endl;
    g << *map << std::endl;
    gameWindow->clear(sf::Color::White);
    Resume();
    gameWindow->draw(text);
    gameWindow->draw(resume);
    gameWindow->display();
    std::cout << "Resume";
}

void Game::Resume() {
    if (!texture2.loadFromFile("D:\\project\\joc2\\resume.png")) {
        std::cout << "Nu se incarca imaginea" << std::endl;
    }
    font.openFromFile("D:\\project\\joc2\\arial.ttf");
    text.setString("You are in pause! \n Please click the Resume Button \n to continue the game.");
    text.setFont(font);
    text.setCharacterSize(40);
    text.setPosition({ 100, 150 });
    text.setFillColor(sf::Color::Black);
    resume.setTexture(&texture2);
    resume.setSize(sf::Vector2f(200.0f, 200.0f));
    resume.setPosition(sf::Vector2f(390.0f, 300.0f));
}

void Game::windowResume() {
    std::ifstream file("joc.txt");
    auto* minion2 = new Minion;
    file >> *minion2;
    auto* map2 = new Map;
    file >> *map2;
    gameWindow->clear(sf::Color::White);
    minioni.emplace_back(minion2);
    maps.emplace_back(map2);
    minioni.erase(minioni.begin()+1);
    maps.erase(maps.begin()+1);
    this->pause();
    this->render();
    this->draw();
}

bool Game::running(int& ok) {
    Finish(ok);
    lost(ok);
    if (this->gameWindow != nullptr and ok == 0)
        return this->gameWindow->isOpen();
    return false;
}

void Game::lost(int& ok) {
    //std::cout << "SECTIUNEA dE LOST" << std::endl;
    auto* mini = minioni[0];
    if (mini->getPuncte() < 0)
    { 
        ok = 1;
    }
    if (mini->getKiwiP() < 0)
        ok = 1;
}

void Game::render() {
    if (gameWindow != nullptr)
    {
        this->gameWindow->clear(sf::Color(165, 42, 42));
        //window->display();
        //Minion* primul = &minioni[0];
        this->draw();
        gameWindow->display();
    }
}

void Game::draw() {
    if (gameWindow != nullptr)
    {
      
        for (auto& m : maps)
        {
            std::cout << "desen";
            m->draw(gameWindow);
        }
        for (auto& mini : minioni)
        {
            std::cout << "mini";
            mini->draw(gameWindow);
        }
        gameWindow->draw(pauza);
        gameWindow->draw(cocos);
        gameWindow->draw(Coco);
        gameWindow->draw(kiwi);
        gameWindow->draw(Kiwi);
    }
}

Game::~Game() {
    for (auto& mini : minioni)
        delete mini;
    minioni.clear();
    for (auto& m : maps) {
        delete m;
    }
    maps.clear();
}
