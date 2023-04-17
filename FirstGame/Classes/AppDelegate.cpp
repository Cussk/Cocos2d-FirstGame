#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "GraphicsScene.h"

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
        glview = GLViewImpl::create("Hello World");
        glview->setFrameSize(640, 480);
        director->setOpenGLView(glview);
    }

    //create instance of scene
    auto scene = GraphicsScene::createScene();
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