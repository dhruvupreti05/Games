#include <SFML/Graphics.hpp>

#include "constants.h"
#include "planet.h"

int main()
{
    bool stop = false;
    sf::Clock clock;
    const float frameDelay = 0.01f;

    sf::RenderWindow window(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "Planet Simulator", sf::Style::Close | sf::Style::Titlebar);
    Planet::planets.push_back(Planet(50.0f, sf::Vector2f(300, 300), sf::Vector2f(1, 1)));


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

        if (clock.getElapsedTime().asSeconds() >= !stop)
        {
            clock.restart();

            for (Planet& planet : Planet::planets)
            {
                stop |= planet.move(frameDelay);
                planet.draw(window);
            }

            window.clear(sf::Color(0, 0, 0));
            window.display();
        }
    }

    return 0;
}