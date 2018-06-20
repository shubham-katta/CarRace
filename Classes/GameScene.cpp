//
// Created by Shubham on 19/06/18.
//

#include "GameScene.h"

using namespace std;
Scene* GameScene::createScene()
{
    auto scene = Scene::create();

    auto layer = GameScene::create();

    scene->addChild(layer);

    return scene;
}

bool GameScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    player = new Player(this);
    road = new Road(this);
    enemy = new Enemy(this);
    gameStart = true;
    this->scheduleUpdate();
    return true;
}

void GameScene::update(float delta)
{
    if (gameStart == true)
    {
        road->startRoad(delta);
        enemy->enemyLeftCarMove(delta);
        enemy->enemyRightCarMove(delta);
    }
}