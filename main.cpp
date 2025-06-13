#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Snake Game");
    Game game(8, 8, 128);

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