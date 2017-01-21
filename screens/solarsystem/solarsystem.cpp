#include "solarsystem.hpp"

#include "sun.hpp"
#include "planet.hpp"
#include "spaceplayer.hpp"

SolarSystem::SolarSystem() {
    std::cout << "Generating SolarSystem" << std::endl;
}
SolarSystem::SolarSystem(sf::Vector2f bounds) {
    entities.push_back(new SpacePlayer());
    shape.setRadius(sqrt(bounds.x * bounds.y) / 10);
    shape.setPosition(sf::Vector2f(rand() & 700, rand() & 500));
    this->bounds = bounds;
    sf::Vector2i center = sf::Vector2i(bounds.x / 2, bounds.y / 2);
    entities.push_back(new Sun(sf::Vector2f(rand() % ((int)bounds.x - 100) + 100 , rand() % ((int)bounds.y - 100) + 100), "Cool star"));

    for (int i = 0; i < rand() % 7 + 2; i++)
        entities.push_back(new Planet(sf::Vector2f(rand() % (int)bounds.x, rand() % (int)bounds.y), (Sun*)entities[1]));

}
void SolarSystem::tick() {
    for (auto const &e : entities) {
        e->move();
        e->tick();
    }
}

void SolarSystem::draw(sf::RenderWindow &window) {
    auto view = window.getDefaultView();
    ((SpacePlayer*)entities[0])->setView(window, view);
    for (auto const &e : entities) {
        e->draw(window);
    }
}
void SolarSystem::drawIcon(sf::RenderWindow &window) {
    window.draw(shape);
}

bool SolarSystem::checkIconClick(sf::RenderWindow &window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        return shape.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
    }
}