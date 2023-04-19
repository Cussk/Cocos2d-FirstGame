#pragma once

#include "cocos2d.h"

class MultiTouch : public cocos2d::Layer
{

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(MultiTouch);

private:
    //const variable for max allowed multi touch
    const static int MAX_TOUCHES = 5;

protected:
    //array of labels to show all multi touches
    cocos2d::Label* labelTouchLocations[MAX_TOUCHES];

};