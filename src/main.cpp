#pragma once
#include "FieldBuilder.h"
int main() {

    FieldBuilder fb;
    Field *field = fb.getField();
    field->exec();
    delete(field);



    return 0;
}