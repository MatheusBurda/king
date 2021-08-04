#pragma once

#include "Level.h"
#include "LevelBuilder.h"

class FieldBuilder : public LevelBuilder {
private:
    Level* field;

public:
    FieldBuilder();
    ~FieldBuilder();
    void buildMap();
    Level* getField() { return field; }
};
