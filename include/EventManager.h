#pragma once

#include "GraphicManager.h"
#include "InputManager.h"
#include "stdafx.h"

class EventManager {
private:
    GraphicManager* pGraphicM;
    InputManager* pInputM;
    sf::RenderWindow* pWindow;


public:
    EventManager(GraphicManager* pGM = NULL, InputManager *pIM = NULL);
    ~EventManager();

    void setGraphicManager(GraphicManager* pGM);
    void setInputManager(InputManager* pIM);

    void pollEvents();
};
