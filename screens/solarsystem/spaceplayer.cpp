#include "spaceplayer.hpp"

SpacePlayer::SpacePlayer() {
    std::cout << "Generated player" << std::endl;
    rect.setSize(sf::Vector2f(20, 20));
    rect.setFillColor(sf::Color::Magenta);
}

void SpacePlayer::tick() {
    pos += vel;
    rect.setPosition(pos);
}
void SpacePlayer::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        vel.x += -0.0001;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        vel.x += 0.0001;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        vel.y += -0.0001;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        vel.y += 0.0001;
    }
}
void SpacePlayer::draw(sf::RenderWindow &window) {
    window.draw(rect);
}

void SpacePlayer::setView(sf::RenderWindow &window, sf::View &view) {
    view.setCenter(pos);
    window.setView(view);
}