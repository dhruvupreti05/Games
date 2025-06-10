#include <SFML/Graphics.hpp>
#include <iostream>

int main() 
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
   
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    player.setFillColor(sf::Color::White);
    player.setOrigin(50.0f, 50.0f);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("./tux.jpg");
    player.setTexture(&playerTexture);

    sf::Clock clock; // For measuring elapsed time
    const float frameDelay = 0.25f; // seconds

    while (window.isOpen()) 
{
    sf::Event evnt;  
    while (window.pollEvent(evnt)) 
    {
        if (evnt.type == sf::Event::Closed)
            window.close();
        else if (evnt.type == sf::Event::Resized)
            printf("New width: %i, new height: %i\n", evnt.size.width, evnt.size.height);
        else if (evnt.type == sf::Event::TextEntered)
            if (evnt.text.unicode < 128)
                printf("%c", evnt.text.unicode);
    }

    // ✅ Always check input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.move(-25, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.move(25, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player.move(0, -25);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player.move(0, 25);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        player.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }

    // Only control render frequency
    if (clock.getElapsedTime().asSeconds() >= frameDelay)
    {
        window.clear();
        window.draw(player);
        window.display();

        clock.restart();
    }
}


    return 0;
}
