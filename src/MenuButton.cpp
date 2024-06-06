#include "MenuButton.hpp"

MenuButton::MenuButton(sf::Font& font, const std::string& buttonText, sf::Vector2f buttonSize, sf::Vector2f buttonPosition) {
    shape.setSize(buttonSize);
    shape.setPosition(buttonPosition);
    defaultColor = sf::Color::Black;
    hoverColor = sf::Color::Black;
    pressedColor = sf::Color::Magenta;
    shape.setFillColor(defaultColor); // Couleur par défaut du bouton

    text.setFont(font);
    text.setString(buttonText);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White); // Couleur du texte
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(buttonPosition.x + buttonSize.x / 2.0f, buttonPosition.y + buttonSize.y / 2.0f);
}

void MenuButton::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

bool MenuButton::isMouseOver(sf::Vector2f mousePosition) {
    return shape.getGlobalBounds().contains(mousePosition);
}

void MenuButton::setFillColor(sf::Color color) {
    shape.setFillColor(color);
}

void MenuButton::setDefaultColor(sf::Color color) {
    defaultColor = color;
    shape.setFillColor(defaultColor);
}

void MenuButton::setHoverColor(sf::Color color) {
    hoverColor = color;
}

void MenuButton::setPressedColor(sf::Color color) {
    pressedColor = color;
}

void MenuButton::update(sf::Vector2f mousePosition, bool isPressed) {
    if (isMouseOver(mousePosition)) {
        if (isPressed) {
            shape.setFillColor(pressedColor);
        } else {
            shape.setFillColor(hoverColor);
        }
    } else {
        shape.setFillColor(defaultColor);
    }
}

void MenuButton::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseMoved) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if (isMouseOver(mousePos)) {
            shape.setFillColor(hoverColor);
        } else {
            shape.setFillColor(defaultColor);
        }
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (isMouseOver(mousePos)) {
                shape.setFillColor(pressedColor);
                isPressed = true;
            }
        }
    } else if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (isMouseOver(mousePos)) {
                shape.setFillColor(hoverColor);
            } else {
                shape.setFillColor(defaultColor);
            }
            isPressed = false;
        }
    }
}








