#pragma once

#include "../rscentity.hpp"
#include "../../gui/gui.hpp"

class Dilithium: public RscEntity{
public:
  Dilithium(int num) : RscEntity("", "Dilithium", num){};


private:

};

class Armor:public RscEntity{
public:
  Armor() : RscEntity("", "Dilithium Armor", 0) {};


private:

};

class LaserMiner: public RscEntity{
public:
  LaserMiner() : RscEntity("", "Dilithium Miner", 0){};
  void mineRsc(gui::inventory inv){};
  void deployMiner(){};
private:
};
