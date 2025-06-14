#include "Snake.hpp"

Snake::Snake(int l) {
    length = l;
    direction = Direction::Right;

    position = getInitialPos();
    
}

std::vector<sf::Vector2i> Snake::getInitialPos() {
    sf::Vector2i headStart(5, 5);
    std::vector<sf::Vector2i> pos;

    for (int i = 0; i < length; i++) {
        pos.push_back(sf::Vector2i(headStart.x - i, headStart.y));
    }

    return pos;
}

std::vector<sf::Vector2i> Snake::getPosition() {
    return position;
}

void Snake::setDirection(Direction dir) {
    if ((direction == Direction::Up && dir == Direction::Down) ||
        (direction == Direction::Down && dir == Direction::Up) ||
        (direction == Direction::Left && dir == Direction::Right) ||
        (direction == Direction::Right && dir == Direction::Left))
    {
        return;
    }

    direction = dir;
}