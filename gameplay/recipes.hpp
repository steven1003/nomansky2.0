#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "../gui/gui.hpp"

class Recipes{
public:
 Recipes(std::string name, std::string in,RscEntity* output, int numOf);
 std::vector<std::string> getInput();
 std::string getName();
 RscEntity* getOutput();
 RscEntity* craftRecipe(gui::inventory inv, std::string name, int amount);

private:
  std::string name;
  std::vector<std::string> input;
  RscEntity* output;
  int numOf;
};
