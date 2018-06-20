//
// Created by Shubham on 19/06/18.
//

#include "Player.h"

Player::Player(cocos2d::Layer *layer)
{
    player = Sprite::create("Audi.png");
    player->setPosition(Vec2( visibleSize.width/2 + 25, 30));
    layer->addChild(player, 5);
}

void Player::playerMoveRight()
{
    auto position = player->getPosition();
    position.x += PLAYER_SPEED ;
    player->setPosition(position);
}

void Player::playerMoveLeft()
{
    auto position = player->getPosition();
    position.x -= PLAYER_SPEED ;
    player->setPosition(position);
}