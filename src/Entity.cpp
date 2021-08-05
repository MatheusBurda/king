#include "Entity.h"

#include "Animation.h"

Entity::Entity(ID::ids id, sf::Vector2f pos, sf::Vector2f hit) :
Ent(id, pos) {
    hitbox = hit;
    velocity = sf::Vector2f(0.0f, 0.0f);
    showing = true;
    faceLeft = false;
}

Entity::Entity() {
    hitbox = sf::Vector2f(0.0f, 0.0f);
    velocity = sf::Vector2f(0.0f, 0.0f);
    showing = false;
    faceLeft = false;
}

Entity::~Entity() {
}

void Entity::changePosition(const Vector2f pos) {
    changePos(pos);
}

Vector2f Entity::getPosition() const {
    return getPos();
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
    return getID();
}

void Entity::Move(sf::Vector2f vec) {
    MoveBody(vec);
}