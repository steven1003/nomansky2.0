#include "sysobject.hpp"
#include "asteroid.hpp"
#include "planet.hpp"
#include "sun.hpp"
class StarSystem{


public:
  StarSystem();
  std::vector<SysObject> shapes;
  //Future implementation get a way forl the player to get information about a planet and asteroid and sun.
  //Maybe scanning system?
  Planet getPlanet(Planet planet);
  Asteroid getAsteroid(Asteroid asteroid);
  Sun getSun(Sun sun);
  StarSystem getSystem(std::vector<SysObject> systemObjects);

private:


};
