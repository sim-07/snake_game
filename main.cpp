#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Game.hpp"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    sf::RenderWindow window(sf::VideoMode(800, 800), "Snake Game");
    Game game(16, 16, 50);

    while (window.isOpen()) {
        sf::Event event; // struttura che contiene un evento
        while (window.pollEvent(event)) { // window.pollEvent(event) prende l'ultimo evento dalla coda interna di SFML e lo copia nell'oggetto "event"
            if (event.type == sf::Event::Closed) { // controlla se l'evento è la chiusura della finestra
                window.close();
            }
            game.handleInput(event); // passo l'evento a game
        }

        game.update();
        window.clear(); // pulisce lo schermo dai disegni del frame precedente
        game.draw(window);
        window.display();  
    }

}