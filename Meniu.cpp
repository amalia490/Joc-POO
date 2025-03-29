#include "Meniu.h"
#include "Map.h"
#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

Meniu::Meniu() {
    isPaused = false;
    isRunning = false;
    isRestarting = false;
    isResume = false;
    Begin = false;
}

bool Meniu::getRun() {
    return isRunning;
}


/*void Meniu::init() {

    this->window = nullptr; 
}

void Meniu::initWindow() {
    sf::VideoMode videoMode({ 500, 900 }, 32);
    this->window = new sf::RenderWindow(this->videoMode, "Minionii");
    this->window->setFramerateLimit(200);

    view.setSize({static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)});
    view.setCenter(view.getSize() / 2.f);
    // Set the view to be displayed in the window
    window->setView(view);
    window->display();
}
*/
void Meniu::update() {
    


    std::cout << "                                                  ---MINI MAZE---" << std::endl;
    std::cout << "                                                       ~MENU~" << std::endl;
    std::cout << "                                                       START" << std::endl;
    std::cout << "                                                       PAUSE" << std::endl;
    std::cout << "                                                       RESUME" << std::endl;
    std::cout << "                                                       RESTART" << std::endl;
    std::cout << "                                                       ESCAPE" << std::endl;
    std::cout << "                                      If you want to exit menu just enter escape!" << std::endl;
    std::cout << "Select one of them by writing here your option:";
    std::cin >> optiune;
    handleInput();
   

}


/*void Meniu::rend() {
    if (this->window != nullptr)
    {
        this->window->clear(sf::Color::Black);
        //game.render();
        this->window->display();
    }
} */
/*void Meniu::events() {
    
    if (this->window != nullptr) {
        while (this->window->pollEvent()) {
            const std::optional event = window->pollEvent();
            if (event->is<sf::Event::Closed>()) {
                this->window->close();
                break;
            }
        }
    }
}*/

/*bool Meniu::running() {
    if (this->window != nullptr)
        return this->window->isOpen();
    return false;
}*/

bool Meniu::running() {
    if (isRunning == false)
        return true;
    else
        return false;
}

Meniu &Meniu::getInstance() {

    static Meniu instance;
    return instance;

}

void Meniu::handleInput() {
    if (strcmp(optiune, "Pause") == 0) {
        if (!isPaused) {
            isPaused = true;
            isResume = false;
            game.saveState();
        }
    }
    if (strcmp(optiune, "Resume") == 0) {
        if (!isResume) {
            isResume = true;
            isPaused = false;
            isRunning = false;
            game.loadState();
        }
    }
    if (strcmp(optiune, "Start") == 0) {
        if (isRunning == false && Begin == false) {
            Begin = true;
            //isRunning = true;
            game.start();
            //game.render();
        }
    }
    if (strcmp(optiune, "Restart") == 0) {
        if (isRunning == false && isRestarting == false) {
            std::cout << "Are you sure you want to restart the game? Your progress won't be saved." << std::endl;
            std::cin >> ok;
            if (strcmp(ok, "yes") == 0)
            {
                game.restart();
                //game.render();
            }
            else {
                game.restart2();
            }
        }
    }
    if (strcmp(optiune, "Escape") == 0) {
        isRunning = true;
        std::cout << "Are you sure you want to exit?" << std::endl;
        std::cin >> raspuns;
        if (strcmp(raspuns, "yes") == 0)
            game.exit();
        else
        {
            isRunning = false;
        }
    }
}



