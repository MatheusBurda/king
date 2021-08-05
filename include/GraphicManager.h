#pragma once

#include "EntityList.h"
#include "Player.h"
#include "stdafx.h"
#include <map>

class GraphicManager {
private:
    sf::RenderWindow* window;
    sf::View view;
    std::map<const char*, sf::Texture*> texturesMap;

    /* Singleton class */
    static GraphicManager* instance;
    GraphicManager();

public:
    ~GraphicManager();

    static GraphicManager* getInstance();

    void render(sf::RectangleShape* body);
    void display();
    void clear();
    sf::RenderWindow* getWindow() const;
    bool isWindowOpen() const;
    void closeWindow();
    void handleWindowResize();
    sf::Vector2u getWindowSize() const;
    void centerView(sf::Vector2f pos);
    sf::Texture* loadTexture(const char* path);
};
