#pragma once

#include <SFML/Graphics.hpp>

class Tile {
public:
    Tile ();
    ~Tile();
    void setPosition(float x, float y);
    void draw(sf::RenderWindow &window);
private:
    sf::RectangleShape shape;
    

};