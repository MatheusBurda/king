#include "Fireball.h"
#include "Animation.h";
#include "GraphicManager.h"
Fireball::Fireball(GraphicManager* GM) : Entity(ID::fireball, GM){
	setHitbox(sf::Vector2f(FIREBALL_WIDTH, FIREBALL_HEIGHT));
	initializeSprite();
	setShowing(false);
	changePosition(sf::Vector2f(0.0f, 0.0f));
}

Fireball::~Fireball()
{

}
void Fireball::update(float dt) {
	if (getShowing()) {
		velocity = Vector2f(velocity.x, velocity.y + GRAVITY * dt);
		changePosition(Vector2f(velocity.x * dt + position.x, velocity.y * dt + position.y));
		sprite->Update(0, dt, facingLeft(), position);
	}
}
void Fireball::render() {
	sprite->render();
}
void Fireball::initializeSprite() {
	sprite->initializeTexture(PATH_FIREBALL_TEXTURE, id, sf::Vector2u(3, 1));
}