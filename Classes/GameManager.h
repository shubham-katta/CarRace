//
// Created by Shubham on 21/06/18.
//

#ifndef PROJ_ANDROID_GAMEMANAGER_H
#define PROJ_ANDROID_GAMEMANAGER_H

#include "cocos2d.h"
#include "Enemy.h"

USING_NS_CC;

class GameManager {
public:
    GameManager();
    void displayScore(cocos2d::Layer *layer);
    void displayChangedScore(int scored);
    bool gameStart;
    bool gameOver;
    int time ;
    int score;
    Label* scoreLabel;

private:
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

};


#endif //PROJ_ANDROID_GAMEMANAGER_H
