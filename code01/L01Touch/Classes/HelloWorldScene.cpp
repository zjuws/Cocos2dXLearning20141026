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
    Size size=Director::getInstance()->getVisibleSize();
    auto label=Label::createWithSystemFont("Click me", "Courier", 30);
    addChild(label);
    label->setPosition(Vec2(size.width/2,size.height/2));
    auto listener=EventListenerTouchOneByOne::create();
    listener->onTouchBegan=[](Touch* t,Event* e){
        if(e->getCurrentTarget()->getBoundingBox().containsPoint(t->getLocation())){
             log("onTouchBegin");
        }
       
        return true;
    };
    int count=0;
    listener->onTouchMoved=[count](Touch* t,Event* e) mutable{
        count++;
        log("onTouchMoved");
        
    };
       listener->onTouchEnded=[](Touch* t,Event* e){
        
        log("onTouchended");
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, label);
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
