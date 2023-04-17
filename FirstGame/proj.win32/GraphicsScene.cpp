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
    sprite->setPosition(0, 0);

    //childs sprite to Layer and sets Z-Order (how close/far from screen perspective)
    this->addChild(sprite, 0);

    return true;
}