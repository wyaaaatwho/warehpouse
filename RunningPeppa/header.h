//
// Created by 26711 on 2023/12/19.
//

#ifndef RUNNINGPEPPA_HEADER_H
#define RUNNINGPEPPA_HEADER_H
//headers
#include "initiating.h"
#include "shutdown.h"
#include "homepage.h"
#include "peppa.h"
#include "obstacle.h"
#include <time.h>
#include <stdlib.h>
//declares
SDL_Window* window =NULL;

SDL_Surface* backGround1 =NULL;
SDL_Surface* backGround2 =NULL;
SDL_Surface* peppa =NULL;
SDL_Surface* peppa_left =NULL;
SDL_Surface* peppa_right =NULL;
SDL_Surface* peppa_shoot =NULL;
SDL_Surface* peppa_kneel =NULL;
SDL_Surface* Start_button =NULL;
SDL_Surface* Start_button_on =NULL;
SDL_Surface* difficulty_font=NULL;
SDL_Surface* name_font=NULL;
SDL_Surface* obstacle=NULL;


SDL_Renderer *render1=NULL;

SDL_Texture * texture1=NULL;
SDL_Texture * texture2=NULL;
SDL_Texture * Start_button_texture=NULL;
SDL_Texture *Start_button_on_texture=NULL;
SDL_Texture * peppa_texture=NULL;
SDL_Texture* peppa_left_texture =NULL;
SDL_Texture* peppa_right_texture =NULL;
SDL_Texture* peppa_shoot_texture =NULL;
SDL_Texture* peppa_kneel_texture =NULL;
SDL_Texture* name_font_texture=NULL;
SDL_Texture* difficulty_font_texture1=NULL;
SDL_Texture* difficulty_font_texture2=NULL;
SDL_Texture* obstacle1_texture=NULL;
SDL_Texture* obstacle2_texture=NULL;
SDL_Texture* obstacle3_texture=NULL;
SDL_Texture* obstacle4_texture=NULL;
SDL_Texture* obstacle5_texture=NULL;
SDL_Texture* obstacle6_texture=NULL;
SDL_Texture* obstacle7_texture=NULL;


SDL_Rect rect_background1={.x=0,.y=0};
SDL_Rect rect_background2={.x=1200,.y=0};
SDL_Rect rect_peppa = {.x=200, .y=330};
SDL_Rect rect_peppa_left = {.x=200, .y=330};
SDL_Rect rect_peppa_right = {.x=200, .y=330};
SDL_Rect rect_peppa_shoot = {.x=200, .y=330};
SDL_Rect rect_obstacle1 = {.x=1200, .y=340};
SDL_Rect rect_obstacle2 = {.x=1200, .y=325};
SDL_Rect rect_obstacle3 = {.x=1200, .y=280};
SDL_Rect rect_obstacle4 = {.x=1200, .y=320};
SDL_Rect rect_obstacle5 = {.x=1200, .y=350};
SDL_Rect rect_obstacle6 = {.x=1200, .y=320};
SDL_Rect rect_obstacle7 = {.x=1200, .y=300};

TTF_Font * font =NULL;
SDL_Color font_color1={0x00,0x00,0x00,0x00};
SDL_Color font_color2={0xff,0x00,0x00,0xff};

// bool
bool running=true;
bool keyIsPressed = false;

int life=3;int lr=1;
int speed =2;
int generate=0;
int hardness=1;
int isObstacle1=0;
int isObstacle2=0;
int isObstacle3=0;
int isObstacle4=0;
int isObstacle5=0;
int isObstacle6=0;
int isObstacle7=0;

#endif //RUNNINGPEPPA_HEADER_H
