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
    void setFillColor(sf::Color color);
    void setDefaultColor(sf::Color color);
    void setHoverColor(sf::Color color);
    void setPressedColor(sf::Color color);
    void update(sf::Vector2f mousePosition, bool isPressed);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
};







