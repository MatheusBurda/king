#include "SpiderWeb.h"
#include "Animation.h"
#include "GraphicManager.h"

SpiderWeb::SpiderWeb(sf::Vector2f pos) :
Obstacle(pos, sf::Vector2f(SPIDER_WIDTH, SPIDER_HEIGHT),0.5, ID::spiderweb) {
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