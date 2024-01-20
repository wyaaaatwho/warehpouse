//
// Created by 26711 on 2023/12/21.
//

#ifndef RUNNINGPEPPA_PEPPA_H
#define RUNNINGPEPPA_PEPPA_H
#include "global.h"
void pigpeppa(SDL_Rect *peppaArgue,SDL_Event *peppaMove);
void peppaDisplay(SDL_Rect *pigRect,SDL_Texture *pigTexture);
void peppaNormalDisplay();
void peppaDeathDisplay();
#endif //RUNNINGPEPPA_PEPPA_H
