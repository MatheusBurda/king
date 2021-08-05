#pragma once

#include "Button.h"
#include "MenuControl.h"
#include "Background.h"
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

    int* pState;

public:
    Menu(InputManager* IM, const char* backPath);
    virtual ~Menu();

    virtual void render();
    void exec();
    void selectDown();
    void selectUp();
    void setPState(int* p);float dt;
};
