#include "Entity.h"

#include "GraphicManager.h"

Entity::Entity(ID::ids id, GraphicManager* GM) {
    showing = true;
    this->id = id;
    pGraphicManager = GM;
}

Entity::Entity() {

    this->id = ID::empty;
    pGraphicManager = NULL;
}

Entity::~Entity() {
}

void Entity::changePosition(const Vector2f pos) {
    position = pos;
    body.setPosition(position);
}

Vector2f Entity::getPosition() const {
    return position;
}

void Entity::setVelocity(const Vector2f vel) {
    velocity = vel;
}

Vector2f Entity::getVelocity() const {
    return velocity;
}

void Entity::setHitbox(const Vector2f hit) {
    hitbox = hit;
}

Vector2f Entity::getHitbox() const {
    return hitbox;
}

ID::ids Entity::getId() const {
    return id;
}
void Entity:: Move(sf::Vector2f vec) {
    body.move(vec);
    position = sf::Vector2f(position.x + vec.x, position.y + vec.y);
}