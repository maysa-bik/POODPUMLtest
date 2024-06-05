#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class MenuButton {
private:
    sf::RectangleShape shape;
    sf::Text text;
public:
    MenuButton(sf::Font& font, const std::string& buttonText, sf::Vector2f buttonSize, sf::Vector2f buttonPosition) {
        shape.setSize(buttonSize);
        shape.setPosition(buttonPosition);
        shape.setFillColor(sf::Color::Blue); // Couleur du bouton

        text.setFont(font);
        text.setString(buttonText);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White); // Couleur du texte
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(buttonPosition.x + buttonSize.x / 2.0f, buttonPosition.y + buttonSize.y / 2.0f);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }

    bool isMouseOver(sf::Vector2f mousePosition) {
        return shape.getGlobalBounds().contains(mousePosition);
    }

    void setFillColor(sf::Color color) {
        shape.setFillColor(color);
    }
};

class Menu {
private:
    sf::Font font;
    MenuButton* startButton;
    MenuButton* optionsButton;
    MenuButton* quitButton;
public:
    Menu(const std::string& fontPath) {
        if (!font.loadFromFile(fontPath)) {
            std::cerr << "Failed to load font!" << std::endl;
            exit(-1);
        }
        startButton = new MenuButton(font, "Start", sf::Vector2f(200, 50), sf::Vector2f(500, 300));
        optionsButton = new MenuButton(font, "Options", sf::Vector2f(200, 50), sf::Vector2f(500, 400));
        quitButton = new MenuButton(font, "Quit", sf::Vector2f(200, 50), sf::Vector2f(500, 500));
    }

    ~Menu() {
        delete startButton;
        delete optionsButton;
        delete quitButton;
    }

    void draw(sf::RenderWindow& window) {
        startButton->draw(window);
        optionsButton->draw(window);
        quitButton->draw(window);
    }

    void handleMouseClick(sf::Vector2f mousePos, sf::RenderWindow& window) {
        if (startButton->isMouseOver(mousePos)) {
            std::cout << "Start button clicked!" << std::endl;
            // Insérez ici le code pour commencer le jeu
        }
        else if (optionsButton->isMouseOver(mousePos)) {
            std::cout << "Options button clicked!" << std::endl;
            // Insérez ici le code pour afficher les options
        }
        else if (quitButton->isMouseOver(mousePos)) {
            std::cout << "Quit button clicked!" << std::endl;
            window.close();
        }
    }
};
