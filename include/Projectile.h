#pragma once
#include "Entity.h"
class Projectile : public Entity{
protected:
	float timeActive;
	int Damage;
public:
	Projectile(sf::Vector2f pos, sf::Vector2f hit, int damage, int timeActive, ID::ids id);
	virtual ~Projectile(){ }
	void rotate(){ }
	int getDamage()const { return Damage; }
};

