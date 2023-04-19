#include "TouchSceneLambda.h"

USING_NS_CC;

//creates scene
Scene* TouchSceneLambda::createScene()
{
    auto scene = Scene::create();
    auto layer = TouchSceneLambda::create();
    scene->addChild(layer);

    return scene;
}

//initializes layer class
bool TouchSceneLambda::init()
{
    //if no layer return false
    if (!Layer::init())
    {
        return false;
    }

    //creates sprite and positions in center of window
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
        Director::getInstance()->getVisibleSize().height / 2));

    // Add a "touch" event listener to our sprite
    auto touchListener = EventListenerTouchOneByOne::create();

    //lambda function for onTouchBegan
    touchListener->onTouchBegan = [](Touch* touch, Event* event) -> bool
	{

        //get bounding box for current target i.e. sprite
        auto bounds = event->getCurrentTarget()->getBoundingBox();

        //If click/touch occurs within bounding box display below coordinate information
        if (bounds.containsPoint(touch->getLocation())) {
            std::stringstream touchDetails;
            touchDetails << "Touched at OpenGL coordinates: " <<
                touch->getLocation().x << "," << touch->getLocation().y << std::endl <<
                "Touched at UI coordinate: " <<
                touch->getLocationInView().x << "," << touch->getLocationInView().y << std::endl <<
                "Touched at local coordinate:" <<
                event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).x << "," <<
                event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).y << std::endl <<
                "Touch moved by:" << touch->getDelta().x << "," << touch->getDelta().y;

            //creates pop up message with above info
            MessageBoxA(NULL, touchDetails.str().c_str(), "Touched", MB_OK);
        }
        return true;
    };

    //sets sprite as the target of the event
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, sprite);
    this->addChild(sprite, 0);

    return true;
}