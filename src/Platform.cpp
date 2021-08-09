#include "Platform.h"
#include "Animation.h"
#include "GraphicManager.h"
#include <string.h>

Platform::Platform(ID::ids id, sf::Vector2f pos, sf::Vector2f hit, const char pt[100]) :
Entity(ID::platform, pos, hit) {
    strcpy(path, pt);
    changePosition(pos);
    initializeSprite();
}

Platform::~Platform() {
}

void Platform::update(float dt) {
    sprite->Update(0, dt, false, position);
}

void Platform::render() {
    sprite->render();
}

void Platform::initializeSprite() {
    sprite->initializeTexture(path, sf::Vector2u(1, 1));
}
void Platform::save() {
    if (getShowing()) {
        ofstream file;
        file.open("./assets/Saves/Platform.txt", ios::app);
        if (!file) {
            cout << "ERROR TO OPEN FILE" << endl;
            abort();
        }
        file << getPosition().x << ' ' << getPosition().y <<" "<< path << endl;
        file.close();
    }
}