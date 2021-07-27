#include "Entity.h"

#include "Animation.h"
#include "GraphicManager.h"

Entity::Entity(ID::ids id, GraphicManager* GM) :
sprite(new Animation(GM)) {
    showing = true;
    this->id = id;
}

Entity::Entity() {
    this->id = ID::empty;
}

Entity::~Entity() {
    delete (sprite);
}

void Entity::changePosition(const Vector2f pos) {
    position = pos;
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
void Entity::Move(sf::Vector2f vec) {
    position = sf::Vector2f(position.x + vec.x, position.y + vec.y);
}