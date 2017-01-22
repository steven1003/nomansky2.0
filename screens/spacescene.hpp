#pragma once

#include <SFML/Graphics.hpp>
#include "cscreen.hpp"
#include <iostream>
#include "solarsystem/solarsystem.hpp"
#include "groundscene/groundscene.hpp"


class SpaceScene : public CScreen {
private:
    GroundScene* groundScene;
public:
    SpaceScene();
    SpaceScene(GroundScene* groundScene);
    virtual int run (sf::RenderWindow &window);
    SolarSystem* currentSystem;
};