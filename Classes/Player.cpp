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
        position.x += PLAYER_SPEED;
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

void Player::speedBtns(cocos2d::Layer *layer)
{
    auto speedIncreaseBtn = MenuItemImage::create("UI/SpeedBtn.png", "UI/SpeedBtn.png", CC_CALLBACK_1( Player::speedIncrease, this ));
    speedIncreaseBtn->setPosition(Vec2(visibleSize.width - speedIncreaseBtn->getContentSize().width, visibleSize.height/2 + speedIncreaseBtn->getContentSize().height));
    speedIncreaseBtn->setScale(1.25f,1.25f);

    auto speedDecreaseBtn = MenuItemImage::create("UI/SpeedBtnDown.png", "UI/SpeedBtnDown.png", CC_CALLBACK_1( Player::speedDecrease, this ));
    speedDecreaseBtn->setPosition(Vec2(visibleSize.width - speedIncreaseBtn->getContentSize().width, visibleSize.height/2 - speedIncreaseBtn->getContentSize().height));
    speedDecreaseBtn->setScale(1.25f,1.25f);

    auto menuItem = Menu::create( speedIncreaseBtn, speedDecreaseBtn, NULL);
    menuItem->setPosition(Vec2(origin.x,origin.y));
    layer->addChild(menuItem,3);
}

void Player::speedIncrease(cocos2d::Ref *pSender)
{
   if (player->getPosition().y < visibleSize.height - player->getContentSize().height - 5)
   {
       auto position = player->getPosition();
       position.y +=10;
       player->setPosition(position);
   }
}

void Player::speedDecrease(cocos2d::Ref *pSender)
{
    if (player->getPosition().y > origin.y + player->getContentSize().height - 5)
    {
        auto position = player->getPosition();
        position.y -= 10;
        player->setPosition(position);
    }
}