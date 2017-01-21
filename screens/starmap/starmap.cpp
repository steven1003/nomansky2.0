#include "../spacescene/spacescene.hpp"
#include <iostream>
#include "../spacescene/starsystem.hpp"
#include <string>

StarMap::StarMap(){

}
StarMap::~StarMap() {}
std::vector<StarSystem> starMap;
int StarMap::run(sf::RenderWindow &window) {
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
                case sf::Keyboard::S:
                    return 3; //Goes to SpaceScene Menu
                }
            }
            // else if(/*User selects star system*/)
            // {
            //   if(/* we have data stored at location, call it*/)
            //   {
            //       //And now we enter the system
            //   }
            //   else
            //   {
            //     StarSystem starSystem = StarSystem::generateSystem;
            //     starMap.push_back(starSystem);
            //
            //     //And now we enter the system
            //   }
            // }
        }
        window.clear(sf::Color(0, 0, 0, 0));
        draw();
        window.display();
    }
    return (-1);
}
