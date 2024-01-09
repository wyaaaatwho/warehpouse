//
// Created by 26711 on 2023/12/20.
//

#ifndef RUNNINGPEPPA_INITIATING_H
#define RUNNINGPEPPA_INITIATING_H
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>


int initiation ();
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
extern SDL_Surface* name_font;
extern SDL_Surface* difficulty_font;
extern SDL_Surface* obstacle;

extern SDL_Renderer* render1;

extern SDL_Texture* texture1;
extern SDL_Texture* texture2;
extern SDL_Texture* Start_button_texture;
extern SDL_Texture *Start_button_on_texture;
extern SDL_Texture* peppa_texture;
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


extern SDL_Rect rect_background1;
extern SDL_Rect rect_background2;

extern TTF_Font* font;
extern SDL_Color font_color1;
extern SDL_Color font_color2;

extern bool running;
extern bool keyIsPressed;

extern int life;
extern int lr;
extern int speed;

#endif //RUNNINGPEPPA_INITIATING_H
