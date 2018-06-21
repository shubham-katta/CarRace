//
// Created by Shubham on 21/06/18.
//

#ifndef PROJ_ANDROID_GAMEMANAGER_H
#define PROJ_ANDROID_GAMEMANAGER_H

#include "cocos2d.h"

class GameManager {
public:
    GameManager();
    void gameStartTimer(cocos2d::Layer *layer);
    bool gameStart;
    bool gameOver;


private:

};


#endif //PROJ_ANDROID_GAMEMANAGER_H
