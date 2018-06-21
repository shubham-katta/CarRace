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
#include "GameManager.h"

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    GameManager *gameManager;
    Player *player;
    Road *road;
    Enemy *enemy;


    bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event);

    CREATE_FUNC(GameScene);
private:
    cocos2d::PhysicsWorld *sceneWorld;
    void setPhysicsWorld(cocos2d::PhysicsWorld *world);
    void update(float delta) override ;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

};

#endif //PROJ_ANDROID_GAMESCENE_H
