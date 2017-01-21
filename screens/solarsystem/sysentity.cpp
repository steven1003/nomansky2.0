#include "sysentity.hpp"

float SysEntity::getDistance(const SysEntity &s) {
    return sqrt(pow(pos.x - s.pos.x,2) + pow(pos.y - s.pos.y,2));
}

float SysEntity::getDistance(const sf::Vector2f &s) {
    return sqrt(pow(pos.x - s.x,2) + pow(pos.y - s.y,2));
}