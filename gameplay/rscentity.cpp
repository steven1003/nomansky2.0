#include "rscentity.hpp"

RscEntity::RscEntity(){
  name = "";
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
