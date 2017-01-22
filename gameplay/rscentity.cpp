#include "rscentity.hpp"

RscEntity::RscEntity(std::string texturefile){
  name = "";
  numOf = 0;
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