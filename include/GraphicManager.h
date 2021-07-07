#pragma once 

#include "stdafx.h"

class GraphicManager
{
private:
    sf::RenderWindow *window;

public:
    GraphicManager();
    ~GraphicManager();
    sf::RenderWindow* getWindow();
    void display();
    void clear();

};

