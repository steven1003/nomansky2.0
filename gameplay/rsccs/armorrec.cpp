#include "armorrec.hpp"

ArmorRec::ArmorRec(){
  name = "Dilithium Armor";
  input = std::vector<std::string>({"Dilithium"});
  output = &Armor;
  int numOf = 1;
}

std::vector<std::string> ArmorRec::getInput()
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

    inventory::removeItem("Dilithium", 200);
    inventory::addItem(Armor);
    //Armor::addItem(1);

    return;
}
