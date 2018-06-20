//
// Created by Shubham on 19/06/18.
//

#ifndef PROJ_ANDROID_GAMEOVERSCENE_H
#define PROJ_ANDROID_GAMEOVERSCENE_H

#include "cocos2d.h"
#include <2d/CCScene.h>

USING_NS_CC;

class GameOverScene : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();


    CREATE_FUNC(GameOverScene);
private:

};


#endif //PROJ_ANDROID_GAMEOVERSCENE_H
