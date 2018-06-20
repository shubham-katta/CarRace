//
// Created by Shubham on 19/06/18.
//

#include "GameOverScene.h"


Scene* GameOverScene::createScene()
{
    auto scene = Scene::create();

    auto layer = GameOverScene::create();

    scene->addChild(layer);

    return scene;
}

bool GameOverScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    return true;
}