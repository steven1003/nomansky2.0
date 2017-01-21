#include "spacescene.hpp"
#include <iostream>


SpaceScene::SpaceScene() {
    std::cout << "SOIDIDS" << std::endl;
}

int SpaceScene::run(sf::RenderWindow &window) {
    std::cout << "running game" << std::endl;

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
                    return 2; //Goes to Pause Menu
                }
            }
            else if (Event.type == sf::Event::KeyPressed) {
                switch (Event.key.code) {
                case sf::Keyboard::P:
                    return 1; //Goes to GroundScene Menu
                }
            }
            else if (Event.type == sf::Event::KeyPressed) {
                switch (Event.key.code) {
                case sf::Keyboard::M:
                    return 4; //Goes to StarMap Menu
                }
            }
        }
        window.clear(sf::Color(0, 0, 0, 0));
        window.display();
    }
    return (-1);
}



// if ((leftindex + 1) == rightindex)
//     return;
// int midindex = ((leftindex + rightindex) / 2);
// int change = ((rand() % 11) - 5) * displacement;
// terrain_array[midindex] = (terrain_array[leftindex] + terrain_array[rightindex]) / 2 + change;
// displacement = displacement * roughness;
// generateTerrain(leftindex, midindex, displacement);
// generateTerrain(midindex, rightindex, displacement);



std::vector<SysObject> generateSystem(int leftindex, int rightindex, int numsysobjects) {
    std::vector<SysObject> systemObjects;
    int x = 400;
    int y = 300;
    sf::CircleShape circle;
    circle.setRadius(50);
    Sun sun = Sun(x, y, "sun");
    systemObjects.push_back(sun);
    for (int i = 0; i < numsysobjects - 1; i++)
    {
        int decider = rand() % 10;
        if (decider >= 4)
        {
            int x = rand() % rightindex;
            int y = rand() % leftindex;
            sf::CircleShape circle;
            circle.setRadius(10.0f);
            systemObjects.push_back(Asteroid(x, y, ("asteroid" + (rand() % 999 + 300)), circle));
        }
        else
        {
            int x = rand() % rightindex;
            int y = rand() % leftindex;
            sf::CircleShape circle;
            circle.setRadius(10.0f);
            systemObjects.push_back(Planet(x, y, ("planet" + (rand() % 999 + 300)), circle));
        }

    }
    return systemObjects;
}
