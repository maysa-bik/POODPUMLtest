// main.cpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include "Menu.hpp"
#include "Game.hpp"

enum class AppState {
    Menu,
    Game
};

int main() {
    std::cout << "Hello" << std::endl;
    sf::RenderWindow window(sf::VideoMode(1200, 950), "Towerdefence");

    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    std::string imagePath = "C:/Users/33753/OneDrive/Bureau/POODPUMLtest/assets/images/Kingdom-rush-frontiers-front-jaquette-upscale.jpg";
    std::string fontPath = "C:/Users/33753/OneDrive/Bureau/POODPUMLtest/assets/font/Coffee Spark.ttf";

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile(imagePath)) {
        std::cerr << "Failed to load background image!" << std::endl;
        return -1;
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        window.getSize().x / backgroundSprite.getLocalBounds().width,
        window.getSize().y / backgroundSprite.getLocalBounds().height
    );

    Menu menu(fontPath);
    AppState appState = AppState::Menu;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (appState == AppState::Menu) {
                menu.handleEvent(event, window);
                if (event.type == sf::Event::MouseButtonReleased) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (menu.handleMouseClick(mousePos, window) == "Start") {
                        appState = AppState::Game;
                    }
                }
            }
        }

        window.clear();
        if (appState == AppState::Menu) {
            window.draw(backgroundSprite);
            menu.draw(window);
        } else if (appState == AppState::Game) {
            runGame(window);
        }
        window.display();
    }

    return 0;
}

