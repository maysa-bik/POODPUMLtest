#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem> // C++17
#include "Menu.hpp"

int main()
{
    std::cout << "Hello" << std::endl;
    sf::RenderWindow window(sf::VideoMode(1200, 950), "Towerdefence");

    // Imprimez le chemin de travail actuel
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    // Utilisez un chemin absolu pour tester
    std::string imagePath = "C:/Users/33753/OneDrive/Bureau/POODPUMLtest/assets/images/Kingdom-rush-frontiers-front-jaquette-upscale.jpg";
    std::string fontPath = "C:/Users/33753/OneDrive/Bureau/POODPUMLtest/assets/font/Coffee Spark.ttf";

    // Chargez la texture de l'image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile(imagePath))
    {
        std::cerr << "Failed to load background image!" << std::endl;
        return -1;
    }

    // Créez un sprite pour afficher la texture
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    // Redimensionnez le sprite pour qu'il corresponde à la taille de la fenêtre
    backgroundSprite.setScale(
        window.getSize().x / backgroundSprite.getLocalBounds().width,
        window.getSize().y / backgroundSprite.getLocalBounds().height
    );

    // Créez le menu
    Menu menu(fontPath);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased)
            {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                menu.handleMouseClick(mousePos, window);
            }
        }    
        

        window.clear();
        // Dessinez le sprite (image de fond) avant tout autre dessin
        window.draw(backgroundSprite);
        menu.draw(window);
        window.display();
    }

    return 0;
}



