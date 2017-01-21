#include "boundingbox.hpp"

BoundingBox::BoundingBox() {}

bool BoundingBox::intersects(BoundingBox &b) {
    for(auto const &box1 : boxes) {
        for(auto const &box2 : b.boxes) {
            if(box1.intersects(box2)) return true;
        }
    }
    return false;
}

void BoundingBox::shiftBoxes(sf::Vector2f &shift) {
    for(auto const &box : boxes) {
        box.left += shift.x;
        box.top += shift.y;
    }
}