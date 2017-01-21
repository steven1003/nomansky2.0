#include "rscentity.hpp"

RscEntity::RscEntity(){
  name = "";
  numOf = 0;
  rsctext = NULL;
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
