#include "Entity.h"

Entity::Entity(ID::ids id) {
    this->id = id;
    setHitbox(Vector2f(50, 50));
    body.setSize(hitbox);
    body.setFillColor(Color::Blue);
    body.setPosition(Vector2f(200, 500));
}

Entity::Entity() {
    this->id = ID::empty;
    setHitbox(Vector2f(50, 50));
    body.setSize(hitbox);
    body.setFillColor(Color::Red);
    body.setPosition(Vector2f(200, 500));
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

void Entity::update() {
}

void Entity::render() {
    window->draw(body);
}
