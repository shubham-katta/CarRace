/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "MainMenu.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}

bool MainMenu::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backGround = Sprite::create("CarRaceBackGround.png");
    backGround->setPosition(Vec2(origin.x,origin.y));
    backGround->setAnchorPoint(Vec2(0,0));
    backGround->setScale(0.77f,1);
    this->addChild(backGround,-10);

    auto playBtn = MenuItemImage::create("start.png", "start.png", CC_CALLBACK_1( MainMenu::playGameScene, this ));
    playBtn->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    playBtn->setScale(1.25f,1.25f);

    auto exitBtn = MenuItemImage::create( "exit.png", "exit.png", CC_CALLBACK_1( MainMenu::exitGame, this ) );
    exitBtn->setPosition(Vec2(visibleSize.width , visibleSize.height + origin.y));
    exitBtn->setAnchorPoint(Vec2(1,1));

    auto menuItem = Menu::create(playBtn, exitBtn, NULL);
    menuItem->setPosition(Vec2(origin.x,origin.y));
    this->addChild(menuItem,3);


    return true;
}

void MainMenu::playGameScene(cocos2d::Ref *pSender)
{
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(2,scene));
}

void MainMenu::exitGame(cocos2d::Ref *pSender)
{
    Director::getInstance()->end();
}

