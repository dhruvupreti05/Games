#include <SFML/Graphics.hpp>
#include <vector>

#ifndef PLANETS_H
#define PLANETS_H

class Planet
{
private:

    static constexpr float G = 1;

    float mass;
    sf::Vector2f velocity;
    sf::CircleShape body;

public:

    static std::vector<Planet> planets;

    bool move(float dt);
    float distance(Planet& planet) const;
    const sf::Vector2f gravity() const;
    const sf::Vector2f impact(float dt) const;
    void draw(sf::RenderWindow& window) const;
    Planet(float mass, const sf::Vector2f& position, const sf::Vector2f& velocity);

    inline const float getMass() const { return mass; }
    inline const sf::CircleShape& getBody() const { return body; }
};

#endif