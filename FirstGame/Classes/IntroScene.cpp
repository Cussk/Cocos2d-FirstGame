#include "IntroScene.h"

USING_NS_CC;

Scene* IntroScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    auto layer = IntroScene::create();

    scene->addChild(layer);

    return scene;
}

//initiates HelloWorld "Layer", a node with touch functionality
bool IntroScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    //creates label that is a child of the Layer and anchors to a point in the container
    auto label = Label::createWithSystemFont("IntroScene", "Arial", 96);
    label->setAnchorPoint(cocos2d::Vec2(0.0, 0.0));
    this->addChild(label, 1);

    return true;
}