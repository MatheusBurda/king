#pragma once

#include "EntityList.h"
#include "Player.h"
#include "stdafx.h"
#include <map>

class GraphicManager {
private:
    sf::RenderWindow* window;
    sf::View view;
    std::map<ID::ids, sf::Texture*> texturesMap;
    sf::Texture* backgroundTexture;
    sf::RectangleShape backgroundBody;
    EntityList* pEntityList;
    Player* player1;
    Player* player2;

public:
    GraphicManager();
    ~GraphicManager();

    void exec();
    void display();
    void clear();
    void centerView();
    void checkWindowEvents();
    void renderAll();
    void render(sf::RectangleShape* body);

    void setEntityList(EntityList* pList);
    sf::RenderWindow* getWindow() const;

    bool isWindowOpen() const;
    sf::Texture* loadTexture(ID::ids id, const char* path);

    void setPlayers(Player* player1, Player* player2 = NULL);
    void setBackground(const char* path);
    void updateBackground();
};
