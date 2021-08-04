#include "EventManager.h"
#include "FieldBuilder.h"
#include "GraphicManager.h"
#include "InputManager.h"
#include "MainMenu.h"
#include "MenuControl.h"
#include "PauseMenu.h"

int main() {

    int state = 0;
    /*    0-> jogando
      outro> executar menu
        2-> sair 
    */

    if (state == 0) {
        cout << "RODANDO JOGO" << endl;
        FieldBuilder fb;
        Level* field = fb.getField();
        field->exec();
        delete (field);
        state = 9;
    }

    EventManager* EM = EventManager::getInstance();
    GraphicManager GM;
    InputManager IM;
    PauseMenu main(&GM, &IM);

    EM->setGraphicManager(&GM);
    EM->setInputManager(&IM);

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