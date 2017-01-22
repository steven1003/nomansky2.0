#include "planet.hpp"

Planet::Planet() {
    std::cout << "Generating planet" << std::endl;
}

Planet::Planet(sf::Vector2f pos, Sun* parentSun) {
    std::cout << "Generating planet at " << pos.x << " " << pos.y << std::endl;
    this->pos = pos;
    this->vel = sf::Vector2f(0, 0);
    this->parentSun = parentSun;
    this->sunDistance = sqrt(pow(center.x - parentSun->center.x, 2) + pow(center.y - parentSun->center.y, 2));
    this->mass = rand() % 50 + 30;
    shape.setPosition(pos);
    shape.setRadius(mass);
    shape.setFillColor(sf::Color::Cyan);
}

void Planet::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

void Planet::tick() {
    pos += vel;
    center = sf::Vector2f(pos.x + mass, pos.y + mass);

    shape.setPosition(pos);
}

void Planet::move() {
    float dx = center.x - parentSun->center.x;
    float dy = center.y - parentSun->center.y;
    float vv = sqrt(0.001 * mass *parentSun->mass / sunDistance);

    vel.x = vv * (dy / sunDistance);
    vel.y = vv * (-dx / sunDistance);
}