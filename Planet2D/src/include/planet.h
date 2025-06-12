#include <SFML/Graphics.hpp>
#include <vector>

#ifndef PLANETS_H
#define PLANETS_H

class Planet
{
private:

    static constexpr float G = 100;
    static constexpr int length = 25;

    int iteration;
    std::vector<sf::Vector2f> pastPositions;

    float mass;
    sf::CircleShape body;
    sf::Vector2f velocity;

public:

    static std::vector<Planet> planets;
    Planet(float mass, float radius, const sf::Vector2f& position, const sf::Vector2f& velocity);

    bool move(float dt);
    bool hitBoundary() const;
    const sf::Vector2f gravity() const;
    float distance(Planet& planet) const;
    void draw(sf::RenderWindow& window) const;
    const sf::Vector2f impulse(float dt) const;

    inline const float getMass() const { return mass; }
    inline const sf::CircleShape& getBody() const { return body; }
};

#endif