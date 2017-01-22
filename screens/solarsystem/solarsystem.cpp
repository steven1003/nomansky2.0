#include "solarsystem.hpp"

#include "sun.hpp"
#include "planet.hpp"
#include "spaceplayer.hpp"
#include "spacemonster/spacemonster.hpp"
#include "../../gui/gui.hpp"
#include "../../gameplay/rsccs/masterrsc.hpp"

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
    for (int i = 0; i < rand() % 50 + 10; i++)
        entities.push_back(new SpaceMonster((SpacePlayer*)entities[0]));
    // }

}
int SolarSystem::tick(GroundScene* groundScene) {
    SpacePlayer* player = (SpacePlayer*)entities[0];
    for (auto const &e : entities) {
        e->move();
        e->tick();
        if (dynamic_cast<Planet*>(e)) {
            float dx = player->center.x - e->center.x;
            float dy = player->center.y - e->center.y;
            float d = sqrt(dx * dx + dy * dy);
            if (d < e->mass) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    *groundScene = GroundScene();
                    return 5;
                }
            }
        }
    }
    return 0;
}

void SolarSystem::draw(sf::RenderWindow &window) {
    auto view = window.getDefaultView();
    ((SpacePlayer*)entities[0])->setView(window, view);
    ((SpacePlayer*)entities[0])->tickEntites(entities, window);

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

void SolarSystem::launchMiner(gui::inventory inv)
{
    if(inv.removeItem("LaserMiner", 1))
    {
      //entities.push_back(new LaserMiner())
    }
}
