#pragma once

#include "../sysentity.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet : public SysEntity {
private:
    sf::Clock clock;
    sf::RectangleShape shape;
public:
    Bullet(sf::Vector2f pos, sf::Vector2f vel);


    virtual void move();
    virtual void tick();
    virtual void draw(sf::RenderWindow &window);

    bool alive();
};