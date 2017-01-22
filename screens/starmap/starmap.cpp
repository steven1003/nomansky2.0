#include "starmap.hpp"

StarMap::StarMap() {
    // solarSystem.push_back(SolarSystem(sf::Vector2f(500, 500)));
    std::cout << "failed" << std::endl;
}

StarMap::StarMap(SpaceScene* scene) {
    for (int i = 0; i < rand() % 5 + 1; i++) {
        solarSystem.push_back(SolarSystem(sf::Vector2f(1000, 1000)));
        // solarSystem.push_back(SolarSystem(sf::Vector2f(500, 500)));
    }
    this->spaceScene = scene;
}


int StarMap::run(sf::RenderWindow &window) {
    std::cout << "Lauching StarMap" << std::endl;
    sf::Event Event;

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(10, 10));
    rect.setFillColor(sf::Color::Cyan);

    auto view = window.getDefaultView();
    while (window.isOpen()) {
        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed) {
                return (-1);
            }
            else if (Event.type == sf::Event::KeyPressed) {
                switch (Event.key.code) {
                case sf::Keyboard::Escape:
                    return 4; //Goes to Pause Menu
                }
            }
        }
        window.setView(view);
        window.clear(sf::Color(0, 0, 0, 0));
        for (auto &s : solarSystem) {
            s.drawIcon(window);
            if (s.checkIconClick(window)) {
                spaceScene->currentSystem = &s;
                return 2;
            }
        }
        window.display();
    }
    return (-1);
}