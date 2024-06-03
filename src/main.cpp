#include <SFML/Graphics.hpp>
#include <iostream>

class MenuButton {
private:
    sf::RectangleShape shape;
    sf::Text text;
public:
    MenuButton(sf::Font& font, std::string buttonText, sf::Vector2f buttonSize, sf::Vector2f buttonPosition) {
        shape.setSize(buttonSize);
        shape.setPosition(buttonPosition);
        shape.setFillColor(sf::Color::Blue); // Couleur du bouton

        text.setFont(font);
        text.setString(buttonText);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White); // Couleur du texte
        text.setPosition(buttonPosition.x + 10, buttonPosition.y + 10); // Ajustement du texte dans le bouton
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }

    bool isMouseOver(sf::Vector2f mousePosition) {
        return shape.getGlobalBounds().contains(mousePosition);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Menu");

    sf::Font font;
    if (!font.loadFromFile("Coffee Spark.ttf")) {
        std::cerr << "Failed to load assets/font!" << std::endl;
        return -1;
    }

    MenuButton startButton(font, "Start", sf::Vector2f(200, 50), sf::Vector2f(300, 200));
    MenuButton optionsButton(font, "Options", sf::Vector2f(200, 50), sf::Vector2f(300, 300));
    MenuButton quitButton(font, "Quit", sf::Vector2f(200, 50), sf::Vector2f(300, 400));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (startButton.isMouseOver(mousePos)) {
                    std::cout << "Start button clicked!" << std::endl;
                    // Insérez ici le code pour commencer le jeu
                }
                else if (optionsButton.isMouseOver(mousePos)) {
                    std::cout << "Options button clicked!" << std::endl;
                    // Insérez ici le code pour afficher les options
                }
                else if (quitButton.isMouseOver(mousePos)) {
                    std::cout << "Quit button clicked!" << std::endl;
                    window.close();
                }
            }
        }

        window.clear();
        startButton.draw(window);
        optionsButton.draw(window);
        quitButton.draw(window);
        window.display();
    }

    return 0;
}
