#include"Player.h"
Player::Player() {
	setHitbox(Vector2f(50, 50));
	body.setSize(hitbox);
	body.setFillColor(Color::Blue);
	body.setPosition(Vector2f(100, 200));
}