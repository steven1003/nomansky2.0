#include "spaceplayer.hpp"

SpacePlayer::SpacePlayer() {
    std::cout << "Generated player" << std::endl;
    rect.setSize(sf::Vector2f(20, 20));
    rect.setFillColor(sf::Color::Magenta);
    mass = 20;
    center = sf::Vector2f(pos.x + mass / 2, pos.y + mass / 2);
    angle = 0;
}

void SpacePlayer::tick() {
    pos += vel;
    center = sf::Vector2f(pos.x + mass / 2, pos.y + mass / 2);
    rect.setPosition(pos);
}
void SpacePlayer::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        vel.x += -0.0001;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        vel.x += 0.0001;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        vel.y += -0.0001;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        vel.y += 0.0001;
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        fire = true;
    }
    else fire = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        angle += 0.1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        angle -= 0.1;
    }
    // std::cout << angle << std::endl;
}
void SpacePlayer::draw(sf::RenderWindow &window) {
    window.draw(rect);
}

void SpacePlayer::setView(sf::RenderWindow &window, sf::View &view) {
    view.setCenter(pos);
    window.setView(view);
}
void SpacePlayer::tickEntites(const std::vector<SysEntity*> &entities, sf::RenderWindow &window) {
    for (auto const &e : entities) {
        if (e == (SysEntity*)this) continue;
        if (e->mass < 50) continue;
        float dx = center.x - e->center.x;
        float dy = center.y - e->center.y;
        float d = sqrt(dx * dx + dy * dy);
        if (d <= mass) continue;
        float f = 0.001 * mass * e->mass / (d * d);
        // std::cout << f << std::endl;
        vel.x -= f * (dx / d);
        vel.y -= f * (dy / d);

        sf::Vertex line[] =
        {
            sf::Vertex(center),
            sf::Vertex(e->center)
        };

        window.draw(line, 2, sf::Lines);
    }
}

bool SpacePlayer::shouldFire() {
    if(fire && clock.getElapsedTime().asSeconds() > 0.1) {
        clock.restart();
        return true;
    }
    return false;
}

sf::Vector2f SpacePlayer::dirVec() {
    return sf::Vector2f(std::acos(angle*3.1415/360), std::asin(angle*3.1415/360));
}