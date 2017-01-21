#ifndef SCREEN_GAME_HPP
#define SCREEN_GAME_HPP

#include "../cscreen.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <stdexcept>

class SpaceScene : public CScreen {
public:
    //#TODO --> every space scene loads a starsystem StarSystem starSystem;
    SpaceScene();
    virtual int run(sf::RenderWindow &window);
    std::vector<SysObject> generateSystem(int leftindex, int rightindex, int numsysobjects);
private:
  //#TODO
  //Add all functions and variables into SpaceScene
    void draw();
};

#endif
