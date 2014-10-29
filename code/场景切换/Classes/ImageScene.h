//
//  ImageScene.h
//  learntx
//
//  Created by  ws on 14/10/26.
//
//

#ifndef __learntx__ImageScene__
#define __learntx__ImageScene__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class ImageScene:public Layer{
public:
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(ImageScene);
};
#endif /* defined(__learntx__ImageScene__) */
