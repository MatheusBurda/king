#include "Lava.h"

#include "Animation.h"
#include "GraphicManager.h"

Lava::Lava(ID::ids id, sf::Vector2f pos, sf::Vector2f hit) :
    Entity(id, pos, hit) {
    sprite->initializeTexture(LAVA_PATH, sf::Vector2u(3, 1));
}

Lava::~Lava() {
}

void Lava::update(float dt) {
    dt /= 4;
    sprite->Update(0, dt, facingLeft(), position);
}

void Lava::save() {
    if (getShowing()) {
        ofstream file;
        file.open("./assets/Saves/Lava.txt", ios::app);
        if (!file) {
            cout << "ERROR TO OPEN FILE" << endl;
            abort();
        }
        file << getPosition().x << ' ' << getPosition().y<<endl;
        file.close();
    }
}