#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
//读取文件
    auto fu=FileUtils::getInstance();
    Data d=fu->getDataFromFile(fu->fullPathFromRelativeFile("data.txt", fu->getWritablePath()));
    log("%s",d.getBytes());
    
    
////-------------------------------------------------------------
////写入文件
//    FileUtils *fu=FileUtils::getInstance();
//    FILE *f=fopen(fu->fullPathFromRelativeFile("data.txt", fu->getWritablePath()).c_str(), "w");
//    fprintf(f, "Hello ws\n");
//    fclose(f);
//    log("%s",fu->getWritablePath().c_str());
////-------------------------------------------------------------------------
////UserDefault的用法
//    UserDefault::getInstance()->setStringForKey("data", "Hello ws");
//    
//    log("%s",UserDefault::getInstance()->getStringForKey("data1","Hello world").c_str());
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
