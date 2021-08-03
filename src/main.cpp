#include "EventManager.h"
#include "FieldBuilder.h"
#include "GraphicManager.h"
#include "InputManager.h"
#include "Menu.h"

int main() {

    /* FieldBuilder fb;
    Field *field = fb.getField();
    field->exec();
    delete(field); */
    EventManager* EM = EventManager::getInstance();
    GraphicManager GM;
    InputManager IM;
    Menu main(&GM);

    EM->setGraphicManager(&GM);
    EM->setInputManager(&IM);

    while (GM.isWindowOpen()) {
        EM->pollEvents();

        GM.clear();
        main.render();
        GM.display();
    }

    return 0;
}