#pragma once

#include "Button.h"

class GraphicManager;

class Menu {
private:
    Button bt1;
    Button bt2;
    Button bt3;
    int selected;
    int min;
    int max;

public:
    Menu(GraphicManager* GM);
    ~Menu();

    void render();
    void exec();
};
