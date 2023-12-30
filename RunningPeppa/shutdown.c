//
// Created by 26711 on 2023/12/20.
//

#include "shutdown.h"

void  shutdown()
{
    //clear the window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render1);

    SDL_DestroyTexture(Start_button_texture);
    Start_button_texture = NULL;

    SDL_DestroyTexture(Start_button_on_texture);
    Start_button_on_texture = NULL;

    SDL_DestroyTexture(peppa_texture);
    peppa_texture = NULL;

    SDL_DestroyTexture(peppa_left_texture);
    peppa_left_texture = NULL;

    SDL_DestroyTexture(peppa_right_texture);
    peppa_right_texture = NULL;

    SDL_DestroyTexture(peppa_shoot_texture);
    peppa_shoot_texture = NULL;

    SDL_DestroyTexture(peppa_kneel_texture);
    peppa_kneel_texture = NULL;

    SDL_DestroyTexture(difficulty_font_texture1);
    difficulty_font_texture1 = NULL;

    SDL_DestroyTexture(difficulty_font_texture2);
    difficulty_font_texture2 = NULL;

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}