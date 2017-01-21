#pragma once

#include <vector>
#include "boundingbox.hpp"
#include <SFML/Graphics.hpp>
#include "../../tools/anim.hpp"

class GroundEntity {

protected:
    sf::Vector2f pos;
    sf::Vector2f prevpos;
    sf::Vector2f vel;
    float movespeed;
    
public:
    Anim anim;
    BoundingBox boundingBox;
    bool intersects(GroundEntity &e);
    bool intersects(sf::FloatRect b);

    virtual void tick() = 0;
    virtual void move() = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
    void move(sf::Vector2f &vel);

    void goBack();
};