//
// Created by Shubham on 19/06/18.
//

#ifndef PROJ_ANDROID_ROAD_H
#define PROJ_ANDROID_ROAD_H

#include "cocos2d.h"

USING_NS_CC;

class Road {
public:
    Road(cocos2d::Layer *layer);
    void startRoad(float delta);

private:
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    int noOfRoad = 3;
    Node* roads[3];
    float yPos;

};


#endif //PROJ_ANDROID_ROAD_H
