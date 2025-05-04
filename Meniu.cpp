#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "Meniu.h"
#include "Minion.h"


Meniu& Meniu::getInstance() {

    static Meniu instance;
    return instance;
}

void Meniu::addGame(Game* game) {
    games.emplace_back(game);
}

int Meniu::getok() {
    return ok;
}

void Meniu::initializare() {
    this->window = nullptr;
}

void Meniu::initText() {
    font.openFromFile("D:\\project\\joc2\\arial.ttf");
    title.setString("Choose your game!");
    title.setFont(font);
    title.setCharacterSize(40);
    title.setPosition({ 300, 20 });
    title.setFillColor(sf::Color::White);
    Start.setString("Start");
    Start.setFont(font);
    Start.setCharacterSize(40);
    Start.setPosition({ 150, 100 });
    Start.setFillColor(sf::Color::White);
    Setari.setString("Setari");
    Setari.setFont(font);
    Setari.setCharacterSize(40);
    Setari.setPosition({ 400, 100 });
    Setari.setFillColor(sf::Color::White);
    Audio.setString("Audio");
    Audio.setFont(font);
    Audio.setCharacterSize(40);
    Audio.setPosition({ 660, 100 });
    Audio.setFillColor(sf::Color::White);

}

void Meniu::initializareWindow() {

    this->videoMode.size.x = 900;
    this->videoMode.size.y = 700;
    this->window = new sf::RenderWindow(this->videoMode,
        "My Minion", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);
    // Create a view with the same size as the window
    view.setSize({ static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y) });
    view.setCenter(view.getSize() / 2.f);
    // Set the view to be displayed in the window
    window->setView(view);
    
}

Meniu::Meniu(): title(font), Start(font), Setari(font), Audio(font){

    this->initializare();
    this->initializareWindow();
    this->initText();
    this->render();
    this->draw();
};


void Meniu::update() {
    this->pollEvents(*this->window);
}


void Meniu::pollEvents(sf::RenderWindow &window) {
    if (this->window != nullptr) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else {
                if (event->is<sf::Event::KeyPressed>()) {
                    if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape) {
                        window.close();
                    }
                }
                else {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                        sf::Vector2i position = sf::Mouse::getPosition(*this->window);
                        if (position.x >= 150 && position.y >= 100 && position.x <= 200 && position.y <= 150){
                            window.close();
                            delete &window;
                            auto* game1 = new Game;
                            addGame(game1);
                           // auto* game1 = games[0];
                            for (auto* g : games)
                            {
                                g->start();
                                while (g->running(ok))
                                {
                                    g->update();
                                }
                            }
                        }
                    }           
                }
            }
        }
    }
}

bool Meniu::running() {
    if (this->window != nullptr)
        return this->window->isOpen();
    return false;
}


void Meniu::render() {
    if (this->window != nullptr)
    {
        this->window->clear(sf::Color::Black);
        //Draw Meniu
        this->draw();
        this->window->display();
    }
}

void Meniu::draw() {
    if (this->window != nullptr)
    {
        this->window->draw(title);
        this->window->draw(Start);
        this->window->draw(Setari);
        this->window->draw(Audio);

    }
}