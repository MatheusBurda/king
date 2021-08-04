#include "EventManager.h"
#include "FieldBuilder.h"
#include "CastleBuilder.h"
#include "BossBuilder.h"
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
        CastleBuilder cb;
        Level* castle = cb.getCastle();
        castle->exec();
        delete(castle);
        BossBuilder bb;
        Level* boss = bb.getBoss();
        boss->exec();
        delete(boss);
        state = 9;
    }

    /*EventManager* EM = EventManager::getInstance();
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
    }*/
    return 0;
}