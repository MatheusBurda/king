#pragma once
#include "stdafx.h"
#include"GraphicManager.h"
using namespace sf;
class Entity {
protected:
	Vector2f position;
	Vector2f velocity;
	Vector2f hitbox;
	RectangleShape body;
	RenderWindow* window;

public:
	Entity();
	~Entity();
	void setPosition(sf::Vector2f pos);
	Vector2f getPosition();
	void setVelocity(Vector2f vel);
	Vector2f getVelocity();
	void setHitbox(Vector2f vel);
	Vector2f getHitbox();
	virtual void update();
	virtual void render();
	void setWindow(RenderWindow *wind) {
		window = wind;
	}
};