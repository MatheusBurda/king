#include "Ent.h"

#include "Animation.h"

Ent::Ent(ID::ids id, sf::Vector2f pos) :
sprite(new Animation()),
id(id),
position(pos) { }

Ent::Ent() {
    this->id = ID::empty;
    sprite = NULL;
}

Ent::~Ent() {
    delete (sprite);
}

void Ent::changePos(const sf::Vector2f pos) {
    position = pos;
}

Vector2f Ent::getPos() const {
    return position;
}

ID::ids Ent::getID() const {
    return id;
}

void Ent::MoveBody(const sf::Vector2f vec) {
    position = sf::Vector2f(position.x + vec.x, position.y + vec.y);
}

void Ent::render() {
    sprite->render();
}
