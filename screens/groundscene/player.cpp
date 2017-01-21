#include "player.hpp"
#include <iostream>

Player::Player(){
    anim.init("rsc/player.png", 24, 40, 7, true);
    shape.setSize(sf::Vector2f(32, 32));
    shape.setFillColor(sf::Color::Red);
    boundingBox.boxes.push_back(sf::FloatRect(0, 0, 32, 32));
    part = 0;
}
void Player::tick() {
    // std::cout << vel.x << " " << vel.y << std::endl;
    boundingBox.shiftBoxes(vel);
    pos += vel;
    // std::cout << prevpos.x << " " << prevpos.y << " " << pos.x << " " << pos.y << std::endl;
    // std::cout << "vel: " << vel.x << " " << vel.y << std::endl;
    // std::cout << boundingBox.boxes[0].top << std::endl;
    anim.setPosition(pos);
    // pos.y += 0.1;
}

void Player::move() {
    vel.x = 0;
    vel.y = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        vel.x = -0.8;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        vel.x = 0.8;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        vel.y = -0.3;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        vel.y = 0.6;
    }
    if (clock.getElapsedTime().asSeconds() > 0.5f) {
        anim.setTextureRect(part);
        clock.restart();
        if (part == 6) {
            part = 0;
        } else {
            part++;
        }
    }
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(anim.getSprite());
}

void Player::setView(sf::RenderWindow &window, sf::View &view) {
    view.setCenter(pos);
    window.setView(view);
}
