#include "Level.h"

Level::Level(const char* path, Player* p1, Player* p2, sf::Vector2u levelSize) :
graphicM(GraphicManager::getInstance()),
_list(new EntityList()),
player1(p1),
player2(p2),
colis(_list),
levelMapSize(levelSize),
back(sf::Vector2f(float(graphicM->getWindowSize().x / 2), float(graphicM->getWindowSize().y / 2)), path),
reachEnd(1000) {
    strcpy(this->path, path);
    pEventManager = EventManager::getInstance();
    levelRunning = 1;

    if (player1) {
        _list->addEntity(player1);
    }
    if (player2) {
        _list->addEntity(player2);
    }
}

Level::~Level() {
    if (player1) {
        _list->removeEntity(player1);
        player1 = NULL;
    }
    if (player2) {
        _list->removeEntity(player2);
        player2 = NULL;
    }
    delete (_list);
}

void Level::exec(float dt) {
    if (player1->getShowing()) {
        if (player2 && !player2->getShowing())
            levelRunning = 0;
        /* Update all entities */
        _list->updateAll(dt);
        /* Collide all entities */
        colis.toCollide();
        //Condition to end level because reached the end
        if (player1->getPosition().x >= reachEnd) {
            if (player2) {
                if (player2->getPosition().x >= reachEnd) {
                    levelRunning = -1;
                } else
                    levelRunning = 1;
            } else
                levelRunning = -1;
        }
    } else
        levelRunning = 0;
}

/* Run all graphic events */
void Level::renderAll() {
    centerView();

    back.render();

    for (int i = 0; i < _list->getSize(); i++) {
        if ((*_list)[i]->getShowing())
            (*_list)[i]->render();
    }
}

void Level::centerView() {
    sf::Vector2f viewPosition, viewSize;

    if (player2 == NULL) {
        viewPosition = player1->getPosition();
    } else {
        viewPosition = (player1->getPosition() + player2->getPosition()) / 2.0f;
    }

    graphicM->centerView(viewPosition);
    back.changePos(viewPosition);
}

void Level::saveLvl() {
    ofstream level;
    level.open("./assets/Saves/Level.txt", ios::trunc);
    if (!level) {
        cout << "ERROR TO OPEN FILE" << endl;
        abort();
    }
    level << path << ' ' << reachEnd << endl;
    level.close();
    ofstream clean;
    clean.open("./assets/Saves/Player1.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/Wizard.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/Archer.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/Wall.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/Player2.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/Platform.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/SpiderWeb.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/Lava.txt", ios::trunc);
    clean.close();
    clean.open("./assets/Saves/Boss.txt", ios::trunc);
    clean.close();
    for (int i = 0; i < _list->getSize(); i++) {
        (*_list)[i]->save();
    }
}

int Level::getNumLevel() {
    if (!strcmp(path, PATH_BACKGROUND_FIELD))
        return 1;
    else if (!strcmp(path, PATH_BACKGROUND_CASTLE))
        return 2;
    return 0;
}