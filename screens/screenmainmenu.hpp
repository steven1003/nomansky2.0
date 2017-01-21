/* 
	Load menu and pause menu screen class.
	Someone can work on this.
*/

#ifndef SCREEN_MAIN_MENU_HPP
#define SCREEN_MAIN_MENU_HPP

#include <iostream>
#include "cscreen.hpp"

#include "screengame.hpp"

//manages the main menu screen
class ScreenMainMenu : public CScreen
{
public:
    ScreenMainMenu();
    virtual int run(sf::RenderWindow &window);
    virtual ~ScreenMainMenu();
};

#endif
