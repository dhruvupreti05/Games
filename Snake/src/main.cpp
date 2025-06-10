#include <SFML/Graphics.hpp>
#include "constants.h"
#include "snake.h"
#include "apple.h"
#include <vector>

int main()
{
    sf::Clock clock;
    const float frameDelay = 0.15f; 

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game", sf::Style::Close | sf::Style::Titlebar);
    
    std::vector<sf::Vertex> grid;
    for (int y = 0; y <= WINDOW_HEIGHT; y += GRID_HEIGHT) {
        grid.push_back(sf::Vertex(sf::Vector2f(0.f, static_cast<float>(y)), sf::Color::White));
        grid.push_back(sf::Vertex(sf::Vector2f(static_cast<float>(WINDOW_WIDTH), static_cast<float>(y)), sf::Color::White));
    }
    for (int x = 0; x <= WINDOW_WIDTH; x += GRID_WIDTH) {
        grid.push_back(sf::Vertex(sf::Vector2f(static_cast<float>(x), 0.f), sf::Color::White));
        grid.push_back(sf::Vertex(sf::Vector2f(static_cast<float>(x), static_cast<float>(WINDOW_HEIGHT)), sf::Color::White));
    }

    Snake snake;
    Apple apple(snake.getBody());

    sf::Vector2f direction(GRID_WIDTH, 0);
    bool alive = true;

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
            else if (evnt.type == sf::Event::KeyPressed)
            {
                switch (evnt.key.code)
                {
                case sf::Keyboard::Up:
                    if (direction != sf::Vector2f(0, GRID_HEIGHT)) 
                        direction = sf::Vector2f(0, -GRID_HEIGHT);
                    break;
                case sf::Keyboard::Down:
                    if (direction != sf::Vector2f(0, -GRID_HEIGHT))
                        direction = sf::Vector2f(0, GRID_HEIGHT);
                    break;
                case sf::Keyboard::Left:
                    if (direction != sf::Vector2f(GRID_WIDTH, 0))
                        direction = sf::Vector2f(-GRID_WIDTH, 0);
                    break;
                case sf::Keyboard::Right:
                    if (direction != sf::Vector2f(-GRID_WIDTH, 0))
                        direction = sf::Vector2f(GRID_WIDTH, 0);
                    break;
                default:
                    break;
                }
            }
        }

        if (clock.getElapsedTime().asSeconds() >= frameDelay && alive)
        {
            clock.restart();

            alive = snake.move(&apple, direction);

            window.clear();
            window.draw(&grid[0], grid.size(), sf::Lines);
            snake.draw(&window);
            apple.draw(&window);
            window.display();
        }
    }

    return 0;
}
