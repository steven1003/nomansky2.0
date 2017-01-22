#include "recipes.hpp"
#include "rsccs/masterrsc.hpp"

Recipes::Recipes(std::string name, std::string in,RscEntity* output, int numOf){
  this->name = name;
  this->numOf = numOf;
  this->output = output;
  this->input = std::vector<std::string>({in});
}

std::string Recipes::getName()
{
  return name;
}

std::vector<std::string> Recipes::getInput()
{
  return input;
}

RscEntity* Recipes::getOutput()
{
  return output;
}

RscEntity* Recipes::craftRecipe(gui::inventory inv, std::string name, int amount)
{
  RscEntity d = Armor();
  inv.addItem(d);
  inv.addQuantity("Armor", 1);
  inv.removeItem("Dilithium", 200);
  return output;
}
