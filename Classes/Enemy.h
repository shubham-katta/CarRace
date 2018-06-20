//
// Created by Shubham on 19/06/18.
//

#ifndef PROJ_ANDROID_ENEMY_H
#define PROJ_ANDROID_ENEMY_H

#include "cocos2d.h"

USING_NS_CC;

class Enemy {
public:
    Enemy(cocos2d::Layer *layer);


private:
    std::string vehicleNames[8] = {"Ambulance.png","Black_viper.png","Car.png","Mini_truck.png","Mini_van.png","Police.png","taxi.png","truck.png"};
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
};


#endif //PROJ_ANDROID_ENEMY_H
