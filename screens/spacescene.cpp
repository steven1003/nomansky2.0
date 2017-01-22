#include "spacescene.hpp"

SpaceScene::SpaceScene() {
}

SpaceScene::SpaceScene(GroundScene* groundScene) {
    this->groundScene = groundScene;
}
int SpaceScene::run(sf::RenderWindow &window) {
    std::cout << "Lauching SpaceScene" << std::endl;
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
                    return 3;
                    break;
                }
            }
        }
        window.clear(sf::Color(0, 0, 0, 0));
        // window.draw(rect);
        if(currentSystem->tick(groundScene) == 5) {
            return 1;
        }
        currentSystem->draw(window);
        window.display();
    }
    return (-1);
}
