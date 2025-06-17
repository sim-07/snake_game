#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/Graphics.hpp>

enum class Direction
{
    Up,
    Down,
    Left,
    Right
};

class Snake
{
private:
    Direction direction;
    int length;
    std::vector<sf::Vector2i> position;
    std::vector<sf::Vector2i> getInitialPos();

public:
    Snake(int l);
    std::vector<sf::Vector2i> getPosition();
    void grow();
    void setDirection(Direction direction);
    Direction getDirection();
    void move();
};

#endif