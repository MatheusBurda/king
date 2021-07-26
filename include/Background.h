#pragma once
#include "Entity.h"
class Background : public Entity
{
	sf::Texture texture;
	sf::RectangleShape background;
	sf::RenderWindow* window;
public:
	Background(sf::RenderWindow* wind=NULL) : Entity(), background(sf::Vector2f(WIDTH, HEIGHT)) {
		if (!texture.loadFromFile("./assets/Backgrounds/montanha.png")) {
			exit(9);
		}
		window = wind;
		background.setTexture(&texture);
	}
	~Background(){}


};

