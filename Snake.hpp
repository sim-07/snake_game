#ifndef SNAKE_HPP
#define SNAKE_HPP


class Snake {
    public:
        Snake(int lenght);
        sf::Vector2i getPosition();
        void grow();
};

#endif