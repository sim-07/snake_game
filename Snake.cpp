#include "Snake.hpp"

Snake::Snake(int l) {
    length = l;
    direction = Direction::Right;

    position = getInitialPos();
    
}

std::vector<sf::Vector2i> Snake::getInitialPos() {
    sf::Vector2i headStart(4, 1);
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
    if ((direction == Direction::Up && dir == Direction::Down) || // il serpente non può fare cambi di direzione di 180°
        (direction == Direction::Down && dir == Direction::Up) ||
        (direction == Direction::Left && dir == Direction::Right) ||
        (direction == Direction::Right && dir == Direction::Left))
    {
        return;
    }

    direction = dir;
}

Direction Snake::getDirection() {
    return direction;
}

void Snake::grow() {
    position.push_back(position.back());
    length++;
}

void Snake::move() {
    switch (direction)
    {
    case Direction::Right:
        position[0].x += 1;
        break;
    case Direction::Left:
        position[0].x += -1;
        break;
    case Direction::Down:
        position[0].y += 1;
        break;
    case Direction::Up:
        position[0].y += -1;
        break;
    
    default:
        break;
    }
}