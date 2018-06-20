//
// Created by Shubham on 19/06/18.
//

#include "Enemy.h"

Enemy::Enemy(cocos2d::Layer *layer)
{
    auto car1 = Sprite::create("Ambulance.png");
    Cars[0]=car1;
    auto car2 = Sprite::create("Black_Viper.png");
    Cars[1]=car2;
    auto car3 = Sprite::create("Car.png");
    Cars[2]=car3;
    auto car4 = Sprite::create("Mini_truck.png");
    Cars[3]=car4;
    auto car5 = Sprite::create("Mini_Van.png");
    Cars[4]=car5;
    auto car6 = Sprite::create("Police.png");
    Cars[5]=car6;
    auto car7 = Sprite::create("taxi.png");
    Cars[6]=car7;
    auto car8 = Sprite::create("truck.png");
    Cars[7]=car8;
}