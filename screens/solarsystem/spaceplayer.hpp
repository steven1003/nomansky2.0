#pragma once
#include "sysentity.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class SpacePlayer : public SysEntity {


public:
    SpacePlayer();
    sf::RectangleShape rect;
    virtual void move();
    virtual void draw(sf::RenderWindow &window);
    virtual void tick();

    void setView(sf::RenderWindow &window, sf::View &view);
    void tickEntites(const std::vector<SysEntity*> &entities, sf::RenderWindow &window);
};