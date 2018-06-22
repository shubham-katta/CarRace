//
// Created by Shubham on 19/06/18.
//

#ifndef PROJ_ANDROID_PLAYER_H
#define PROJ_ANDROID_PLAYER_H

#include "cocos2d.h"
#include "Definations.h"

USING_NS_CC;

class Player {
public:
    Player(cocos2d::Layer *layer);
    void playerMoveRight();
    void playerMoveLeft();
    void speedBtn(cocos2d::Layer *layer);

private:
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Sprite* player;

};


#endif //PROJ_ANDROID_PLAYER_H
