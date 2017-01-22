#include "../recipes.hpp"
#include "armor.hpp"

class ArmorRec:public Recipes{
public:
  ArmorRec() : Recipes("Dilithium Armor","Dilithium", (RscEntity*)(new Armor()), 1) {};


private:

};
