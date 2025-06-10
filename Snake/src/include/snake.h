#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Apple;  

class Snake 
{
private:
    std::vector<sf::RectangleShape> body;

public:
    Snake(); 

    bool move(Apple* apple, sf::Vector2f& pos);
    const std::vector<sf::RectangleShape>& getBody() const;
    void draw(sf::RenderWindow *window);   
};

#endif 
