#include "Wall.h"
#include "Animation.h"
#include "GraphicManager.h"

Wall::Wall(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, const char* path) :
Entity(id, pos, hit) {
    strcpy(this->path, path);
    sprite->initializeTexture(path, sf::Vector2u(1, 1));
}

Wall::~Wall() {
}

void Wall::update(float dt) {
    sprite->Update(0, dt, facingLeft(), position);
}

void Wall::render() {
    sprite->render();
}
void Wall::save() {
    if (getShowing()) {
        ofstream file;
        file.open("./assets/Saves/Wall.txt", ios::app);
        if (!file) {
            cout << "ERROR TO OPEN FILE" << endl;
            abort();
        }
        file << getPosition().x << ' ' << getPosition().y << ' ' << path <<' ' <<facingLeft()<< endl;
        file.close();
    }
}