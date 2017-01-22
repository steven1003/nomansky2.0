#include "masterrec.hpp"


// ArmorRec::ArmorRec(){
//   name = "Dilithium Armor";
//   input = std::vector<std::string>({"Dilithium"});
//   output = &Armor;
//   int numOf = 1;
// }

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

RscEntity ArmorRec::craftRecipe(gui::inventory inv, std::string name, int amount)
{
    inv.addItem(Armor);
    inv.addQuantity("Armor", 1);
    inv.removeItem("Dilithium", 200);
    return this->Armor;
}
