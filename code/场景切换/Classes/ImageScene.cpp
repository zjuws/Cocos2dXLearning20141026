//
//  ImageScene.cpp
//  learntx
//
//  Created by  ws on 14/10/26.
//
//

#include "ImageScene.h"
#include "HelloWorldScene.h"


Scene* ImageScene::createScene(){
    
    Scene* scene=Scene::create();
    ImageScene* layer=ImageScene::create();
    scene->addChild(layer);
    return scene;
}

bool ImageScene::init(){
    Size size=Director::getInstance()->getVisibleSize();
    Sprite *s=Sprite::create("HelloWorld.png");
    s->setPosition(size.width/2,size.height/2);
    addChild(s);
    auto *label=Label::createWithSystemFont("Show ahead scene", "Courier", 36);
    label->setPosition(size.width/2,size.height/2);
    addChild(label);
    
    EventListenerTouchOneByOne *listener=EventListenerTouchOneByOne::create();
    listener->onTouchBegan=[label](Touch* t,Event* e){
        if (label->getBoundingBox().containsPoint(t->getLocation())) {
            Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(1, HelloWorld::createScene()));
        }
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, label);
    
    
    
    
    return true;
}