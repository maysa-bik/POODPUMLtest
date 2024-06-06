#include "MenuButton.hpp"

MenuButton::MenuButton(sf::Font& font, const std::string& buttonText, sf::Vector2f buttonSize, sf::Vector2f buttonPosition) {
    shape.setSize(buttonSize);
    shape.setPosition(buttonPosition);
    shape.setFillColor(sf::Color::Transparent); // Couleur du bouton, maintenant transparent

    text.setFont(font);
    text.setString(buttonText);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White); // Couleur du texte
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(buttonPosition.x + buttonSize.x / 2.0f, buttonPosition.y + buttonSize.y / 2.0f);
}

void MenuButton::draw(sf::RenderWindow& window) {
    // window.draw(shape); // Ne pas dessiner le fond
    window.draw(text);
}

bool MenuButton::isMouseOver(sf::Vector2f mousePosition) {
    return shape.getGlobalBounds().contains(mousePosition);
}

void MenuButton::setFillColor(sf::Color color) {
    shape.setFillColor(color);
}



