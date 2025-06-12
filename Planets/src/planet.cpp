#include <SFML/Graphics.hpp>
#include <cmath>

#include "planet.h"
#include "constants.h"

std::vector<Planet> Planet::planets;

Planet::Planet(float mass, const sf::Vector2f& position, const sf::Vector2f& velocity)
{    
    this->mass = mass;
    body.setPosition(position);
    body.setFillColor(sf::Color::Green);
    this->velocity = velocity; 
}

bool Planet::move(float dt)
{
    sf::Vector2f force = gravity() + impact(dt);
    velocity += dt*force/mass;
    body.setPosition(dt*velocity);

    if (body.getPosition().x < 0 || body.getPosition().x >= WINDOW_WIDTH ||
        body.getPosition().y < 0 || body.getPosition().y >= WINDOW_HEIGHT)
    {
        return true; 
    }
    return false;
}

const sf::Vector2f Planet::gravity() const
{
    sf::Vector2f force = sf::Vector2f(0,0);
    for (Planet& satellite : Planet::planets)
    {   
        force += static_cast<float>(G * mass * satellite.getMass() / std::pow(distance(satellite), 2)) *
        (satellite.getBody().getPosition() - body.getPosition());    
    }
    return force;
}
 
const sf::Vector2f Planet::impact(float dt) const
{
    sf::Vector2f force = sf::Vector2f(0,0);
    for (Planet& satellite : Planet::planets) 
    {    
        if (distance(satellite) <= body.getRadius() + satellite.getBody().getRadius())
        {
            force += mass*(satellite.getBody().getPosition() - body.getPosition())/dt;
        }
    }
    return force;
}

float Planet::distance(Planet& planet) const
{
    sf::Vector2f diff = planet.getBody().getPosition() - body.getPosition();
    return sqrt(diff.x*diff.x + diff.y*diff.y);
}

void Planet::draw(sf::RenderWindow& window) const
{
    window.draw(body);
}

