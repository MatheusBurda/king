#include"Entity.h"
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
void Entity::update() {

}
void Entity::render() {

}