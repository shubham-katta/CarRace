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
        auto enemyBody = PhysicsBody::createBox(leftCar->getContentSize(),PhysicsMaterial(0,1,0));
        enemyBody->setDynamic(false);
        enemyBody->setCollisionBitmask(2);
        enemyBody->setContactTestBitmask(true);
        leftCar->setPhysicsBody(enemyBody);
        layer->addChild(leftCar,5);
        leftCars[i] = leftCar;
    }
    for (int i = 0; i < NO_OF_CARS_IN_RIGHT_SIDE; i++) {
        rightCarYPos += DISTANCE_BETWEEN_CARS;
        auto rightCar = Sprite::create(vehicleNames[cocos2d::RandomHelper::random_int(0,7)]);
        rightCar->setPosition(Vec2(visibleSize.width/2 + rightCarLoc[loc[cocos2d::RandomHelper::random_int(0,11)]],visibleSize.height + rightCarYPos));
        auto enemyBody = PhysicsBody::createBox(rightCar->getContentSize(),PhysicsMaterial(0,1,0));
        enemyBody->setDynamic(false);
        enemyBody->setCollisionBitmask(2);
        enemyBody->setContactTestBitmask(true);
        rightCar->setPhysicsBody(enemyBody);
        rightCar->setFlippedY(true);
        layer->addChild(rightCar,5);
        rightCars[i] = rightCar;
    }
    score = 0;
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
            leftCars[i]->getPhysicsBody()->removeFromWorld();
            auto enemyBody = PhysicsBody::createBox(leftCars[i]->getContentSize(),PhysicsMaterial(0,1,0));
            enemyBody->setDynamic(false);
            enemyBody->setCollisionBitmask(2);
            enemyBody->setContactTestBitmask(true);
            leftCars[i]->setPhysicsBody(enemyBody);
            score++;
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
            rightCars[i]->getPhysicsBody()->removeFromWorld();
            auto enemyBody = PhysicsBody::createBox(rightCars[i]->getContentSize(),PhysicsMaterial(0,1,0));
            enemyBody->setDynamic(false);
            enemyBody->setCollisionBitmask(2);
            enemyBody->setContactTestBitmask(true);
            rightCars[i]->setPhysicsBody(enemyBody);
        }
        rightCars[i]->setPosition(position);
    }
}

int Enemy::getScore()
{
    return score;
}