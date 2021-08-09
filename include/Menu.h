#pragma once

#include "Background.h"
#include "Button.h"
#include "MenuControl.h"
#include <vector>

class GraphicManager;

class Menu {
protected:
    std::vector<Button*> vectorOfButtons;
    std::vector<Button*>::iterator it;
    int selected;
    int min;
    int max;
    MenuControl control;
    Background back;
    bool active;

public:
    Menu(InputManager* IM, const char* backPath);
    virtual ~Menu();

    virtual void exec() = 0;
    void updateView();
    void selectDown();
    void selectUp();
};
