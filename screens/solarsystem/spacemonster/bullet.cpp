#include "bullet.hpp"

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f vel) {
    this->pos = pos;
    this->vel = vel;
    this->mass = 0;
    shape.setSize(sf::Vector2f(50, 5));
    shape.setFillColor(sf::Color::White);
    shape.rotate(std::atan2(vel.y, vel.x) * 360 / 3.1415);
}

void Bullet::tick() {
    pos += vel;
    shape.setPosition(pos);
}
void Bullet::move() {

}

void Bullet::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

bool Bullet::alive() {
    if (clock.getElapsedTime().asSeconds() > 5) return false;
    return true;
}