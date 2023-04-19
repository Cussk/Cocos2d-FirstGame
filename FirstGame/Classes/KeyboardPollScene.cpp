#include "KeyboardPollScene.h"

USING_NS_CC;

Scene* KeyboardPollScene::createScene()
{
    auto scene = Scene::create();

    KeyboardPollScene* layer = KeyboardPollScene::create();
    scene->addChild(layer);
    return scene;
}

bool KeyboardPollScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    //create label as child of layer, center the bounding box in parent container
    label = cocos2d::Label::createWithSystemFont("Press the CTRL Key", "Arial", 32);
    label->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
    addChild(label);
    auto eventListener = EventListenerKeyboard::create();



    Director::getInstance()->getOpenGLView()->setIMEKeyboardState(true);
    eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        // If a key already exists, do nothing as it will already have a time stamp
        // Otherwise, set's the timestamp to now
        if (keys.find(keyCode) == keys.end()) {
            keys[keyCode] = std::chrono::high_resolution_clock::now();
        }
    };
    eventListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        // remove the key.  std::map.erase() doesn't care if the key doesnt exist
        keys.erase(keyCode);
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);

    // Let cocos know we have an update function to be called.
    this->scheduleUpdate();
    return true;
}

bool KeyboardPollScene::isKeyPressed(EventKeyboard::KeyCode code) {
    // Check if the key is currently pressed by seeing it it's in the std::map keys
    if (keys.find(code) != keys.end())
        return true;
    return false;
}

double KeyboardPollScene::keyPressedDuration(EventKeyboard::KeyCode code) {
    if (!isKeyPressed(EventKeyboard::KeyCode::KEY_CTRL))
        return 0;  // Not pressed, so no duration

    // Return the amount of time that has elapsed between now and when the user
    // first started holding down the key in milliseconds
    // the start time is the value we hold in our std::map keys
    return std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::high_resolution_clock::now() - keys[code]).count();
}

void KeyboardPollScene::update(float delta) {
    // Register an update function that checks to see if the CTRL key is pressed
    // and if it is displays how long, otherwise tell the user to press it
    Node::update(delta);
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_CTRL)) {
        std::stringstream ss;
        ss << "Control key has been pressed for " <<
            keyPressedDuration(EventKeyboard::KeyCode::KEY_CTRL) << " ms";
        label->setString(ss.str().c_str());
    }
    else
        label->setString("Press the CTRL Key");
}
// Because cocos2d-x requres createScene to be static, we need to make other non-pointer members static
std::map<cocos2d::EventKeyboard::KeyCode,
    std::chrono::high_resolution_clock::time_point> KeyboardPollScene::keys;