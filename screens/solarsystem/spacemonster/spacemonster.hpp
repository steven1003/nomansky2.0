#pragma once
#include "../sysentity.hpp"
#include "../spaceplayer.hpp"
#include "bullet.hpp"

class SpaceMonster : public SysEntity {
private:
    sf::RectangleShape shape;
    SpacePlayer* spacePlayer;
    std::vector<SysEntity*> *entities;
    bool fire;
    float angle;
    sf::Clock clock;
    float speed;
    int limit;
public:
    SpaceMonster();
    SpaceMonster(SpacePlayer *spacePlayer);
    virtual void move();
    virtual void tick();
    virtual void draw(sf::RenderWindow &window);

};