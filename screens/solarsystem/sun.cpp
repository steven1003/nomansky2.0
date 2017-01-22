#include "sun.hpp"

Sun::Sun() {
    std::cout << "Generating sun" << std::endl;
}

Sun::Sun(sf::Vector2f pos, std::string name) {
    std::cout << "Generating sun at " << pos.x << " " << pos.y << std::endl;
    this->name = name;
    this->pos = pos;
    this->vel = sf::Vector2f(0, 0);
    this->mass = rand() % 100 + 50;
    shape.setPosition(pos);
    shape.setRadius(mass);
    shape.setFillColor(sf::Color::Red);
    center = sf::Vector2f(pos.x + mass , pos.y + mass);
}

void Sun::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

void Sun::tick() {

}

void Sun::move() {}