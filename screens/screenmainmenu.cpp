#include "screenmainmenu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

ScreenMainMenu::ScreenMainMenu() {}

int ScreenMainMenu::run(sf::RenderWindow &window) {
    sf::Event Event;
    sf::Font font;
    if(!font.loadFromFile("rsc/font.ttf"))
    {
      return EXIT_FAILURE;
    }
    sf::Text text("No Mans Sky - Pretty much", font, 50);
    text.setPosition(180,100);

    sf::Text option1("New Game", font, 25);
    option1.setPosition(325, 175);

    sf::Text option2("Continue", font, 25);
    option2.setPosition(325, 200);

    sf::Text option3("Options", font, 25);
    option3.setPosition(325, 225);

    sf::Text option4("Exit", font, 25);
    option4.setPosition(325, 250);

    sf::FloatRect op1 = option1.getGlobalBounds();
    sf::FloatRect op2 = option2.getGlobalBounds();
    sf::FloatRect op3 = option3.getGlobalBounds();
    sf::FloatRect op4 = option4.getGlobalBounds();

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
    if(op1.contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))
    {
      if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
      {
        //Will Launch New Game When Implemented
        std::cout << "Button 1 Works!" << std::endl;
      }
    }

    if(op2.contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))
    {
      if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
      {
        //Will Launch New Game When Implemented
        std::cout << "Button 2 Works!" << std::endl;
      }
    }

    if(op3.contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))
    {
      if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
      {
        //Will Launch New Game When Implemented
        std::cout << "Button 3 Works!" << std::endl;
      }
    }

    if(op4.contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))
    {
      if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
      {
        //Will Launch New Game When Implemented
        std::cout << "Button 4 Works!" << std::endl;
      }
    }
        window.clear(sf::Color(0, 0, 0, 0));
        window.draw(text);
        window.draw(option1);
        window.draw(option2);
        window.draw(option3);
        window.draw(option4);

        window.display();

    }

    return (-1);
}
ScreenMainMenu::~ScreenMainMenu()
{

}
