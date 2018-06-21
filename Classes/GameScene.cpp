//
// Created by Shubham on 19/06/18.
//

#include "GameScene.h"

using namespace std;
Scene* GameScene::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld( )->setGravity( Vect( 0, 0 ) );

    auto layer = GameScene::create();
    layer->setPhysicsWorld( scene->getPhysicsWorld());

    scene->addChild(layer);

    return scene;
}

bool GameScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT,3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Vec2(visibleSize.width/2 + origin.x,visibleSize.height/2));
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);

    scheduleOn = true;

    gameManager = new GameManager();
    player = new Player(this);
    road = new Road(this);
    enemy = new Enemy(this);

    countDownTimer = Label::createWithTTF(to_string(gameManager->time),"fonts/arial.ttf",80);
    countDownTimer->setPosition(Vec2(visibleSize.width/2+origin.x,visibleSize.height/2));
    this->addChild(countDownTimer);

    auto touchListner = EventListenerTouchOneByOne::create();
    touchListner->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListner, this);

    this->scheduleUpdate();
    return true;
}

void GameScene::setPhysicsWorld(cocos2d::PhysicsWorld *world)
{
    sceneWorld = world;
}

void GameScene::update(float delta)
{
    if (gameManager->gameStart == false && scheduleOn == true)
    {
        this->schedule(schedule_selector(GameScene::gameStartTimer),1.0f);
        scheduleOn = false;
    }
    if (gameManager->gameStart == true && gameManager->gameOver == false)
    {
        road->startRoad(delta);
        enemy->enemyLeftCarMove(delta);
        enemy->enemyRightCarMove(delta);
    }
}
bool GameScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
    if (gameManager->gameStart == true)
    {
        if (visibleSize.width/2 + origin.x > touch->getLocation().x)
        {
            player->playerMoveLeft();
        } else
        {
            player->playerMoveRight();
        }
    }
    return true;
}

void GameScene::gameStartTimer(float dt)
{
    gameManager->time--;
    countDownTimer->setString(to_string(gameManager->time));
    if (gameManager->time == 0)
    {
        gameManager->gameStart = true;
        countDownTimer->removeFromParent();
        this->unschedule(schedule_selector(GameScene::gameStartTimer));
    }
}
