// Game.cpp
#include "Game.hpp"

void runGame(sf::RenderWindow& window) {
    // Fonction pour exécuter le jeu. Peut être étendue pour inclure la logique du jeu.
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        // Ajoutez ici le code pour dessiner le jeu
        window.display();
    }
}
