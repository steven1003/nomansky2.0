#include "groundentity.hpp"
#include <iostream>

bool GroundEntity::intersects(GroundEntity &e) {
    return boundingBox.intersects(e.boundingBox);
}

bool GroundEntity::intersects(sf::FloatRect b) {
    return boundingBox.intersects(b);
}

void GroundEntity::goBack() {
    // pos = prevpos;
    vel.x = -vel.x;
    vel.y = -vel.y;
    // pos += vel;
    // vel = -2*vel;
    // std::cout << "Go back!" << std::endl;
    // std::cout << vel.x << " " << vel.y << std::endl;
}

void GroundEntity::move(sf::Vector2f &vel) {
    pos += vel;
}