#pragma once

#include "cocos2d.h"

class ActionsPause : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(ActionsPause);

private:
    cocos2d::Sprite* sprite, * sprite2;
    cocos2d::Label* label;
    bool spritePaused = false;
    cocos2d::Vector<Node*> pausedNodes;
};