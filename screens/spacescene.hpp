#pragma once

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
#include <iostream>
#include "solarsystem/solarsystem.hpp"


class SpaceScene : public CScreen {
public:
    SpaceScene();
    virtual int run (sf::RenderWindow &window);
    SolarSystem* currentSystem;
};