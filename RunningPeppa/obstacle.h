//
// Created by 26711 on 2024/1/5.
//

#ifndef RUNNINGPEPPA_OBSTACLE_H
#define RUNNINGPEPPA_OBSTACLE_H

#include "global.h"

void obstacleInit(SDL_Rect *obstacleArgue,int *num,int index);
void obstacleMove();
void rewardInit(SDL_Rect *rewardArgue,int *num,int index);
void attackMove();
bool collide(SDL_Rect *rect1);
bool destroyObstacle(SDL_Rect *rect1);

#endif //RUNNINGPEPPA_OBSTACLE_H
