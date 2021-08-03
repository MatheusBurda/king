#include "EventManager.h"
#include "FieldBuilder.h"
#include "GraphicManager.h"
#include "InputManager.h"
#include "Menu.h"
#include "MenuControl.h"

int main() {

    EventManager* EM = EventManager::getInstance();
    GraphicManager GM;
    InputManager IM;
    Menu main(&GM);
    MenuControl MM(&IM, &main);

    EM->setGraphicManager(&GM);
    EM->setInputManager(&IM);

    int state = 0;
    /*    0-> jogando
      outro> executar menu
        2-> sair 
    */

    /*  if (state == 0) {
            cout << "RODANDO JOGO" << endl;
            FieldBuilder fb;
            Field* field = fb.getField();
            field->exec();
            delete (field);
            state = 9;
        } */

    while (GM.isWindowOpen()) {
        if (state == 2)
            GM.closeWindow();
        else {
            EM->pollEvents();
            GM.clear();
            main.render();
            GM.display();
        }

    }
        return 0;

}