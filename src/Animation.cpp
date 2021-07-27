#include "Animation.h"

#include <math.h>

Animation::Animation(GraphicManager* pGraphicM, sf::Vector2u imageCount) :
pGraphicM(pGraphicM),
imageCount(imageCount),
texture(NULL),
currentImage(sf::Vector2u(0, 0)) {
    totalTime = 0.0f;
}

Animation::~Animation() {

}

void Animation::initializeTexture(const char* path, ID::ids id) {

    texture = pGraphicM->loadTexture(id, path);

    if (texture == NULL) {
        cout << "ERROR loading texture failed on Animation::initializeTexture." << endl;
        exit(1);
    }

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);

    body.setSize(sf::Vector2f(uvRect.width, uvRect.height));
    body.setOrigin(sf::Vector2f(uvRect.width, uvRect.height) / 2.0f);
    body.setTexture(texture);
}

void Animation::Update(int row, float dt, bool facingLeft, sf::Vector2f position) {
    currentImage.y = row;
    totalTime += dt;

    if (totalTime >= switchTime) {
        totalTime -= switchTime;
        currentImage.x++;

        if (currentImage.x >= imageCount.x) {
            currentImage.x = 0;
        }
    }

    uvRect.top = currentImage.y * uvRect.height;

    if (facingLeft) {
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    } else {
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }

    body.setPosition(position);
    body.setTextureRect(uvRect);
}

void Animation::setimageCount(const sf::Vector2u imageCount) {
    this->imageCount = imageCount;
}