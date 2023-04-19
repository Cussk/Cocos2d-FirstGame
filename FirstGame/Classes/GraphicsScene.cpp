#include "GraphicsScene.h"

USING_NS_CC;

//Creates Scene
Scene* GraphicsScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GraphicsScene::create();
    scene->addChild(layer);

    return scene;
}

//initiates Layer/Scene/Node
bool GraphicsScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    //creates sprite using defined image file at designated postion
    auto sprite = Sprite::create("decepticon.png");
    auto sprite2 = Sprite::create("autobot.png");

    //changes anchor point of sprite from center (default) to bottom left corner
    sprite->setAnchorPoint(Vec2(0, 0));
    sprite2->setAnchorPoint(Vec2(0, 0));

    //child sprite2 to sprite, making sprite2's positioning relative to its parent
    sprite->addChild(sprite2);

    sprite->setPosition(100, 100);
    //0,0 within the container of sprite
    sprite2->setPosition(0, 0);

    //childs sprite to Layer and sets Z-Order (how close/far from screen perspective)
    this->addChild(sprite, 0);

    return true;
}