#include "rscentity.hpp"

RscEntity::RscEntity(std::string texturefile, std::string name, int num){
  this->name = name;
  numOf = num;
  if(texturefile != "")
    rsctext.loadFromFile(texturefile);
}
std::string RscEntity::getName()
{
  return name;
}

int RscEntity::getNum()
{
    return numOf;
}

sf::Texture RscEntity::getTexture()
{
  return rsctext;
}

void RscEntity::addItem(int num) {
	this->numOf += num;
}

void RscEntity::setTexture(sf::Texture text)
{
  rsctext = text;
}
