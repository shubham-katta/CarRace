//
// Created by Shubham on 19/06/18.
//

#include "Enemy.h"

Enemy::Enemy(cocos2d::Layer *layer)
{
    auto car1 = Sprite::create(vehicleNames[0]);
    car1->setPosition(Vec2(visibleSize.width/2 + 46,10));
    layer->addChild(car1,5);
    auto car2 = Sprite::create(vehicleNames[1]);
    car2->setPosition(Vec2(visibleSize.width/2 + 46,30));
    layer->addChild(car2,5);
    auto car3 = Sprite::create(vehicleNames[2]);
    car3->setPosition(Vec2(visibleSize.width/2 + 46,50));
    layer->addChild(car3,5);
    auto car4 = Sprite::create(vehicleNames[3]);
    car4->setPosition(Vec2(visibleSize.width/2 + 46,70));
    layer->addChild(car4,5);
    auto car5 = Sprite::create(vehicleNames[4]);
    car5->setPosition(Vec2(visibleSize.width/2 + 46,90));
    layer->addChild(car5,5);
    auto car6 = Sprite::create(vehicleNames[5]);
    car6->setPosition(Vec2(visibleSize.width/2 + 46,110));
    layer->addChild(car6,5);
    auto car7 = Sprite::create(vehicleNames[6]);
    car7->setPosition(Vec2(visibleSize.width/2 + 46,130));
    layer->addChild(car7,5);
    auto car8 = Sprite::create(vehicleNames[7]);
    car8->setPosition(Vec2(visibleSize.width/2 + 46,150));
    layer->addChild(car8,5);
}