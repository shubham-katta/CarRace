//
// Created by Shubham on 19/06/18.
//

#include "Road.h"

Road::Road(cocos2d::Layer *layer)
{
    for (int i = 0; i < noOfRoad; ++i) {
        yPos += visibleSize.height/2;
        auto roadLeft = Sprite::create("Road.png");
        auto roadRight = Sprite::create("Road.png");
        auto road = Node::create();

        // roadLeft->setScale(0.77f,1.0f);
        roadLeft->setAnchorPoint(Vec2(0,1));
        roadLeft->setScale(0.388f,0.5f);
        roadLeft->setPosition(Vec2(origin.x,origin.y));

        // roadLeft->setScale(0.77f,1.0f);
        roadRight->setAnchorPoint(Vec2(0,1));
        roadRight->setScale(0.388f,0.5f);
        roadRight->setPosition(Vec2(visibleSize.width/2 + 21,origin.y));

        road->setAnchorPoint(Vec2(0,1));
        road->setPosition(Vec2(origin.x - 23, yPos));

        road->addChild(roadLeft);
        road->addChild(roadRight);
        layer->addChild(road,-10);
        roads[i] = road;
    }
}

void Road::startRoad(float delta)
{
    for (int i = 0; i < noOfRoad; ++i) {
        auto position = roads[i]->getPosition();
        position.y -= 50 * delta;
        if (position.y  < 5 )
        {
            position.y = yPos  ;

        }
        roads[i]->setPosition(position);
    }
}