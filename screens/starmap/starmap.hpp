#include "../spacescene/starsystem.hpp"
#include "../spacescene/spacescene.hpp"
#include <string>

class StarMap : public CScreen{


public:
  StarMap();
  virtual ~StarMap();
  virtual int run(sf::RenderWindow &window);
  //So we need all the functionality of the starmap here including all of its various functions
  //This is not going to be fun.

private:
    std::vector<StarSystem> starMap;
};
