#include "Lava.h"

#include "Animation.h"
#include "GraphicManager.h"

Lava::Lava(ID::ids id, sf::Vector2f pos, sf::Vector2f hit) :
    Entity(id, pos, hit) {
    sprite->initializeTexture(LAVA_PATH, sf::Vector2u(1, 1));
}

Lava::~Lava() {
}

void Lava::update(float dt) {
    sprite->Update(0, dt, facingLeft(), position);
}

void Lava::render() {
    sprite->render();
}
