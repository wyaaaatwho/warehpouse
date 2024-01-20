//
// Created by 26711 on 2023/12/19.
//

#ifndef RUNNINGPEPPA_HEADER_H
#define RUNNINGPEPPA_HEADER_H
//headers

#include "global.h"

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
SDL_Surface* obstacle1=NULL;
SDL_Surface* obstacle2=NULL;
SDL_Surface* obstacle3=NULL;
SDL_Surface* obstacle4=NULL;
SDL_Surface* obstacle5=NULL;
SDL_Surface* obstacle6=NULL;
SDL_Surface* obstacle7=NULL;
SDL_Surface* lifeBar=NULL;
SDL_Surface* lanaBar=NULL;
SDL_Surface* lanaFont=NULL;
SDL_Surface *reward1=NULL;
SDL_Surface *reward2=NULL;
SDL_Surface *bullet=NULL;
SDL_Surface *helpFont=NULL;
SDL_Surface *scoreFont=NULL;
SDL_Surface *restart=NULL;
SDL_Surface *pork=NULL;

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
SDL_Texture *lifeBar1_texture=NULL;
SDL_Texture *lifeBar2_texture=NULL;
SDL_Texture *lifeBar3_texture=NULL;
SDL_Texture *lifeBar4_texture=NULL;
SDL_Texture *lanaBar_texture=NULL;
SDL_Texture* lanaFont_texture=NULL;
SDL_Texture *reward1_texture=NULL;
SDL_Texture* reward2_texture=NULL;
SDL_Texture* reward3_texture=NULL;
SDL_Texture* bullet_texture1=NULL;
SDL_Texture* bullet_texture2=NULL;
SDL_Texture* bullet_texture3=NULL;
SDL_Texture *scoreFontTexture=NULL;
SDL_Texture *helpFontTexture=NULL;
SDL_Texture *help_page1_texture=NULL;
SDL_Texture *help_page2_texture=NULL;
SDL_Texture *shield_texture=NULL;
SDL_Texture *restart1_texture=NULL;
SDL_Texture *restart2_texture=NULL;
SDL_Texture *pork_texture=NULL;

SDL_Rect rect_background1={.x=0,.y=0};
SDL_Rect rect_background2={.x=1200,.y=0};
SDL_Rect rect_peppa = {.x=200, .y=310};
SDL_Rect rect_peppa_left = {.x=200, .y=310};
SDL_Rect rect_peppa_right = {.x=200, .y=310};
SDL_Rect rect_peppa_shoot = {.x=200, .y=310};
SDL_Rect rect_peppa_kneel = {.x=200, .y=330};
SDL_Rect rect_obstacle1 = {.x=1200, .y=330};
SDL_Rect rect_obstacle2 = {.x=1200, .y=356};
SDL_Rect rect_obstacle3 = {.x=1200, .y=260};
SDL_Rect rect_obstacle4 = {.x=1200, .y=416};
SDL_Rect rect_obstacle5 = {.x=1200, .y=356};
SDL_Rect rect_obstacle6 = {.x=1200, .y=330};
SDL_Rect rect_obstacle7 = {.x=1200, .y=400};
SDL_Rect rect_lifeBar={.x=0, .y=0};
SDL_Rect rect_lanaBar={.x=14, .y=70};
SDL_Rect rect_lanaBar_font={.x=66, .y=70};
SDL_Rect rect_reward1={.x=1200, .y=360};
SDL_Rect rect_reward2={.x=1200, .y=350};
SDL_Rect rect_reward3={.x=1200, .y=350};
SDL_Rect rect_bullet1={.x=240, .y=380};
SDL_Rect rect_bullet2={.x=240, .y=380};
SDL_Rect rect_bullet3={.x=240, .y=380};
SDL_Rect rect_help;
SDL_Rect rect_helppage={.x=-10,.y=0};
SDL_Rect rect_score={.x=780,.y=0,.w=100};
SDL_Rect rect_shield;
SDL_Rect rect_restart;
SDL_Rect rect_pork;

TTF_Font * font1 =NULL;
TTF_Font * font2 =NULL;

SDL_Color font_color1={0x00,0x00,0x00,0x00};
SDL_Color font_color2={0xff,0x00,0x00,0xff};

Mix_Music* mainMusic=NULL;
Mix_Chunk* peppaHonk=NULL;
Mix_Chunk* peppaDeathScream=NULL;

// bool
bool running=true;
bool whetherstart=false;

enum GameStatus currentGameStatus ;

int gameRunning=0;
int life=3;
int lana=3;
int lr=1;
int speed =3;
int generate=0;
int hardness=1;
int isPeppaKneel=0;
int peppaHurt=0;
int isHurt=0;
int isObstacle1=0;
int isObstacle2=0;
int isObstacle3=0;
int isObstacle4=0;
int isObstacle5=0;
int isObstacle6=0;
int isObstacle7=0;
int errorMargin = 10;
int generateReward2=0;
int generateReward1=0;
int generateReward3=0;
int generateRewardFrequency=0;
int bullet1out=0;
int bullet2out=0;
int bullet3out=0;
int isInvincible=0;

int score=0;
int history=0;
int score_frequency=0;

char buffer1[10];
char buffer2[30];
char history_buffer[10];

FILE *history_p=NULL;
#endif //RUNNINGPEPPA_HEADER_H
