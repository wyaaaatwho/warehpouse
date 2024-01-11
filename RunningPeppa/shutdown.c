//
// Created by 26711 on 2023/12/20.
//

#include "shutdown.h"

void  shutdown()
{
    //clear the window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render1);

    // destroy surface
    SDL_FreeSurface(backGround1);
    SDL_FreeSurface(backGround2);
    SDL_FreeSurface(Start_button);
    SDL_FreeSurface(Start_button_on);
    SDL_FreeSurface(peppa);
    SDL_FreeSurface(peppa_left);
    SDL_FreeSurface(peppa_right);
    SDL_FreeSurface(peppa_shoot);
    SDL_FreeSurface(peppa_kneel);
    SDL_FreeSurface(name_font);
    SDL_FreeSurface(difficulty_font);

    // destroy texture
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