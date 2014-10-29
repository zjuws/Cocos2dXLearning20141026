#include "HelloWorldScene.h"
#include "ImageScene.h"
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
        Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto ks=Sprite::create("kaishi.jpg");
    ks->setPosition(visibleSize.width/2,visibleSize.height/2);
    addChild(ks);
    auto *label=Label::createWithSystemFont("Show next scene", "Courier", 36);
    label->setPosition(visibleSize.width/2,visibleSize.height/2);
    addChild(label);
    
    EventListenerTouchOneByOne *listener=EventListenerTouchOneByOne::create();
    listener->onTouchBegan=[label](Touch* t,Event* e){
        if (label->getBoundingBox().containsPoint(t->getLocation())) {
            Director::getInstance()->replaceScene(TransitionJumpZoom::create(1, ImageScene::createScene()));
        }
        return false;
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
