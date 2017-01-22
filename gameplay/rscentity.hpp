#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class RscEntity{
public:
  std::string getName();
  int getNum();
  sf::Texture getTexture();
  void addItem(int num);
  RscEntity(std::string texturefile, std::string name, int num);
  void setTexture(sf::Texture text);

private:
  int numOf;
  sf::Texture rsctext;
  std::string name;



};
