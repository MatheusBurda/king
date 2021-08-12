#include "Wall.h"
#include "Animation.h"
#include "GraphicManager.h"

#include "string.h"

Wall::Wall(sf::Vector2f pos, const char* path) :
Entity(ID::wall, pos, sf::Vector2f(WALL_WIDTH, WALL_HEIGHT)) {
    strcpy(this->path, path);
    sprite->initializeTexture(path, sf::Vector2u(1, 1));
}

Wall::~Wall() {
}

void Wall::update(float dt) {
    sprite->Update(0, dt, facingLeft(), position);
}

void Wall::save() {
    if (getShowing()) {
        ofstream file;
        file.open("./assets/Saves/Wall.txt", ios::app);
        if (!file) {
            cout << "ERROR TO OPEN FILE" << endl;
            abort();
        }
        file << getPosition().x << ' ' << getPosition().y << ' ' << facingLeft() << ' ' << path << endl;
        file.close();
    }
}