#pragma once

#include <vector>

class BoundingBox {

public:
    BoundingBox();
    std::vector<sf::IntRect> boxes;
    bool intersects(BoundingBox &b);
    void shiftBoxes(sf::Vector2f &shift);
};