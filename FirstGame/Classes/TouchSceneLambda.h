#pragma once

#include "cocos2d.h"

class TouchSceneLambda : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(TouchSceneLambda);

private:
    //label for text
    cocos2d::Label* labelTouchInfo;
};