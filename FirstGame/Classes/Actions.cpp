#include "Actions.h"

cocos2d::Scene* Actions::createScene()
{
    auto scene = cocos2d::Scene::create();
    auto layer = Actions::create();
    scene->addChild(layer);
    return scene;
}

bool Actions::init()
{
    //initiates layer with background color that can be changed
    if (!LayerColor::initWithColor(cocos2d::Color4B::BLACK))
    {
        return false;
    }

    sprite = cocos2d::Sprite::create("Veyron.png");
    sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
    this->addChild(sprite, 0);

    //event listener for key press by any key
    auto listener = cocos2d::EventListenerKeyboard::create();
    listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event)->void {

        /*Actions Over Time inherit from ActionInterval*/

        //MoveTo action moving sprite to designated position over designated time
        /*auto action = cocos2d::MoveTo::create(2, cocos2d::Vec2(0, 0));*/

        //MoveBy action moving sprite a designated number of pixels over time
        /*auto action = cocos2d::MoveBy::create(2, cocos2d::Vec2(300, 300));*/

    	//tells sprite to perform the action
        /*sprite->runAction(action);*/

        //cocos Vector array (not a std::vector) of actions 
        /*cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
        actions.pushBack(cocos2d::ScaleBy::create(1.5, 1.5));
        actions.pushBack(cocos2d::TintTo::create(1.5, 255, 0, 0));
        actions.pushBack(cocos2d::FadeTo::create(1.5, 30));

        //creates an action sequence from array run back-to-back
        auto sequence = cocos2d::Sequence::create(actions);

        //calls whole sequence with 1 key press
        sprite->runAction(sequence);*/

        //same as above Vector array of actions
        /*cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
        actions.pushBack(cocos2d::ScaleBy::create(4, 1.5));
        actions.pushBack(cocos2d::TintTo::create(4, 255, 0, 0));
        actions.pushBack(cocos2d::FadeTo::create(4, 30));

        //creates an action group from array run all at once
        auto parallel = cocos2d::Spawn::create(actions);

        sprite->runAction(parallel);*/

        //repeating actions
        /*auto action = cocos2d::MoveBy::create(0.2, cocos2d::Vec2(10, 0));
        auto action2 = cocos2d::ScaleBy::create(2, 1.3);
        //variable to repeat action a designated amount of time
        auto repeat = cocos2d::Repeat::create(action, 10);
        //variable to repeat action "Forever" while application is running
        auto repeatForever = cocos2d::RepeatForever::create(action2);

        sprite->runAction(repeat);
        sprite->runAction(repeatForever);*/

        /*Instant Actions inherit from ActionInstant*/

        cocos2d::Vector<cocos2d::FiniteTimeAction*> actions;
        //interval action
        actions.pushBack(cocos2d::MoveTo::create(1, cocos2d::Vec2(0, 0)));
        //delays specified time between actions
        actions.pushBack(cocos2d::DelayTime::create(1));
        //places node back in center of window
        actions.pushBack(cocos2d::Place::create(cocos2d::Vec2(
            this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY())));
        actions.pushBack(cocos2d::DelayTime::create(1));
        //instant actions with delays between
        actions.pushBack(cocos2d::FlipX::create(true));
        actions.pushBack(cocos2d::DelayTime::create(1));
        actions.pushBack(cocos2d::FlipY::create(true));
        actions.pushBack(cocos2d::DelayTime::create(1));
        actions.pushBack(cocos2d::Hide::create());
        actions.pushBack(cocos2d::DelayTime::create(1));
        actions.pushBack(cocos2d::Show::create());
        actions.pushBack(cocos2d::DelayTime::create(1));

        //calls to a function to perform action, calls lambda here to change bg color
        actions.pushBack(cocos2d::CallFunc::create([=]()->void {
            this->setColor(cocos2d::Color3B::RED);
            }));

        actions.pushBack(cocos2d::DelayTime::create(1));
        //removes node from parent, calling true will perform cleanup
        actions.pushBack(cocos2d::RemoveSelf::create(false));

        //createsequence from array then call sequence
        auto sequence = cocos2d::Sequence::create(actions);
        sprite->runAction(sequence);
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}