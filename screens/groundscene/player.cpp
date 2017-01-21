#include "player.hpp"

Player::Player() {
    shape.setSize(sf::Vector2f(32,32));
    shape.setColor(sf::Color::Red);
    boundingBox.push_back(sf::IntRect(0,0,32,32));
}

void Player::tick() {
    pos += vel;
    boundingBox.shiftBoxes(pos);
}

void Player::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        vel = 0.5;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        vel = -0.5;
    }
    vel = 0;
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(shape);
}