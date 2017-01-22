#pragma once

#include "../groundscene/groundscene.hpp"
#include <string>
#include "sysobject.hpp"
class Planet: public SysObject{
public:
  sf::CircleShape shape;
//  GroundScene scene;
//#TODO
Planet();
Planet(int x, int y, std::string name, sf::CircleShape circle);
  //Each planet has a instance of land on it that is derived from GroundScene.

};
