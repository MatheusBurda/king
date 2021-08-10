#include "SpiderWeb.h"
#include "Animation.h"
#include "GraphicManager.h"

SpiderWeb::SpiderWeb(ID::ids id, sf::Vector2f pos, sf::Vector2f hit) :
    Entity(id, pos, hit) {
    sprite->initializeTexture(SPIDER_PATH, sf::Vector2u(1, 1));
}

SpiderWeb::~SpiderWeb() {
}

void SpiderWeb::update(float dt) {
    sprite->Update(0, dt, facingLeft(), position);
}

void SpiderWeb::save() {
    if (getShowing()) {
        ofstream file;
        file.open("./assets/Saves/SpiderWeb.txt", ios::app);
        if (!file) {
            cout << "ERROR TO OPEN FILE" << endl;
            abort();
        }
        file << getPosition().x << ' ' << getPosition().y << endl;
        file.close();
    }
}