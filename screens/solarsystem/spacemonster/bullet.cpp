#include "bullet.hpp"

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f vel) {
    std::cout << "Made bullet" << std::endl;
    this->pos = pos;
    this->vel = vel;
    shape.setSize(sf::Vector2f(5, 10));
    shape.setFillColor(sf::Color::White);
    shape.rotate(std::atan2(vel.y, vel.x) * 180 / 3.1415);
}

void Bullet::tick() {
    pos += vel;
    shape.setPosition(pos);
}
void Bullet::move() {
    std::cout << "ticked" << std::endl;

}

void Bullet::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

bool Bullet::alive() {
    if (clock.getElapsedTime().asSeconds() > 5) return false;
    return true;
}