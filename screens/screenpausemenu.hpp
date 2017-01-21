/* 
	Load pause menu screen class.
	Someone can work on this.
*/

#ifndef SCREEN_PAUSE_MENU_HPP
#define SCREEN_PAUSE_MENU_HPP

#include <iostream>
#include "cscreen.hpp"


//manages the pause menu screen
class ScreenPauseMenu : public CScreen
{
public:
    ScreenPauseMenu();
    virtual int run(sf::RenderWindow &window);
    virtual ~ScreenPauseMenu();
};

#endif
