#include "armorrec.hpp"

ArmorRec::ArmorRec(){
  name = "Dilithium Armor";
  input = sf::Vector2f<std::string,int>({"Dilithium", 200});
  output = &Armor;
  int numOf = 1;
}

sf:std::Vector2f<std::string,int> ArmorRec::getInput()
{
  return input;
}

std:string ArmorRec::getName()
{
  return name;
}

RscEntity ArmorRec::getOutput()
{
  return output;
}

RscEntity ArmorRec::craftRecipe(RscEntity res1, int numOfRes)
{
    //Remove items from inventory
    //add item
    Armor::setNum(1);
    return;
}
