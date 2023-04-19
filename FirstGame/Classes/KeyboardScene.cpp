#include "KeyboardScene.h"

USING_NS_CC;

Scene* KeyboardScene::createScene()
{
    auto scene = Scene::create();

    auto layer = KeyboardScene::create();
    scene->addChild(layer);
    return scene;
}

bool KeyboardScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    //creates sprite as child of layer, sets position in center of screen
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);

    this->addChild(sprite, 0);

    //create keyboard event listener
    auto eventListener = EventListenerKeyboard::create();


    //lambda function for keyboard event
    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

        //vector2 x,y position of target of event (i.e. sprite)
        Vec2 loc = event->getCurrentTarget()->getPosition();
        switch (keyCode) {
            //press left arrow or A
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            //change target position in x direction negative or left on screen
            event->getCurrentTarget()->setPosition(--loc.x, loc.y);
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            //change target position in x direction positive or right on screen
            event->getCurrentTarget()->setPosition(++loc.x, loc.y);
            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            //change target position in y direction positive or up on screen
            event->getCurrentTarget()->setPosition(loc.x, ++loc.y);
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            //change target position in y direction negative or down on screen
            event->getCurrentTarget()->setPosition(loc.x, --loc.y);
            break;
        }
    };

    //dispatches event calls to sprite
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, sprite);

    return true;
}