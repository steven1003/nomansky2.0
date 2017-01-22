#include "planet.hpp"
Planet::Planet(int x, int y, std::string name, sf::CircleShape circle) {
    xCord =x ;
    yCord = y;
    shape = circle;
    shape.setPosition(sf::Vector2f(x,y));
}
