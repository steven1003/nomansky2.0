#pragma once
#include "../recipes.hpp"
#include "../rsccs/armor.hpp"

class LaserMinerRec:public Recipes{
public:
  LaserMinerRec() : Recipes("Laser Miner", "Dilithium", (RscEntity*)(new LaserMiner()),1){};

private:

};

class ArmorRec:public Recipes{
public:
  ArmorRec() : Recipes("Dilithium Armor","Dilithium", (RscEntity*)(new Armor()), 1) {};


private:

};
