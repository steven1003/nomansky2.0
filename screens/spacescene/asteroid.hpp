#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "sysobject.hpp"
class Asteroid: public SysObject{
  sf::CircleShape shape;
public:
  Asteroid();
  Asteroid(int x, int y, std::string name, sf::CircleShape circle);
};
