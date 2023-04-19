#include "AppDelegate.h"

#include "Actions.h"
#include "ActionsPause.h"
#include "HelloWorldScene.h"
#include "GraphicsScene.h"
#include "TouchScene.h"
#include "TouchSceneLambda.h"
#include "MultiTouchScene.h"
#include "MouseScene.h"
#include "KeyboardScene.h"
#include "KeyboardPollScene.h"
#include "KeyTabletScene.h"
#include "GameLoop.h"

USING_NS_CC;

//constructor
AppDelegate::AppDelegate() {

}

//destructor
AppDelegate::~AppDelegate()
{
}

//called when finishing loading game
bool AppDelegate::applicationDidFinishLaunching()
{
    //get instance of director
    auto director = Director::getInstance();

	//set up game window
    auto glview = director->getOpenGLView();
    if (!glview) {
        glview = GLViewImpl::create("Tutorial");
        //glview->setFrameSize(640, 480);
        director->setOpenGLView(glview);
    }

    //create instance of scene
    //auto scene = HelloWorld::createScene();
    //auto scene = GraphicsScene::createScene();
    //auto scene = TouchScene::createScene();
    //auto scene = TouchSceneLambda::createScene();
    //auto scene = MultiTouch::createScene();
    //auto scene = MouseScene::createScene();
    //auto scene = KeyboardScene::createScene();
    //auto scene = KeyboardPollScene::createScene();
    //auto scene = KeyTabletScene::createScene();
    //auto scene = GameLoop::createScene();
    //auto scene = Actions::createScene();
    auto scene = ActionsPause::createScene();

    //use on scene game will start with only
    director->runWithScene(scene);

    return true;
}

//called when game is out of focus
void AppDelegate::applicationDidEnterBackground()
{

}

//called when game is brought back into focus
void AppDelegate::applicationWillEnterForeground()
{

}