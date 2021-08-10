#pragma once

#include "Ent.h"
#include "GraphicManager.h"
#include "stdafx.h"

#define BUTTON_PATH "./assets/Backgrounds/Button.png"
#define TEXT_SIZE 24

class Button : public Ent {
private:
    bool hover;
    GraphicManager* pGraphicManager;
    sf::Text text;
    sf::Font font;

public:
    Button(sf::Vector2f pos);
    Button();
    virtual ~Button();

    void initializeSprite();
    void render();
    void update(float dt) { }

    void setMessage(const char* m);
    void select(const bool isSelected) { hover = isSelected; }
};
