#include "LoadBuilder.h"
LoadBuilder::LoadBuilder(const char* path, Player* p1, Player* p2, sf::Vector2u levelSize) :
	Level(path,p1, p2, levelSize){
    loadMap();
}
LoadBuilder::~LoadBuilder() {
    saveLvl();
    _list->removeEntity(player1);
    _list->deleteAll();
}
void LoadBuilder::loadMap() {
    ifstream Level("./assets/Saves/Level.txt", ios::in);
    if (!Level) {
        cout << "Cant Open" << endl;
        exit(100);
    }
    Level >> numlvl;

    if (numlvl == -1) {
        cout << "No level saved" << endl;
        exit(99);
    }
    
    sf::Vector2f pos;
    bool facingLeft;
    bool showing;
    sf::Vector2f posProj;
    sf::Vector2f velProj;
    char path[100];
    ifstream Player1(("./assets/Saves/Player1.txt"), ios::in);
    if (!Player1) {
        cout << "Cant Open" << endl;
        exit(100);
    }
    Player1 >> pos.x >> pos.y >> facingLeft;
    setPlayer1(sf::Vector2f(pos.x, pos.y));
    Player1.close();

    ifstream Platform(("./assets/Saves/Platform.txt"), ios::in);
    if (!Platform) {
        cout << "Cant Open" << endl;
        exit(100);
    }
    while (Platform >> pos.x >> pos.y >> path)
        buildPlatform(sf::Vector2f(pos.x, pos.y), path);
    Platform.close();

    ifstream Wall(("./assets/Saves/Wall.txt"), ios::in);
    if (!Wall) {
        cout << "Cant Open" << endl;
        exit(100);
    }
    while (Wall >> pos.x >> pos.y >> path>>facingLeft)
        buildWall(sf::Vector2f(pos.x, pos.y), path, facingLeft);
    Wall.close();

    ifstream Lava(("./assets/Saves/Lava.txt"), ios::in);
    if (!Lava) {
        cout << "Cant Open" << endl;
        exit(100);
    }
    while (Lava >> pos.x >> pos.y)
        buildLava(sf::Vector2f(pos.x, pos.y));
    Lava.close();
    ifstream SpiderWeb(("./assets/Saves/SpiderWeb.txt"), ios::in);
    if (!SpiderWeb) {
        cout << "Cant Open" << endl;
        exit(100);
    }
    while (SpiderWeb >> pos.x >> pos.y)
        buildWeb(sf::Vector2f(pos.x, pos.y));
    SpiderWeb.close();

    ifstream Archer("./assets/Saves/Archer.txt");
    if (!Archer) {
        cout << "Cant Open" << endl;
        return;
    }
    while (Archer >> pos.x >> pos.y >> posProj.x>>posProj.y>>velProj.x>>velProj.y>>showing)
        buildArcher(sf::Vector2f(pos.x, pos.y), sf::Vector2f(posProj.x, posProj.y), sf::Vector2f(velProj.x, velProj.y), showing);
    Archer.close();

    ifstream Wizard("./assets/Saves/Wizard.txt");
    if (!Wizard) {
        cout << "Cant Open" << endl;
        return;
    }
    while (Wizard >> pos.x >> pos.y >> posProj.x >> posProj.y >> velProj.x >> velProj.y >> showing)
        buildWizard(sf::Vector2f(pos.x, pos.y), sf::Vector2f(posProj.x, posProj.y), sf::Vector2f(velProj.x, velProj.y), showing);
    Wizard.close();

}
