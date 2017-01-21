/*
    Class to manage the actual game.
*/

#ifndef SCREEN_GAME_HPP
#define SCREEN_GAME_HPP

#include "cscreen.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <stdexcept>
#include "cscreen.hpp"

class ScreenGame : public CScreen {
public:
    ScreenGame();
    virtual ~ScreenGame();
    virtual int run(sf::RenderWindow &window);

private:
    float roughness;
    int *terrain_array;
    void generateTerrain(int leftindex, int rightindex, int displacement);
};

#endif
