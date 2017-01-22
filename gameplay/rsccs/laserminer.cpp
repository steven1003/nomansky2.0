#include "masterrsc.hpp"
#include

LaserMiner::LaserMiner()
{

    void mineRsc(inventory inv){
      while(true)
      {
      if(inv.addQuantity("Dilithium", 200))
      {
      }
      else
      {
        RscEntity d = Dilithium();
        inv.addItem(d);
      }
      delay(5000);
    }
  }

}
