#include "Game.h"

Game::Game() {
    pEventM = EventManager::getInstance();
    pGraphicM = GraphicManager::getInstance();

    pInputM = new InputManager;
    pEventM->setInputManager(pInputM);
    objMainMenu = new MainMenu(pInputM);
    
    pLevel = NULL;

    player1 = new Player(true, "Kiwi");
    player2 = NULL;
    pEntityL = new EntityList();
   // pEntityL->addEntity(player1);
    pColisM = new CollisionManager(pEntityL);


    state = 9;
    currentLevel = 1;

    objMainMenu->setPState(&state);

    exec();
}

Game::~Game() {
    if (pLevel != NULL) {
        delete (pLevel);
    }
    if (player1)
        delete(player1);
    delete (objMainMenu);
    delete (pInputM);
    delete(pColisM);
    delete(pEntityL);

}

void Game::exec() {
    /*  0-> Criar nova fase
        1-> Jogando
        3-> Sair 
    outro-> Executar menu*/

    while (pGraphicM->isWindowOpen()) {
        pEventM->pollEvents();
        pGraphicM->clear();
        if (state == 0) {
            startNewLevel();
        } else if (state == 1 && pLevel != NULL) {
            pLevel->exec();
            pLevel->renderAll();
            if (!pLevel->isLevelRunning()) {
                state = 9;
                delete(pLevel);
                pLevel = NULL;
            }
        }
        else if (state == 3) {
            pGraphicM->closeWindow();
            return;
        }

        else {
            pGraphicM->centerView(sf::Vector2f(pGraphicM->getWindowSize().x / 2.0f, pGraphicM->getWindowSize().y / 2));
            objMainMenu->render();
        }
        pGraphicM->display();
    }

}

void Game::startNewLevel() {
    player1->reset();
    pEntityL->addEntity(player1);
    if (pLevel != NULL) {
        delete (pLevel);
        currentLevel++;
    }
    if (currentLevel == 1) {
        FieldBuilder* fb = new FieldBuilder("./assets/Backgrounds/montanha.png", pEntityL, player1, player2, pColisM, sf::Vector2u(0,0));
        pLevel = static_cast<Level*>(fb);
   }else if (currentLevel == 2) {
        pEntityL->addEntity(player1);
        CastleBuilder* cb = new CastleBuilder("./assets/Backgrounds/bck1.png", pEntityL, player1, player2, pColisM, sf::Vector2u(0, 0));
        pLevel = static_cast<Level*>(cb);
    }
    else {
        cerr << "GAME - Couldnt create a new LEVEL" << endl;
        exit(35);
    }
    state = 1;
}
