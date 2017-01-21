#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "sysobject.hpp"

class Sun: public SysObject{

public:
  Sun();
  Sun(int x, int y, std::string name);

private:
    sf::CircleShape shape;
};
