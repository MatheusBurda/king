#pragma once

#include "stdafx.h"
#include "Observer.h"   

class Menu;
class InputManager;

class MenuControl : public Observer {
private:
    Menu* pMenu;

public:
    MenuControl(InputManager* pIM, Menu* pM = NULL);
    ~MenuControl();

    void notify();
    void addMenu(Menu* p);
};