//
// Created by Shubham on 19/06/18.
//

#ifndef PROJ_ANDROID_GAMESCENE_H
#define PROJ_ANDROID_GAMESCENE_H

#include "cocos2d.h"
#include <2d/CCScene.h>
#include "Road.h"
#include "Player.h"
#include "Enemy.h"

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    Player *player;
    Road *road;
    Enemy *enemy;
    bool gameStart = false;


    CREATE_FUNC(GameScene);
private:
    void update(float delta) override ;

};



#endif //PROJ_ANDROID_GAMESCENE_H
