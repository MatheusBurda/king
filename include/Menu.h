#pragma once

#include "Button.h"
#include <vector>

class GraphicManager;

class Menu {
protected:
    std::vector<Button*> vectorOfButtons;
    std::vector<Button*>::iterator it;
    int selected;
    int min;
    int max;

public:
    Menu(GraphicManager* GM);
    virtual ~Menu();

    virtual void render();
    int exec();
    void selectDown();
    void selectUp();
};
