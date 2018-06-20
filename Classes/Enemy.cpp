//
// Created by Shubham on 19/06/18.
//

#include "Enemy.h"

Enemy::Enemy(cocos2d::Layer *layer)
{
    for (int i = 0; i < NO_OF_CARS_IN_LEFT_SIDE; i++) {
        leftCarYPos += DISTANCE_BETWEEN_CARS;
        auto leftCar = Sprite::create(vehicleNames[cocos2d::RandomHelper::random_int(0,7)]);
        leftCar->setPosition(Vec2(visibleSize.width/2 + leftCarLoc[loc[cocos2d::RandomHelper::random_int(0,11)]],origin.y - leftCarYPos));
        layer->addChild(leftCar,5);
        leftCars[i] = leftCar;
    }
    for (int i = 0; i < NO_OF_CARS_IN_RIGHT_SIDE; i++) {
        rightCarYPos += DISTANCE_BETWEEN_CARS;
        auto rightCar = Sprite::create(vehicleNames[cocos2d::RandomHelper::random_int(0,7)]);
        rightCar->setPosition(Vec2(visibleSize.width/2 + rightCarLoc[loc[cocos2d::RandomHelper::random_int(0,11)]],visibleSize.height + rightCarYPos));
        rightCar->setFlippedY(true);
        layer->addChild(rightCar,5);
        rightCars[i] = rightCar;
    }
}

void Enemy::enemyLeftCarMove(float delta)
{
    for (int i = 0; i < NO_OF_CARS_IN_LEFT_SIDE; i++) {
        auto position = leftCars[i]->getPosition();
        position.y += 35 * delta;
        if (position.y  > visibleSize.height + 10 )
        {
            leftCars[i]->setTexture(vehicleNames[cocos2d::RandomHelper::random_int(0,7)]);
            position.y = leftCarSpawnYpos;
            position.x = visibleSize.width/2 + leftCarLoc[loc[cocos2d::RandomHelper::random_int(0,11)]];
        }
        leftCars[i]->setPosition(position);
    }
}

void Enemy::enemyRightCarMove(float delta)
{
    for (int i = 0; i < NO_OF_CARS_IN_RIGHT_SIDE; i++) {
        auto position = rightCars[i]->getPosition();
        position.y -= 35 * delta;
        if (position.y  < origin.y - 10)
        {
            rightCars[i]->setTexture(vehicleNames[cocos2d::RandomHelper::random_int(0,7)]);
            position.y = rightCarSpawnYpos;
            position.x = visibleSize.width/2 + rightCarLoc[loc[cocos2d::RandomHelper::random_int(0,11)]];
        }
        rightCars[i]->setPosition(position);
    }
}