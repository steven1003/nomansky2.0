#include "../recipes.hpp"
#include "../rsccs/armor.hpp"

class ArmorRec:public Recipes{
public:
  ArmorRec() : Recipes("Dilithium Armor","Dilithium", (RscEntity*)(new Armor()), 1) {};


private:

};
