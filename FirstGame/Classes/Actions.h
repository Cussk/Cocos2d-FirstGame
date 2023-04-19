#pragma once

#include "cocos2d.h"

class Actions : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(Actions);

private:
    cocos2d::Sprite* sprite;
};