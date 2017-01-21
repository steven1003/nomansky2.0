#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

class BoundingBox {

public:
    BoundingBox();
    std::vector<sf::FloatRect> boxes;
    bool intersects(BoundingBox &b);
    bool intersects(sf::FloatRect &b);
    void shiftBoxes(sf::Vector2f &shift);
};