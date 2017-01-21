/*
    Class to manage the actual game.
*/

#ifndef SCREEN_GAME_HPP
#define SCREEN_GAME_HPP

#include "../cscreen.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <stdexcept>
#include "tile.hpp"
#include "player.hpp"
#include "groundentity.hpp"
#include <vector>

class GroundScene : public CScreen {
public:
    GroundScene();
    virtual ~GroundScene();
    virtual int run(sf::RenderWindow &window);
    sf::Vector2f gravity;
private:
    std::vector<GroundEntity*> entities;
    float roughness;
    int *terrain_array;
    Player *p;
    void generateTerrain(int leftindex, int rightindex, int displacement);
};

#endif
