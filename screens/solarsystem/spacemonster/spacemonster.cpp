#include "spacemonster.hpp"

SpaceMonster::SpaceMonster(SpacePlayer *spacePlayer) {
    std::cout << "Made SpaceMonster " << std::endl;
    shape.setSize(sf::Vector2f(10, 10));
    shape.setFillColor(sf::Color::Green);
    mass = 0;
    center = sf::Vector2f(pos.x + mass / 2, pos.y + mass / 2);
    vel = sf::Vector2f(0, 0);
    pos = sf::Vector2f(rand() % 100, rand() % 100);
    this->spacePlayer = spacePlayer;
    this->entities = entities;

    speed = 0.01 + static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    limit = rand() % 100 + 200;

}

void SpaceMonster::tick() {
    pos += vel;
    center = sf::Vector2f(pos.x + 5, pos.y + 5);
    shape.setPosition(pos);
}
void SpaceMonster::move() {
    vel.x = 0; vel.y = 0;
    sf::Vector2f dir = center - spacePlayer->center;
    angle = std::atan2(dir.y, dir.x);

    float x = std::sqrt(std::pow(dir.x, 2) + std::pow(dir.y, 2));

    if (x < limit) return;
    dir = dir / -x;
    // float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 0.5));
    if (x < 250) fire = true;
    if (x > limit + 100) fire = false;
    vel = speed * dir;
    // std::cout << r << std::endl;
}


void SpaceMonster::draw(sf::RenderWindow &window) {
    if (fire == true) {
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = center;
        line[1].position = spacePlayer->center;
        line[0].color = sf::Color::Red;
        line[1].color = sf::Color::Red;
        window.draw(line);
    }



    window.draw(shape);
}