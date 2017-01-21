#include "screenpausemenu.hpp"
#include <SFML/Graphics.hpp>

ScreenPauseMenu::ScreenPauseMenu() {}

int ScreenPauseMenu::run(sf::RenderWindow &window) {
    sf::Event Event;
    sf::Font font;
    if(!font.loadFromFile("rsc/font.ttf"))
    {
      return EXIT_FAILURE;
    }
    sf::Text text("Pause Menu - Pretty much", font, 50);


    while (window.isOpen()) {
        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed) {
                return (-1);
            }
            else if (Event.type == sf::Event::KeyPressed) {
                switch (Event.key.code) {
                case sf::Keyboard::Escape:
                    return 1; //Goes back to the game
                }
            }
        }

        window.clear(sf::Color(0, 0, 0, 0));
        window.draw(text);
        window.display();

    }

    return (-1);
}
ScreenPauseMenu::~ScreenPauseMenu()
{

}
