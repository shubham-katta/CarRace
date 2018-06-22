//
// Created by Shubham on 19/06/18.
//

#include "Player.h"

Player::Player(cocos2d::Layer *layer)
{
    player = Sprite::create("Audi.png");
    player->setPosition(Vec2( visibleSize.width/2 + 25, 90));
    auto playerBody = PhysicsBody::createBox(player->getContentSize(),PhysicsMaterial(0,1,0));
    playerBody->setCollisionBitmask(1);
    playerBody->setContactTestBitmask(true);
    player->setPhysicsBody(playerBody);
    layer->addChild(player, 5);
}

void Player::playerMoveRight()
{
    if (player->getPosition().x < visibleSize.width + origin.x - player->getContentSize().width - 5)
    {
        auto position = player->getPosition();
        position.x += PLAYER_SPEED ;
        player->setPosition(position);
    }
}

void Player::playerMoveLeft()
{
    if (player->getPosition().x > origin.x + player->getContentSize().width + 5)
    {
        auto position = player->getPosition();
        position.x -= PLAYER_SPEED;
        player->setPosition(position);
    }
}

void Player::speedBtn(cocos2d::Layer *layer)
{
    
}