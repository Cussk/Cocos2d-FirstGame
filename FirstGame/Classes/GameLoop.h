#pragma once

#include "cocos2d.h"

class GameLoop : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(GameLoop);

    void update(float) override;

private:
    cocos2d::Sprite* sprite;
};