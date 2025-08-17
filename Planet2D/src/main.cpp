#include <SFML/Graphics.hpp>
#include <iostream>

#include "constants.h"
#include "planet.h"

int main()
{
    bool stop = false;
    sf::Clock clock;
    const float frameDelay = 0.1f;

    sf::RenderWindow window(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "Planet Simulator", sf::Style::Close | sf::Style::Titlebar);
    Planet::planets.push_back(Planet(25.0f, 5.0f, sf::Vector2f(400, 250), sf::Vector2f(-250.0f, 250.0f)));
    Planet::planets.push_back(Planet(1000.0f, 50.0f, sf::Vector2f(800, 500), sf::Vector2f(0, 0)));
    Planet::planets.push_back(Planet(100.0f, 10.0f, sf::Vector2f(600, 600), sf::Vector2f(0, 0)));

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        if (clock.getElapsedTime().asSeconds() >= frameDelay) //  && !stop
        {
            clock.restart();
            window.clear(sf::Color(0, 0, 0));

            for (Planet& planet : Planet::planets)
            {
                planet.draw(window);
                stop |= planet.move(frameDelay);
            }

            window.display();
        }
    }
    return 0;
}