#include "armor.hpp"

Armor::Armor(){
  name = "Dilithium Armor";
  numOf = 0;
  rsctext;
}

std::string getName()
{
  return name;
}

int getNum()
{
    return numOf;
}

void setNum(int num)
{
  numOf += num;
}

sf::Texture getTexture()
{
  return rsctext;
}

void setTexture(sf::Texture text)
{
  rsctext = text;
}
