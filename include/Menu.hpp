#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MenuButton.hpp"

class Menu {
private:
    sf::Font font;
    MenuButton* startButton;
    MenuButton* optionsButton;
    MenuButton* quitButton;
public:
    Menu(const std::string& fontPath);
    ~Menu();

    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
    void handleMouseClick(sf::Vector2f mousePos, sf::RenderWindow& window);
    void update(sf::Vector2f mousePosition, bool isPressed);
};










