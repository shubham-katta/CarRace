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

    player = new Player(this);
    road = new Road(this);
    enemy = new Enemy(this);

    auto touchListner = EventListenerTouchOneByOne::create();
    touchListner->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListner, this);

    gameStart = true;
    this->scheduleUpdate();
    return true;
}

void GameScene::setPhysicsWorld(cocos2d::PhysicsWorld *world)
{
    sceneWorld = world;
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
bool GameScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
    if (visibleSize.width/2 > touch->getLocation().x)
    {
        player->playerMoveLeft();
    } else
    {
        player->playerMoveRight();
    }
    return true;
}
