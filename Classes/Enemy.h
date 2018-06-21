//
// Created by Shubham on 19/06/18.
//

#ifndef PROJ_ANDROID_ENEMY_H
#define PROJ_ANDROID_ENEMY_H

#include "cocos2d.h"
#include "Definations.h"

USING_NS_CC;

class Enemy {
public:
    Enemy(cocos2d::Layer *layer);
    void enemyLeftCarMove(float delta);
    void enemyRightCarMove(float delta);
    int getScore();

private:
    std::string vehicleNames[8] = {"Ambulance.png","Black_viper.png","Car.png","Mini_truck.png","Mini_van.png","Police.png","taxi.png","truck.png"};
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    int rightCarYPos = -DISTANCE_BETWEEN_CARS;
    int leftCarYPos = -DISTANCE_BETWEEN_CARS;
    int leftCarSpawnYpos = origin.y - 100;
    int rightCarSpawnYpos = visibleSize.height + 100;
    int loc[12] = {1,0,2,2,0,1,2,1,0,0,2,1};
    int leftCarLoc[3] = {-84,-40,4};
    int rightCarLoc[3] = {46,90,134};
    int score;
    Sprite* leftCars[NO_OF_CARS_IN_LEFT_SIDE];
    Sprite* rightCars[NO_OF_CARS_IN_RIGHT_SIDE];
};


#endif //PROJ_ANDROID_ENEMY_H
