#include "Entity.h"

Entity::Entity(ID::ids id) {
    this->id = id;
}

Entity::Entity() {
}

Entity::~Entity() {
}

void Entity::setPosition(Vector2f pos) {
    position = pos;
}

Vector2f Entity::getPosition() {
    return position;
}

void Entity::setVelocity(Vector2f vel) {
    velocity = vel;
}

Vector2f Entity::getVelocity() {
    return velocity;
}

void Entity::setHitbox(Vector2f hit) {
    hitbox = hit;
}

Vector2f Entity::getHitbox() {
    return hitbox;
}

ID::ids Entity::getId() {
    return id;
}

void Entity::update() { }
void Entity::render() { }
