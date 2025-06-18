#ifndef GAME_HPP // Processa il codice successivo solo se non è ancora definito
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "Snake.hpp"
#include "Cell.hpp"

class Game
{
private:
    Cell cell;
    Snake snake;
    std::vector<std::vector<Cell>> grid; // vettore di vettori (matrice) che contiene le celle
    int width;
    int height;
    int cellSize;
    sf::Vector2i applePosition;
    sf::Vector2i randomApplePosition();
    bool gameOver;
    std::vector<sf::Vector2i> getFreeCells() const;
    float moveInterval;
    bool press;
    sf::Clock moveClock; 

    void spawnApple();
    bool checkCollision();

public:
    Game(int width, int height, int cellSize);
    void handleInput(const sf::Event &event);
    void update();
    void draw(sf::RenderWindow &window);
    bool isGameOver() const;
};

#endif