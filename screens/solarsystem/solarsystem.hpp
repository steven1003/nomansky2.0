#pragma once

#include <vector>
#include "sysentity.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class SolarSystem {
private:
    sf::Vector2f bounds;
    sf::CircleShape shape;
public:
    SolarSystem();
    SolarSystem(sf::Vector2f bounds);
    std::vector<SysEntity*> entities;
    void tick();
    void draw(sf::RenderWindow &window);
    void drawIcon(sf::RenderWindow &window);
    bool checkIconClick(sf::RenderWindow &window);
};