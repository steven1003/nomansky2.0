#include "screenmainmenu.hpp"


ScreenMainMenu::ScreenMainMenu() {}

int ScreenMainMenu::run(sf::RenderWindow &window) {
    sf::Event Event;

    while (window.isOpen()) {
        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed) {
                return (-1);
            }
            else if (Event.type == sf::Event::KeyPressed) {
                switch (Event.key.code) {
                case sf::Keyboard::Escape:
                    return 1; //Goes to Pause Menu
                }
            }
        }

        window.clear(sf::Color(255, 0, 0, 0));
        window.display();
    }

    return (-1);
}
ScreenMainMenu::~ScreenMainMenu()
{

}
