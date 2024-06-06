#include "Menu.hpp"

Menu::Menu(const std::string& fontPath) {
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Failed to load font!" << std::endl;
        exit(-1);
    }
    startButton = new MenuButton(font, "Start", sf::Vector2f(200, 50), sf::Vector2f(500, 300));
    optionsButton = new MenuButton(font, "Options", sf::Vector2f(200, 50), sf::Vector2f(500, 400));
    quitButton = new MenuButton(font, "Quit", sf::Vector2f(200, 50), sf::Vector2f(500, 500));
}

Menu::~Menu() {
    delete startButton;
    delete optionsButton;
    delete quitButton;
}

void Menu::draw(sf::RenderWindow& window) {
    startButton->draw(window);
    optionsButton->draw(window);
    quitButton->draw(window);
}

void Menu::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    startButton->handleEvent(event, window);
    optionsButton->handleEvent(event, window);
    quitButton->handleEvent(event, window);
}




