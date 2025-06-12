#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>

#include "planet.h"
#include "constants.h"

std::vector<Planet> Planet::planets;

Planet::Planet(float mass, float radius, const sf::Vector2f& position, const sf::Vector2f& velocity)
{    
    iteration = 0;

    this->mass = mass;
    body.setRadius(radius);
    this->velocity = velocity; 
    body.setPosition(position);
    body.setOrigin(radius, radius);
    body.setFillColor(sf::Color::Green);

}

bool Planet::move(float dt)
{
    sf::Vector2f force = gravity() + impulse(dt);
    velocity += dt*force/mass;

    pastPositions.insert(pastPositions.begin() + iteration%length, body.getPosition());
    body.setPosition(body.getPosition()+dt*velocity);
    iteration += 1;

    if (hitBoundary()) return true;
    return false;
}

const sf::Vector2f Planet::gravity() const
{
    sf::Vector2f force = sf::Vector2f(0,0);
    for (Planet& satellite : planets)
    {   
        if (this == & satellite) continue;
        force += static_cast<float>(G * mass * satellite.getMass() / std::pow(distance(satellite), 2)) *
        (satellite.getBody().getPosition() - body.getPosition());    
    }
    return force;
}
 
const sf::Vector2f Planet::impulse(float dt) const
{
    sf::Vector2f force = sf::Vector2f(0,0);
    for (Planet& satellite : planets) 
    {    
        if (this == & satellite) continue;
        if (distance(satellite) <= body.getRadius() + satellite.getBody().getRadius() || hitBoundary())
        {
            force += mass*(-2.0f*velocity)/dt; // (ideally perfectly elastic collision)
        }
    }
    return force;
}

float Planet::distance(Planet& planet) const
{
    sf::Vector2f diff = planet.getBody().getPosition() - body.getPosition();
    return sqrt(diff.x*diff.x + diff.y*diff.y);
}

bool Planet::hitBoundary() const
{
    return body.getPosition().x < 0 || body.getPosition().x >= WINDOW_WIDTH ||
           body.getPosition().y < 0 || body.getPosition().y >= WINDOW_HEIGHT;
}

void Planet::draw(sf::RenderWindow& window) const
{
    window.draw(body);
    if (pastPositions.size() < 2) return;
    
    //for (std::size_t i = 0; i < iteration%length; i++)
    //{
    //    sf::Vertex vertex[] = 
    //    {
    //        sf::Vertex(pastPositions[i], sf::Color::White),
    //        sf::Vertex(pastPositions[i+1], sf::Color::White)
    //    };
    //    window.draw(vertex, 2, sf::Lines);
    //}
}
