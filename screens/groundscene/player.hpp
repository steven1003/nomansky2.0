#pragma once

#include "groundentity.hpp"

class Player : public GroundEntity {
public:
    sf::RectangleShape shape;
    Player();

    virtual void tick();
    virtual void move();
    virtual void draw(sf::RenderWindow &window);

    void setView(sf::RenderWindow &window, sf::View &view);
private:
    int part;
    sf::Clock clock;
};
