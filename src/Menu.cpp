#include "Menu.hpp"

Menu::Menu(const std::string& fontPath) {
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Failed to load font!" << std::endl;
        exit(-1);
    }
    startButton = new MenuButton(font, "Start", sf::Vector2f(200, 50), sf::Vector2f(500, 650));
    optionsButton = new MenuButton(font, "Options", sf::Vector2f(200, 50), sf::Vector2f(500, 750));
    quitButton = new MenuButton(font, "Quit", sf::Vector2f(200, 50), sf::Vector2f(500, 850));
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

std::string Menu::handleMouseClick(sf::Vector2f mousePos, sf::RenderWindow& window) {
    if (startButton->isMouseOver(mousePos)) {
        std::cout << "Start button clicked!" << std::endl;
        return "Start";
    }
    else if (optionsButton->isMouseOver(mousePos)) {
        std::cout << "Options button clicked!" << std::endl;
        return "Options";
    }
    else if (quitButton->isMouseOver(mousePos)) {
        std::cout << "Quit button clicked!" << std::endl;
        window.close();
        return "Quit";
    }
    return "";
}

