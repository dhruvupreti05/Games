#ifndef APPLE_H
#define APPLE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Apple
{
private:
    sf::RectangleShape apple;

public:
    Apple(const std::vector<sf::RectangleShape>& invalidPos); 

    void draw(sf::RenderWindow& window);
    void newApple(const std::vector<sf::RectangleShape>& invalidPos);
    sf::RectangleShape& getApple();
};

#endif