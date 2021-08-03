#pragma once

#include "LevelBuilder.h"
#include "Level.h"

class FieldBuilder : public LevelBuilder {
private:
    Level* field;

public:
    FieldBuilder();
    ~FieldBuilder();
    void buildMap();
    Level* getField() { return field; }

};
