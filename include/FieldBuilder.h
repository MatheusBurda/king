#pragma once

#include "Builder.h"
#include "Field.h"

class FieldBuilder : public Builder {
private:
    Field* field;

public:
    FieldBuilder();
    ~FieldBuilder();
    void buildMap();
    Field* getField() { return field; }
};
