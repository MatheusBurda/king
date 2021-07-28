#pragma once
#include "Entity.h"
class Animation;
class GraphicManager;
#define PATH_FIREBALL_TEXTURE "./assets/Projectiles/Fireball.png"
class Fireball :public Entity
{
public:
	Fireball(GraphicManager* GM);
	~Fireball();
	void update(float dt);
	void render();
	void initializeSprite();


};

