#pragma once

#include "sysentity.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "sun.hpp"

class Planet : public SysEntity {

private:
    Sun* parentSun;
    float sunDistance;
public:
    Planet();
    Planet(sf::Vector2f pos, Sun* parentSun);
   
    sf::CircleShape shape;

    virtual void move();
    virtual void draw(sf::RenderWindow &window);
    virtual void tick();

};