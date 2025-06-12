#include "constants.h"
#include "apple.h"
#include <random>

Apple::Apple(const std::vector<sf::RectangleShape>& invalidPos)
{
    newApple(invalidPos); 
}

void Apple::draw(sf::RenderWindow& window)
{
    window.draw(apple);
}

sf::RectangleShape& Apple::getApple()
{
    return apple;
}

void Apple::newApple(const std::vector<sf::RectangleShape>& invalidPos)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distX(0, WINDOW_WIDTH / GRID_WIDTH - 1);
    std::uniform_int_distribution<> distY(0, WINDOW_HEIGHT / GRID_HEIGHT - 1);

    while (true)
    {
        int x = distX(gen) * GRID_WIDTH;
        int y = distY(gen) * GRID_HEIGHT;

        bool valid = true;
        for (const sf::RectangleShape &shape : invalidPos)
        {
            if (shape.getPosition() == sf::Vector2f(x, y))
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            apple.setSize(sf::Vector2f(GRID_WIDTH, GRID_HEIGHT));
            apple.setFillColor(sf::Color::Red);
            apple.setPosition(x, y);
            break;
        }
    }
}
