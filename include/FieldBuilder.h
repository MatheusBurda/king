#pragma once
#include "Builder.h"
#include"Field.h"
class FieldBuilder :public Builder
{
private:
    Field *field;
public:
    FieldBuilder();
    ~FieldBuilder();
    void buildPlatform(sf::Vector2f pos);
    void buildPlayer1(sf::Vector2f pos);
    void buildEnemy(sf::Vector2f pos);
    void buildWall(sf::Vector2f pos);
    void buildMap();
    Field* getField() { return field; }
};

