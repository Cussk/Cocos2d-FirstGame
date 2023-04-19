#include "MouseScene.h"

USING_NS_CC;

cocos2d::Scene* MouseScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MouseScene::create();
    scene->addChild(layer);

    return scene;
}

bool MouseScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto listener = EventListenerMouse::create();

    //lambda mouse click event listener
    listener->onMouseDown = [](cocos2d::Event* event) {

        //try to cast Event to mouse event
        try {
            EventMouse* mouseEvent = dynamic_cast<EventMouse*>(event);
            mouseEvent->getMouseButton();
            /*std::stringstream message;
            message << "Mouse event: Button: " << mouseEvent->getMouseButton() << "pressed at point (" <<
                mouseEvent->getLocation().x << "," << mouseEvent->getLocation().y << ")";
            MessageBoxA(NULL, message.str().c_str(), "Mouse Event Details", MB_OK);*/

        }
        catch (std::bad_cast& e) {
            // Not sure what kind of event you passed us cocos, but it was the wrong one
            return;
        }
    };

    listener->onMouseMove = [](cocos2d::Event* event) {
        // Cast Event to EventMouse for position details like above
        cocos2d::log("Mouse moved event");
    };

    listener->onMouseScroll = [](cocos2d::Event* event) {
        cocos2d::log("Mouse wheel scrolled");
    };

    listener->onMouseUp = [](cocos2d::Event* event) {
        cocos2d::log("Mouse button released");
    };

    _eventDispatcher->addEventListenerWithFixedPriority(listener, 1);

    return true;
}