#pragma once

#include <vector>
#include "boundingbox.hpp"
#include <SFML/Graphics>

class GroundEntity {

protected:
    sf::Vector2f pos;
    sf::Vector2f vel;
public:
    BoundingBox boundingBox;
    bool intersects(GroundEntity &e);

    virtual void tick() = 0;
    virtual void move() = 0;
    virtual void draw(sf::RenderWindow &window) = 0;

};