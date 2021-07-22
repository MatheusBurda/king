#pragma once
#include "stdafx.h"
#include"GraphicManager.h"
#include "Id.h"
#include <time.h>

using namespace sf;

class Entity {
protected:
	Vector2f position;
	Vector2f velocity;
	Vector2f hitbox;
	RectangleShape body;
	RenderWindow* window;
	ID::ids id;




public:
	Entity(ID::ids id);
	Entity();
	~Entity();
	void changePosition(sf::Vector2f pos);
	Vector2f getPosition();
	void setVelocity(Vector2f vel);
	Vector2f getVelocity();
	void setHitbox(Vector2f vel);
	Vector2f getHitbox();
	virtual void update(float dt);
	virtual void render();
	void setWindow(RenderWindow *wind) {
		window = wind;
	}
	ID::ids getId();
};