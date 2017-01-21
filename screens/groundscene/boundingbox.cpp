#include "boundingbox.hpp"

BoundingBox::BoundingBox() {}

bool BoundingBox::intersects(BoundingBox &b) {
    for (auto const &box1 : boxes) {
        for (auto const &box2 : b.boxes) {
            if (box1.intersects(box2)) return true;
        }
    }
    return false;
}
bool BoundingBox::intersects(sf::FloatRect &b) {
    for (auto const &box1 : boxes) {
        if (box1.intersects(b)) {
            return true;
        }
    }
    return false;
}
void BoundingBox::shiftBoxes(sf::Vector2f &shift) {
    for (auto &box : boxes) {
        box.left += shift.x;
        box.top += shift.y;
    }
}
