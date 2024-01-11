//
// Created by 26711 on 2023/12/21.
//

#ifndef RUNNINGPEPPA_PEPPA_H
#define RUNNINGPEPPA_PEPPA_H
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>
extern SDL_Window* window;

extern SDL_Surface* backGround1;
extern SDL_Surface* backGround2;
extern SDL_Surface* peppa;
extern SDL_Surface* peppa_left;
extern SDL_Surface* peppa_right;
extern SDL_Surface* peppa_shoot;
extern SDL_Surface* peppa_kneel;
extern SDL_Surface* Start_button;
extern SDL_Surface* difficulty_font;
extern SDL_Surface* obstacle1;
extern SDL_Surface* obstacle2;
extern SDL_Surface* obstacle3;
extern SDL_Surface* obstacle4;
extern SDL_Surface* obstacle5;
extern SDL_Surface* obstacle6;
extern SDL_Surface* obstacle7;

extern SDL_Renderer* render1;

extern SDL_Texture* texture1;
extern SDL_Texture* texture2;
extern SDL_Texture* Start_button_texture;
extern SDL_Texture* peppa_texture;
extern SDL_Texture* peppa_left_texture;
extern SDL_Texture* peppa_right_texture;
extern SDL_Texture* peppa_shoot_texture;
extern SDL_Texture* peppa_kneel_texture;
extern SDL_Texture* difficulty_font_texture1;
extern SDL_Texture* difficulty_font_texture2;
extern SDL_Texture* obstacle1_texture;
extern SDL_Texture* obstacle2_texture;
extern SDL_Texture* obstacle3_texture;
extern SDL_Texture* obstacle4_texture;
extern SDL_Texture* obstacle5_texture;
extern SDL_Texture* obstacle6_texture;
extern SDL_Texture* obstacle7_texture;

extern SDL_Rect rect_background1;
extern SDL_Rect rect_background2;
extern SDL_Rect rect_peppa_left ;
extern SDL_Rect rect_peppa_right ;
extern SDL_Rect rect_peppa_shoot ;
extern SDL_Rect rect_peppa_kneel;
extern SDL_Rect rect_obstacle1;
extern SDL_Rect rect_obstacle2;
extern SDL_Rect rect_obstacle3;
extern SDL_Rect rect_obstacle4;
extern SDL_Rect rect_obstacle5;
extern SDL_Rect rect_obstacle6;
extern SDL_Rect rect_obstacle7;

extern TTF_Font* font;
extern SDL_Color font_color1;
extern SDL_Color font_color2;

extern bool running;
extern bool keyIsPressed;

extern int life;
extern int lr;
extern int speed;
extern int hardness;

extern int isObstacle1;
extern int isObstacle2;
extern int isObstacle3;
extern int isObstacle4;
extern int isObstacle5;
extern int isObstacle6;
extern int isObstacle7;
extern int generate;
extern int isPeppaKneel;
extern int peppaHurt;
extern int isHurt;

void pigpeppa(SDL_Rect *peppaArgue,SDL_Event *peppaMove);
void obstacleInit(SDL_Rect *obstacleArgue,int *num,int index);

extern void obstacleMove();
#endif //RUNNINGPEPPA_PEPPA_H
