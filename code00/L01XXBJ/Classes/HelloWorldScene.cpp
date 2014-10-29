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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
//    TTFConfig ttfConfig;
//    ttfConfig.fontFilePath = "fonts/Marker Felt.ttf"; //必须配置
//    ttfConfig.fontSize = 30;
//    ttfConfig.distanceFieldEnabled = false;
//    ttfConfig.outlineSize = 0;
//    ttfConfig.glyphs = GlyphCollection::DYNAMIC;
//    ttfConfig.customGlyphs = nullptr;
    
    //使用TTFConfig配置，来创建TTF
//    Label* lb3 = Label::createWithTTF("123abc","fonts/Marker Felt.ttf",30);
//    lb3->setPosition(visibleSize.width/2,visibleSize.height/2);
//    addChild(lb3);
////    lb3->setLineBreakWithoutSpace(true);
////    lb3->setWidth(40);
////    lb3->setMaxLineWidth(60);
////    lb3->setLineHeight(80);
////    lb3->setAdditionalKerning(10);
//    auto letter1=lb3->getLetter(1);
//    letter1->setColor(Color3B::GREEN);
//    letter1->setScale(2.0f);
//    auto letter4=lb3->getLetter(4);
//    letter4->setColor(Color3B::RED);
//    letter4->runAction(RepeatForever::create(RotateBy::create(1.0f, 90)));
//------------------------------------------------------
//    Label* lb4 = Label::createWithCharMap("fonts/digit.jpeg", 60, 20, '0');
//    lb4->setString("1234"); //设置字符串内容
//    lb4->setPosition(visibleSize.width/2,visibleSize.height/2);
//    addChild(lb4);
//------------------------------------------------------------------
    //创建图片纹理Texture2D
//    Texture2D* texture = TextureCache::getInstance()->addImage("fonts/digit.png");
//    
//    Label* lb5 = Label::createWithCharMap(texture, 20, 20, '0');
//    lb5->setString("123456"); //设置字符串内容
//    lb5->setPosition(visibleSize.width/2,visibleSize.height/2);
//    addChild(lb5);
//---------------------------------------------------------------------
    
    
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
