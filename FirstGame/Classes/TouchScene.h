#pragma once

#include "cocos2d.h"

class TouchScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

    //touch/click event functions
    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*); //single touch/click
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*); //release from single touch/click
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*); //touch/click and drag
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);  //touch/click ended from external 

	CREATE_FUNC(TouchScene);

private:
    //label for text
    cocos2d::Label* labelTouchInfo;
};