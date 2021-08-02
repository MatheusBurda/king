#include "Field.h"

Field::Field() :
Level() {
    graphicM.setEntityList(&_list);
    graphicM.setBackground("./assets/Backgrounds/montanha.png"); 
}

Field::~Field() {
    _list.deleteAll();

}
