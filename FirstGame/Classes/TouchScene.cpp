#include "TouchScene.h"

USING_NS_CC;

//creates scene
Scene* TouchScene::createScene()
{
    auto scene = Scene::create();
    auto layer = TouchScene::create();
    scene->addChild(layer);

    return scene;
}

//initializes layer class
bool TouchScene::init()
{
    //if no layer return false
    if (!Layer::init())
    {
        return false;
    }

    //create label with font and text
    labelTouchInfo = Label::createWithSystemFont("Touch or click somewhere to begin", "Arial", 30);

    //position label
    labelTouchInfo->setPosition(Vec2(
        Director::getInstance()->getVisibleSize().width / 2,
        Director::getInstance()->getVisibleSize().height / 2));

    //Create Event listener for single touch events
    auto touchListener = EventListenerTouchOneByOne::create();

    //maps events to functions to be called when event fires
    touchListener->onTouchBegan = CC_CALLBACK_2(TouchScene::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(TouchScene::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(TouchScene::onTouchMoved, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(TouchScene::onTouchCancelled, this);

    //dispatches event with high priority, calling as often as possible
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    //child label to layer
    this->addChild(labelTouchInfo);
    return true;
}

//Function called with single click/touch
bool TouchScene::onTouchBegan(Touch* touch, Event* event)
{
    //sets label to position of touch/click and changes string to below
    labelTouchInfo->setPosition(touch->getLocation());
    labelTouchInfo->setString("You Touched Here");
    return true;
}

//Function called on release of touch/click
void TouchScene::onTouchEnded(Touch* touch, Event* event)
{
    //logs event
    cocos2d::log("touch ended");
}

//Function called when touch/click and drag
void TouchScene::onTouchMoved(Touch* touch, Event* event)
{
    //logs event continuously while dragging
    cocos2d::log("touch moved");
}

//Function called when external source (i.e. phone call) interrupts touch/click
void TouchScene::onTouchCancelled(Touch* touch, Event* event)
{
    cocos2d::log("touch cancelled");
}