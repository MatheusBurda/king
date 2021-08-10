#include "Button.h"

#include "Animation.h"
#include <math.h>
#include <string.h>

Button::Button(sf::Vector2f pos) :
Ent(ID::button, pos),
hover(false) {
    initializeSprite();
    pGraphicManager = GraphicManager::getInstance();
}

Button::~Button() {
}

void Button::setMessage(const char* m) {
    text.setString(m);

    text.setFont(*pGraphicManager->getFont());
    text.setCharacterSize(TEXT_SIZE);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(position);
    text.setFillColor(sf::Color::White);
}

void Button::initializeSprite() {
    sprite->initializeTexture(BUTTON_PATH, sf::Vector2u(1, 2));
}

void Button::render() {
    if (hover)
        sprite->Update(0, 0, false, position);
    else
        sprite->Update(1, 0, false, position);

    sprite->render();

    pGraphicManager->render(&text);
}
