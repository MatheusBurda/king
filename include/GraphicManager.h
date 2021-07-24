#pragma once

#include "EntityList.h"
#include "stdafx.h"

class GraphicManager {
private:
    sf::RenderWindow* window;
    EntityList* pEntityList;

public:
    GraphicManager();
    ~GraphicManager();

    void setEntityList(EntityList* pList);
    sf::RenderWindow* getWindow();
    void display();
    void clear();
    bool isWindowOpen();
};
