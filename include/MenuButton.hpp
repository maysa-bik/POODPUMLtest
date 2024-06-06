#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class MenuButton {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Color defaultColor;
    sf::Color hoverColor;
    sf::Color pressedColor;
    bool isPressed;
public:
    MenuButton(sf::Font& font, const std::string& buttonText, sf::Vector2f buttonSize, sf::Vector2f buttonPosition);
    void draw(sf::RenderWindow& window);
    bool isMouseOver(sf::Vector2f mousePosition);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
};



