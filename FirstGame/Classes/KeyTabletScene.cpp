#include "KeyTabletScene.h"

USING_NS_CC;

Scene* KeyTabletScene::createScene()
{
    auto scene = Scene::create();

    auto layer = KeyTabletScene::create();
    scene->addChild(layer);

    return scene;
}

bool KeyTabletScene::init()
{
    if (!Layer::init())
    {
        return false;
    }


    // Create a text field
    TextFieldTTF* textField = cocos2d::TextFieldTTF::textFieldWithPlaceHolder("Click here to type",
        cocos2d::Size(400, 200), TextHAlignment::LEFT, "Arial", 42.0);
    textField->setPosition(this->getBoundingBox().getMidX(),
        this->getBoundingBox().getMaxY() - 20);
    textField->setColorSpaceHolder(Color3B::GREEN);
    textField->setDelegate(this);

    this->addChild(textField);

    // Add a touch handler to our textfield that will show a keyboard when touched
    auto touchListener = EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = [](cocos2d::Touch* touch, cocos2d::Event* event) -> bool {
        try {
            // Show the on screen keyboard
            auto textField = dynamic_cast<TextFieldTTF*>(event->getCurrentTarget());
            textField->attachWithIME();
            return true;
        }
        catch (std::bad_cast& err) {
            return true;
        }
    };

    //dispatches event call to textfield
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, textField);

    return true;
}

//destructor
KeyTabletScene::~KeyTabletScene() {

}

bool KeyTabletScene::onTextFieldAttachWithIME(TextFieldTTF* sender) {
    return TextFieldDelegate::onTextFieldAttachWithIME(sender);
}

bool KeyTabletScene::onTextFieldDetachWithIME(TextFieldTTF* sender) {
    return TextFieldDelegate::onTextFieldDetachWithIME(sender);
}

bool KeyTabletScene::onTextFieldInsertText(TextFieldTTF* sender, const char* text, size_t nLen) {
    return TextFieldDelegate::onTextFieldInsertText(sender, text, nLen);
}

bool KeyTabletScene::onTextFieldDeleteBackward(TextFieldTTF* sender, const char* delText, size_t nLen) {
    return TextFieldDelegate::onTextFieldDeleteBackward(sender, delText, nLen);
}

bool KeyTabletScene::onVisit(TextFieldTTF* sender, Renderer* renderer, const Mat4& transform, uint32_t flags) {
    return TextFieldDelegate::onVisit(sender, renderer, transform, flags);
}