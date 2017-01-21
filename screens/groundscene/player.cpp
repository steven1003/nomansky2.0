#include "player.hpp"
#include <iostream>

Player::Player() {
    shape.setSize(sf::Vector2f(32, 32));
    shape.setFillColor(sf::Color::Red);
    boundingBox.boxes.push_back(sf::FloatRect(0, 0, 32, 32));
}

void Player::tick() {
    // std::cout << vel.x << " " << vel.y << std::endl;
    // prevpos = pos;
    boundingBox.shiftBoxes(vel);
    pos += vel;
    // std::cout << prevpos.x << " " << prevpos.y << " " << pos.x << " " << pos.y << std::endl;
    // std::cout << "vel: " << vel.x << " " << vel.y << std::endl;
    // std::cout << boundingBox.boxes[0].top << std::endl;
    shape.setPosition(pos);
    // pos.y += 0.1;
}

void Player::move() {
    vel.x = 0;
    vel.y = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        vel.x = -0.1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        vel.x = 0.1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        vel.y = -0.3;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        vel.y = 0.1;
    }
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

void Player::setView(sf::RenderWindow &window, sf::View &view) {
    view.setCenter(pos);
    window.setView(view);
}