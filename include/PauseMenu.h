#pragma once

#include "InputManager.h"
#include "Menu.h"

#define BACKGROUND_PATH "./assets/Backgrounds/MenuBackground.png"

class PauseMenu : public Menu {
public:
    PauseMenu(GraphicManager* GM, InputManager* IM);
    ~PauseMenu();
};
