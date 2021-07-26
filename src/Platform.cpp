#include "Platform.h"
#include "GraphicManager.h"

Platform::Platform(sf::Vector2f pos, GraphicManager* GM) :
Entity(ID::plataform, GM) {
    changePosition(pos);

    sf::Texture* tex;
    tex = pGraphicManager->loadTexture(ID::plataform, PLATFORM_PATH);

    setHitbox(sf::Vector2f(200.0f, 50.0f));
    body.setOrigin(hitbox / 2.0f);
    body.setSize(hitbox);
    body.setTexture(tex);
}

Platform::~Platform() {
}

void Platform::update(float dt) {
    body.setPosition(position);
}

void Platform::render() {
    pGraphicManager->getWindow()->draw(body);
}
