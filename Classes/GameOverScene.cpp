//
// Created by Shubham on 19/06/18.
//

#include "GameOverScene.h"


GameOverScene::GameOverScene(cocos2d::Layer *layer)
{
    auto backGround = Sprite::create("CarRaceBackGround.png");
    backGround->setPosition(Vec2(origin.x,origin.y));
    backGround->setAnchorPoint(Vec2(0,0));
    backGround->setScale(0.77f,1);
    layer->addChild(backGround,10);
}