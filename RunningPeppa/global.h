//
// Created by 26711 on 2024/1/11.
//

#ifndef RUNNINGPEPPA_GLOBAL_H
#define RUNNINGPEPPA_GLOBAL_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <time.h>
#include <stdlib.h>

#include "initiating.h"
#include "shutdown.h"
#include "pages.h"
#include "peppa.h"
#include "obstacle.h"
#include "status.h"

#define edge 1200
#define sky 610
#define ground 428
#define DELAY_TIME 2
#define Max_Life 3
#define Max_lana 3
#define obstacleGenerateNum 500
#define rewardGenerateNum 1000
#define lrNum 60
#define scoreNum 100
#define speed1 3
#define speed2 4
#define gunXray 240
#define bulletSpeed 6
#define hurtTime 500
#define vincibleTime 5000



extern SDL_Window* window;

extern SDL_Surface* backGround1;
extern SDL_Surface* backGround2;
extern SDL_Surface* peppa;
extern SDL_Surface* peppa_left;
extern SDL_Surface* peppa_right;
extern SDL_Surface* peppa_shoot;
extern SDL_Surface* peppa_kneel;
extern SDL_Surface* Start_button;
extern SDL_Surface* Start_button_on;
extern SDL_Surface* difficulty_font;
extern SDL_Surface* name_font;
extern SDL_Surface* obstacle1;
extern SDL_Surface* obstacle2;
extern SDL_Surface* obstacle3;
extern SDL_Surface* obstacle4;
extern SDL_Surface* obstacle5;
extern SDL_Surface* obstacle6;
extern SDL_Surface* obstacle7;
extern SDL_Surface* lifeBar;
extern SDL_Surface* lanaBar;
extern SDL_Surface* lanaFont;
extern SDL_Surface *reward1;
extern SDL_Surface *reward2;
extern SDL_Surface *bullet;
extern SDL_Surface *helpFont;
extern SDL_Surface *scoreFont;
extern SDL_Surface *restart;
extern SDL_Surface *pork;

extern SDL_Renderer *render1;

extern SDL_Texture * texture1;
extern SDL_Texture * texture2;
extern SDL_Texture * Start_button_texture;
extern SDL_Texture *Start_button_on_texture;
extern SDL_Texture * peppa_texture;
extern SDL_Texture* peppa_left_texture;
extern SDL_Texture* peppa_right_texture;
extern SDL_Texture* peppa_shoot_texture;
extern SDL_Texture* peppa_kneel_texture;
extern SDL_Texture* name_font_texture;
extern SDL_Texture* difficulty_font_texture1;
extern SDL_Texture* difficulty_font_texture2;
extern SDL_Texture* obstacle1_texture;
extern SDL_Texture* obstacle2_texture;
extern SDL_Texture* obstacle3_texture;
extern SDL_Texture* obstacle4_texture;
extern SDL_Texture* obstacle5_texture;
extern SDL_Texture* obstacle6_texture;
extern SDL_Texture* obstacle7_texture;
extern SDL_Texture *lifeBar1_texture;
extern SDL_Texture *lifeBar2_texture;
extern SDL_Texture *lifeBar3_texture;
extern SDL_Texture *lifeBar4_texture;
extern SDL_Texture *lanaBar_texture;
extern SDL_Texture* lanaFont_texture;
extern SDL_Texture *reward1_texture;
extern SDL_Texture* reward2_texture;
extern SDL_Texture* reward3_texture;
extern SDL_Texture* bullet_texture1;
extern SDL_Texture* bullet_texture2;
extern SDL_Texture* bullet_texture3;
extern SDL_Texture *scoreFontTexture;
extern SDL_Texture *helpFontTexture;
extern SDL_Texture *help_page1_texture;
extern SDL_Texture *help_page2_texture;
extern SDL_Texture *shield_texture;
extern SDL_Texture *restart1_texture;
extern SDL_Texture *restart2_texture;
extern SDL_Texture *pork_texture;

extern SDL_Rect rect_background1;
extern SDL_Rect rect_background2;
extern SDL_Rect rect_peppa;
extern SDL_Rect rect_peppa_left;
extern SDL_Rect rect_peppa_right;
extern SDL_Rect rect_peppa_shoot;
extern SDL_Rect rect_peppa_kneel;
extern SDL_Rect rect_obstacle1;
extern SDL_Rect rect_obstacle2;
extern SDL_Rect rect_obstacle3;
extern SDL_Rect rect_obstacle4;
extern SDL_Rect rect_obstacle5;
extern SDL_Rect rect_obstacle6;
extern SDL_Rect rect_obstacle7;
extern SDL_Rect rect_lifeBar;
extern SDL_Rect rect_lanaBar;
extern SDL_Rect rect_lanaBar_font;
extern SDL_Rect rect_reward1;
extern SDL_Rect rect_reward2;
extern SDL_Rect rect_reward3;
extern SDL_Rect rect_bullet1;
extern SDL_Rect rect_bullet2;
extern SDL_Rect rect_bullet3;
extern SDL_Rect rect_help;
extern SDL_Rect rect_helppage;
extern SDL_Rect rect_score;
extern SDL_Rect rect_shield;
extern SDL_Rect rect_restart;
extern SDL_Rect rect_pork;

extern TTF_Font * font1;
extern TTF_Font * font2;

extern SDL_Color font_color1;
extern SDL_Color font_color2;

extern Mix_Music* mainMusic;
extern Mix_Chunk* peppaHonk;
extern Mix_Chunk* peppaDeathScream;

extern bool running;
extern bool whetherstart;

extern enum GameStatus {
    goHomepage,
    gaming,
    goRestart,
    gameOver
} currentGameStatus;

extern int gameRunning;
extern int life;
extern int lana;
extern int lr;
extern int speed;
extern int generate;
extern int hardness;
extern int isPeppaKneel;
extern int peppaHurt;
extern int isHurt;
extern int isObstacle1;
extern int isObstacle2;
extern int isObstacle3;
extern int isObstacle4;
extern int isObstacle5;
extern int isObstacle6;
extern int isObstacle7;
extern int errorMargin;
extern int generateReward2;
extern int generateReward1;
extern int generateReward3;
extern int generateRewardFrequency;
extern int bullet1out;
extern int bullet2out;
extern int bullet3out;
extern int isInvincible;
extern int score;
extern int score_frequency;
extern int history;
extern char buffer1[10];
extern char buffer2[30];
extern char history_buffer[10];

extern FILE*history_p;
#endif //RUNNINGPEPPA_GLOBAL_H
