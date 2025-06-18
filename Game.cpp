#include "Game.hpp"
#include <cstdlib>
#include <iostream>

Game::Game(int w, int h, int c) : snake(4)
{
    width = w;
    height = h;
    cellSize = c;
    gameOver = false;
    grid.resize(width, std::vector<Cell>(height));
    applePosition = Game::randomApplePosition();
    sf::Clock moveClock; // inizia a contare appena Game viene costruito
    moveInterval = 0.17f;
    press = false;
}

void Game::draw(sf::RenderWindow &window)
{ // passo riferimento a un oggetto di tipo sf::RenderWindow
    sf::RectangleShape apple;
    apple.setSize(sf::Vector2f(cellSize, cellSize));
    apple.setFillColor(sf::Color::Red);
    apple.setPosition(applePosition.x * cellSize, applePosition.y * cellSize);

    window.draw(apple);

    sf::RectangleShape snakeCell;
    sf::RectangleShape head;
    snakeCell.setSize(sf::Vector2f(cellSize, cellSize));

    std::vector<sf::Vector2i> snakePos = snake.getPosition();

    for (sf::Vector2i &pos : snakePos)
    {

        if (pos == snakePos.front())
        {
            snakeCell.setFillColor(sf::Color::Blue);
        }
        else
        {
            snakeCell.setFillColor(sf::Color::Green);
        }

        snakeCell.setPosition(pos.x * cellSize, pos.y * cellSize);
        window.draw(snakeCell);
    }
}

void Game::update()
{
    std::vector<sf::Vector2i> snakePos = snake.getPosition();

    if (gameOver)
    {
        return;
    }

    if (snakePos[0].x >= width || snakePos[0].y >= height || snakePos[0].x <= 0 || snakePos[0].y <= 0)
    {
        gameOver = true;
        return;
    }

    if (grid[snakePos[0].x][snakePos[0].y].type == SNAKE)
    {
        std::cout << "Gameover serpente sbattuto contro se stesso";
        gameOver = true;
        return;
    }

    if (snakePos[0] == applePosition)
    {
        snake.grow();
        applePosition = randomApplePosition();
    }

    if (moveClock.getElapsedTime().asSeconds() >= moveInterval)
    {
        snake.move();
        press = false;
        moveClock.restart();

        for (int i = 0; i < width; ++i)
        {
            for (int j = 0; j < height; ++j)
            {
                grid[i][j].type = EMPTY;
            }
        }

        for (const sf::Vector2i &pos : snakePos)
        {
            grid[pos.x][pos.y].type = SNAKE;
        }

        grid[applePosition.x][applePosition.y].type = APPLE;
    }
}

sf::Vector2i Game::randomApplePosition()
{
    std::vector<sf::Vector2i> freeCells = getFreeCells();

    int rNum = rand() % freeCells.size();

    return freeCells[rNum];
}

std::vector<sf::Vector2i> Game::getFreeCells() const
{
    std::vector<sf::Vector2i> freeCells;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (grid[i][j].type == EMPTY)
            {
                freeCells.push_back(sf::Vector2i(i, j));
            }
        }
    }

    return freeCells;
}

void Game::handleInput(const sf::Event &event)
{
    if (press)
    {
        std::cout << "Errore tasti";
    }
    if (event.type == sf::Event::KeyPressed && !press)
    {
        press = true;
        switch (event.key.code)
        {
        case sf::Keyboard::Right:
            snake.setDirection(Direction::Right);
            break;
        case sf::Keyboard::Left:
            snake.setDirection(Direction::Left);
            break;
        case sf::Keyboard::Down:
            snake.setDirection(Direction::Down);
            break;
        case sf::Keyboard::Up:
            snake.setDirection(Direction::Up);
            break;
        default:
            break;
        }
    }
}