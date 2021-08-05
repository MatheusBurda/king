#pragma once

#include "InputManager.h"
#include "Menu.h"

#define BACKGROUND_MAIN_MENU "./assets/Backgrounds/MainMenuBackground.png"

class MainMenu : public Menu {
private:
public:
    MainMenu(InputManager* IM);
    ~MainMenu();
};
