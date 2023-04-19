#include "GameLoop.h"

USING_NS_CC;

Scene* GameLoop::createScene()
{
    auto scene = Scene::create();
    auto layer = GameLoop::create();
    scene->addChild(layer);
    return scene;
}

bool GameLoop::init()
{
    if (!Layer::init())
    {
        return false;
    }

    sprite = Sprite::create("Veyron.png");
    sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
    this->addChild(sprite, 0);

    //calls to update every frame, higher values in (5) are given lower priority
    this->scheduleUpdate();
    return true;
}

//calls every frame moves sprite to left
void GameLoop::update(float delta) {
    auto position = sprite->getPosition();
    position.x -= 250 * delta;
    //if sprite position becomes less than 0, moves sprite to max X value (right side of screen) and starts starts animation over with half of car visible to begin with
    if (position.x < 0 - (sprite->getBoundingBox().size.width / 2))
        position.x = this->getBoundingBox().getMaxX() + sprite->getBoundingBox().size.width / 2;
    //sets new position every frame
    sprite->setPosition(position);
}