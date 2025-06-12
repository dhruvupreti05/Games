#include <utility>

#include "constants.h"
#include "snake.h"
#include "apple.h"

Snake::Snake() 
{
    sf::RectangleShape head(sf::Vector2f(25.f, 25.f));
    head.setFillColor(sf::Color::Green);
    head.setPosition(100.f, 100.f);
    body.push_back(head);
}

bool Snake::move(Apple& apple, const sf::Vector2f& pos)
{
    sf::Vector2f nextPos = body[0].getPosition() + pos;

    if (nextPos.x < 0 || nextPos.x >= WINDOW_WIDTH ||
        nextPos.y < 0 || nextPos.y >= WINDOW_HEIGHT)
    {
        return false; 
    }

    for (size_t i = 1; i < body.size(); ++i) {
        if (body[i].getPosition() == nextPos)
            return false; 
    }

    if (apple.getApple().getPosition() == nextPos)
        apple.newApple(body);
    else
        body.pop_back();

    sf::RectangleShape newHead(sf::Vector2f(GRID_WIDTH, GRID_HEIGHT));
    newHead.setFillColor(sf::Color::Green);
    newHead.setPosition(nextPos);
    body.insert(body.begin(), newHead);

    return true;
}

void Snake::draw(sf::RenderWindow& window)
{
    for (sf::RectangleShape& part : body)
    {
        window.draw(part);
    }
}

const std::vector<sf::RectangleShape>& Snake::getBody() const
{
    return body;
}
