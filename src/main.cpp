#include "BossBuilder.h"
#include "CastleBuilder.h"
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
        FieldBuilder fb;
        Level* field = fb.getField();
        field->exec();
        delete (field);
        /* CastleBuilder cb;
        Level* castle = cb.getCastle();
        castle->exec();
        delete(castle); */
        /* BossBuilder bb;
        Level* boss = bb.getBoss();
        boss->exec();
        delete(boss);
        state = 9; */
    }

    /* EventManager* EM = EventManager::getInstance();
    GraphicManager* GM = GraphicManager::getInstance();
    InputManager IM;
    MainMenu main(&IM);

    EM->setInputManager(&IM);

    cout << "Menu rodando" << endl;

    while (GM->isWindowOpen()) {
        if (state == 2)
            GM->closeWindow();
        else {
            EM->pollEvents();
            GM->clear();
            GM->centerView(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2));
            main.render();
            GM->display();
        }
    } */
    return 0;
}