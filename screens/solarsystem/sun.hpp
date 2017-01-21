#pragma once

#include "sysentity.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Sun : public SysEntity {

public:
    Sun();
    Sun(sf::Vector2f pos, std::string name);
   
    sf::CircleShape shape;
    std::string name;

    virtual void move();
    virtual void draw(sf::RenderWindow &window);
    virtual void tick();

};