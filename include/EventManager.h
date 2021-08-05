#pragma once

#include "GraphicManager.h"
#include "InputManager.h"
#include "stdafx.h"

class EventManager {
private:
    GraphicManager* pGraphicM;
    InputManager* pInputM;
    sf::RenderWindow* pWindow;

    /* Singleton design pattern */
    static EventManager* instance;
    EventManager();

public:
    ~EventManager();

    static EventManager* getInstance();

    void setGraphicManager();
    void setInputManager(InputManager* pIM);

    void pollEvents();
};

