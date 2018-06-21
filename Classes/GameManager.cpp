//
// Created by Shubham on 21/06/18.
//

#include "GameManager.h"

using namespace std;

GameManager::GameManager()
{
    gameStart = false;
    gameOver = false;
    time = 4;
    score = 0;
}

void GameManager::displayScore(cocos2d::Layer *layer)
{
    scoreLabel = Label::createWithTTF(to_string(score),"fonts/arial.ttf",70);
    scoreLabel->setPosition(Vec2(visibleSize.width/2 + origin.x,visibleSize.height - 30));
    layer->addChild(scoreLabel);
}

void GameManager::displayChangedScore(int scored)
{
    scoreLabel->setString(to_string(scored));
}