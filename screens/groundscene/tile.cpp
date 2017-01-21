#include "tile.hpp"

Tile::Tile() {
    shape.setSize(sf::Vector2f(32,32));
    shape.setOutlineThickness(sf::Color::White);
    shape.setFillColor(sf::Color::Black);
}

void Tile::setPosition(float x, float y) {
    shape.setPosition(x,y);
}

void Tile::draw(sf::RenderWindow &window) {
    window.draw(shape);
}