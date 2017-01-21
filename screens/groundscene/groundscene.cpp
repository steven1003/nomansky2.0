#include "groundscene.hpp"
#include "../../tools/anim.hpp"
#include <iostream>


GroundScene::GroundScene() {
    terrain_array = new int[100];
    for (int i = 0; i < 100; i++) {
        terrain_array[i] = 0;
    }
    roughness = 0.5;
    generateTerrain(0, 99, 40);
    // p = new Player();
    // Player *player = new Player();
    // GroundEntity* player = new Player();
    entities.push_back(new Player());

    gravity = sf::Vector2f(0,0.2);
    // Player player();
}

GroundScene::~GroundScene() {}

int GroundScene::run(sf::RenderWindow &window) {
    std::cout << "running game" << std::endl;

    sf::Event Event;

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(32, 32));
    rect.setFillColor(sf::Color::Cyan);

    auto view = window.getDefaultView();

    int part = 0;

    while (window.isOpen()) {
        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed) {
                return (-1);
            }
            else if (Event.type == sf::Event::KeyPressed) {
                switch (Event.key.code) {
                case sf::Keyboard::Escape:
                    return 2; //Goes to Pause Menu
                }
            }
        }
        window.clear(sf::Color(0, 0, 0, 0));
        for (auto const &e : entities) {
            e->move(gravity);
            e->move();
        }
        for (int i = 0; i < 100; i++) {
            rect.setPosition(sf::Vector2f(i * 32, 300 + terrain_array[i]));
            window.draw(rect);
            for (auto const &e : entities) {
                // std::cout << rect.getGlobalBounds().left << " " << rect.getGlobalBounds().top << std::endl;
                if (e->intersects(rect.getGlobalBounds())) {
                    e->goBack();
                }
            }
        }
        for (auto const &e : entities) {
            e->tick();
            e->draw(window);
        }
        ((Player*)entities[0]) -> setView(window, view);

        window.display();
    }
    return (-1);
}

void GroundScene::generateTerrain(int leftindex, int rightindex, int displacement) {
    if ((leftindex + 1) == rightindex)
        return;
    int midindex = ((leftindex + rightindex) / 2);
    int change = ((rand() % 11) - 5) * displacement;
    // std::cout << (rand() % 2) - 1 << std::endl;
    // int change = ((rand() % 3) - 1) * 32;
    // std::cout << change << std::endl;
    terrain_array[midindex] = (terrain_array[leftindex] + terrain_array[rightindex]) / 2 + change;
    // std::cout << terrain_array[midindex] << std::endl;
    displacement = displacement * roughness;
    generateTerrain(leftindex, midindex, displacement);
    generateTerrain(midindex, rightindex, displacement);
}