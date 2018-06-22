//
// Created by Shubham on 19/06/18.
//

#ifndef PROJ_ANDROID_GAMEOVERSCENE_H
#define PROJ_ANDROID_GAMEOVERSCENE_H

#include "cocos2d.h"


USING_NS_CC;

class GameOverScene  {
public:
    GameOverScene(cocos2d::Layer *layer);


private:
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


};


#endif //PROJ_ANDROID_GAMEOVERSCENE_H
