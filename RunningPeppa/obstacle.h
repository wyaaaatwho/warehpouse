//
// Created by 26711 on 2024/1/5.
//

#ifndef RUNNINGPEPPA_OBSTACLE_H
#define RUNNINGPEPPA_OBSTACLE_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <sys/time.h>
#include <time.h>
#include "global.h"
void obstacleInit(SDL_Rect *obstacleArgue,int *num,int index);
void obstacleMove();
void rewardInit();
#endif //RUNNINGPEPPA_OBSTACLE_H
