#include "sun.hpp"
Sun::Sun() {}
Sun::Sun(int x, int y, std::string name) {
    shape.setRadius(10.0f);
    shape.setPosition(sf::Vector2f(x,y));
}
