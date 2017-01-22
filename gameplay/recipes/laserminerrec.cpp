#include "masterrec.hpp"

std::vector<std::string> LaserMinerRec::getInput()
{
  return input;
}

std:string LaserMinerRec::getName()
{
  return name;
}

RscEntity LaserMinerRec::getOutput()
{
  return output;
}

RscEntity LaserMiner::craftRecipe(gui::inventory inv, std::string name, int amount)
{
    inv.addItem(LaserMiner);
    inv.addQuantity("Laser Miner", 1);
    inv.removeItem("Dilithium", 600);
    return this->Armor;
}
