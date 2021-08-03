#include "FieldBuilder.h"
#include "GraphicManager.h"
#include "Menu.h"

int main() {

    FieldBuilder fb;
    Field *field = fb.getField();
    field->exec();
    delete(field);
   /*  GraphicManager GM;
    Menu main(&GM);
    sf::Event event;

    while (GM.isWindowOpen()) {
        while (GM.getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                GM.closeWindow();
            if (event.type == sf::Event::Resized)
                GM.handleWindowResize();
            if (event.type == sf::Event::KeyPressed)
                main.exec();
        }

        GM.clear();
        main.render();
        GM.display();
    } */

    return 0;
}