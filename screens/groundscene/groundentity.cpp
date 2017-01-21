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
    vel.y -=.6;
    //vel.x =.3;
    // pos += vel;
    // vel = -2*vel;
    // std::cout << "Go back!" << std::endl;
    // std::cout << vel.x << " " << vel.y << std::endl;
}
void GroundEntity::noClip()
{
  pos = prevpos;
}

void GroundEntity::setGravity(sf::Vector2f grav)
{
  vel.y += grav.y;
}

void GroundEntity::move(sf::Vector2f &vel) {
    pos += vel;
}
