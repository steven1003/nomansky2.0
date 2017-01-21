#pragma once

#include <SFML/Graphics.hpp>

class SysEntity {

public:
    sf::Vector2f pos, vel, acc;
    sf::Vector2f center;
    float mass;
    virtual ~SysEntity() {}
    virtual void move() = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual void tick() = 0;

    float getDistance(const SysEntity &s);
    float getDistance(const sf::Vector2f &s);
};