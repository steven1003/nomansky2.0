#include "spaceplayer.hpp"

SpacePlayer::SpacePlayer() {
    std::cout << "Generated player" << std::endl;
    rect.setSize(sf::Vector2f(20, 20));
    rect.setFillColor(sf::Color::Magenta);
    mass = 20;
    center = sf::Vector2f(pos.x + mass/2, pos.y + mass/2);

}

void SpacePlayer::tick() {
    pos += vel;
    center = sf::Vector2f(pos.x + mass/2, pos.y + mass/2);
    rect.setPosition(pos);
}
void SpacePlayer::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        vel.x += -0.0001;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        vel.x += 0.0001;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        vel.y += -0.0001;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
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
void SpacePlayer::tickEntites(const std::vector<SysEntity*> &entities, sf::RenderWindow &window) {
    for (auto const &e : entities) {
        if (e == (SysEntity*)this) continue;
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