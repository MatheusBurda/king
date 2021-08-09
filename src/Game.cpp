#include "Game.h"

using namespace SM;

Game::Game() {
    pEventM = EventManager::getInstance();
    pGraphicM = GraphicManager::getInstance();

    pInputM = new InputManager;
    pEventM->setInputManager(pInputM);

    objMainMenuState = new MainMenuState(pInputM, this);
    vectorOfStates.push_back(objMainMenuState);
    currentStateID = stateID::mainMenu;

    objNewGameState = new NewGameState(pInputM, this);
    vectorOfStates.push_back(objNewGameState);

    pLevel = NULL;

    player1 = new Player(true, "Kiwi");
    player2 = NULL;
    pEntityL = new EntityList();

    pColisM = new CollisionManager(pEntityL);

    currentLevel = 1;

    exec();
}

Game::~Game() {
    if (pLevel != NULL)
        delete (pLevel);
    if (player1)
        delete (player1);
    if (player2)
        delete (player2);
    delete (objMainMenuState);
    delete (pInputM);
    delete (pColisM);
    delete (pEntityL);
}

void Game::exec() {
    while (pGraphicM->isWindowOpen()) {
        if (currentStateID == stateID::exit)
            pGraphicM->closeWindow();
            
        pEventM->pollEvents();

        pGraphicM->clear();

        execCurrentState();

        pGraphicM->display();
    }
}
/* if (state == 0) {
            startNewLevel();
        } 
        else if (state == 1 && pLevel != NULL) {
            pLevel->exec();
            pLevel->renderAll();
            if (!pLevel->isLevelRunning()) {
                state = 9;
                delete (pLevel);
                pLevel = NULL;
            }
        } 
        else if (state == 3) {
            pGraphicM->closeWindow();
            return;
        }

        else {
            pGraphicM->centerView(sf::Vector2f(pGraphicM->getWindowSize().x / 2.0f, pGraphicM->getWindowSize().y / 2));
            objMainMenuState->render();
        } */

void Game::startNewLevel() {
    player1->reset();
    pEntityL->addEntity(player1);
    if (pLevel != NULL) {
        delete (pLevel);
        //currentLevel++;
    }

    /* if (currentLevel == 1) {
        LoadBuilder* lb = new LoadBuilder("./assets/Backgrounds/montanha.png", pEntityL, player1, player2, pColisM, sf::Vector2u(0, 0));
        pLevel = static_cast<Level*>(lb);
    } */

    if (currentLevel == 1) {
        FieldBuilder* fb = new FieldBuilder("./assets/Backgrounds/montanha.png", pEntityL, player1, player2, pColisM, sf::Vector2u(0, 0));
        pLevel = static_cast<Level*>(fb);
    }

    /*else if (currentLevel == 1) {
        CastleBuilder* cb = new CastleBuilder("./assets/Backgrounds/bck1.png", pEntityL, player1, player2, pColisM, sf::Vector2u(0, 0));
        pLevel = static_cast<Level*>(cb);
    }*/

    else {
        cerr << "GAME - Couldnt create a new LEVEL" << endl;
        std::exit(35);
    }
}

void Game::save() {
    ifstream Platform;
}
