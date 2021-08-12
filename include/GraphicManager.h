#pragma once

#include "EntityList.h"
#include "Player.h"
#include "stdafx.h"
#include <map>

#define FONT_PATH "./assets/Fonts/minecraft-ten.ttf"

class GraphicManager {
private:
    sf::RenderWindow* window;
    sf::View view;
    std::map<const char*, sf::Texture*> texturesMap;
    sf::Font* font;

    /* Singleton class */
    static GraphicManager* instance;
    GraphicManager();

public:
    ~GraphicManager();

    static GraphicManager* getInstance();

    void render(sf::RectangleShape* body);
    void render(sf::Text *text);
    void display();
    void clear();
    sf::RenderWindow* getWindow() const;
    bool isWindowOpen() const;
    void closeWindow();
    void handleWindowResize();
    sf::Vector2u getWindowSize() const;
    void centerView(sf::Vector2f pos);
    sf::Texture* loadTexture(const char* path);
    sf::Font* getFont();
    void deleteAllTextures();
};