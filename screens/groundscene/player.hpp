#pragma once

#include "groundentity.hpp"

class Player : public GroundEntity {
    sf::RectangleShape shape;
    Player();

    virtual void tick();
    virtual void move();
    virtual void draw();
};