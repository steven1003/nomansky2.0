#include "screengame.hpp"
#include <iostream>

ScreenGame::ScreenGame() {
    // terrain_array = new int[100];
    roughness = 20;
    std::cout << "This works?: " <<  terrain_array[0] << std::endl;
}

ScreenGame::~ScreenGame() {}

int ScreenGame::run(sf::RenderWindow &window) {
    generateTerrain(0, 99, 20);

    std::cout << "running game" << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << terrain_array[i] << std::endl;
    }
    sf::Event Event;

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(10, 10));
    rect.setFillColor(sf::Color::Cyan);

    while (window.isOpen()) {
        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed) {
                return (-1);
            }
            else if (Event.type == sf::Event::KeyPressed) {
                switch (Event.key.code) {
                case sf::Keyboard::Escape:
                    return 0; //Goes to Pause Menu
                }
            }
        }
        window.clear(sf::Color(0, 0, 0, 0));
        for (int i = 0; i < 100; i++) {
            rect.setPosition(sf::Vector2f(i * 10, terrain_array[i]));
            window.draw(rect);
        }
        window.display();
    }
    return (-1);
}

void ScreenGame::generateTerrain(int leftindex, int rightindex, int displacement) {
    if ((leftindex + 1) == rightindex)
        return;
    int midindex = ((leftindex + rightindex) / 2);
    int change = ((rand() % 11) - 5) * displacement;
    terrain_array[midindex] = (terrain_array[leftindex] + terrain_array[rightindex]) / 2 + change;
    displacement = displacement * roughness;
    generateTerrain(leftindex, midindex, displacement);
    generateTerrain(midindex, rightindex, displacement);
}