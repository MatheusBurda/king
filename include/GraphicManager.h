#pragma once

#include "EntityList.h"
#include "stdafx.h"
#include <map>

class GraphicManager {
private:
    sf::RenderWindow* window;
    sf::View view;
    EntityList* pEntityList;
    std::map<ID::ids, sf::Texture*> texturesMap;

public:
    GraphicManager();
    ~GraphicManager();

    void setEntityList(EntityList* pList);
    sf::RenderWindow* getWindow() const;
    void display();
    void clear();
    bool isWindowOpen() const;
    void checkWindowEvents();
    void centerView(sf::Vector2f pos);
    sf::Texture* loadTexture(ID::ids id, const char* path);
};
