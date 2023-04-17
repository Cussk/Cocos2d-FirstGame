#pragma once

#include "cocos2d.h"

class  AppDelegate : private cocos2d::Application
{
public:
	//constructor
	AppDelegate();

	//destructor
    virtual ~AppDelegate();

	//
    virtual bool applicationDidFinishLaunching();

	virtual void applicationDidEnterBackground();

	virtual void applicationWillEnterForeground();
};