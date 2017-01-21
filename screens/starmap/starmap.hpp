#pragma once

#include <SFML/Graphics.hpp>
#include "../cscreen.hpp"
#include <iostream>
#include "../spacescene.hpp"
#include "../solarsystem/solarsystem.hpp"


class StarMap : public CScreen {
public:
    StarMap();
    StarMap(SpaceScene* scene);
    virtual int run (sf::RenderWindow &window);
    std::vector<SolarSystem> solarSystem;
private:
    SpaceScene* spaceScene;
};