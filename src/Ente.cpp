#include "Ente.h"
#include "Animation.h"
#include "GraphicManager.h"

Ente::Ente(ID::ids id, GraphicManager* GM, sf::Vector2f pos) :
sprite(new Animation(GM)),
id(id),
position(pos) { }

Ente::Ente() {
    this->id = ID::empty;
    sprite = NULL;
}

Ente::~Ente() {
    delete (sprite);
}

void Ente::changePos(const sf::Vector2f pos) {
    position = pos;
}

Vector2f Ente::getPos() const {
    return position;
}

ID::ids Ente::getID() const {
    return id;
}

void Ente::MoveBody(const sf::Vector2f vec) {
    position = sf::Vector2f(position.x + vec.x, position.y + vec.y);
}
