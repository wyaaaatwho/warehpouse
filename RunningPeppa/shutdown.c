//
// Created by 26711 on 2023/12/20.
//

#include "shutdown.h"
#include "global.h"

void  shutdown()
{
    //save history
    if(score>history)
    {
        fclose(history_p);
        history_p = fopen("./resource/history.txt", "w");
        sprintf(history_buffer,"%d",score);
        fputs(history_buffer, history_p);
    }
    fclose(history_p);

    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    SDL_DestroyTexture(Start_button_texture);
    SDL_DestroyTexture(Start_button_on_texture);
    SDL_DestroyTexture(peppa_texture);
    SDL_DestroyTexture(peppa_left_texture);
    SDL_DestroyTexture(peppa_right_texture);
    SDL_DestroyTexture(peppa_shoot_texture);
    SDL_DestroyTexture(peppa_kneel_texture);
    SDL_DestroyTexture(name_font_texture);
    SDL_DestroyTexture(difficulty_font_texture1);
    SDL_DestroyTexture(difficulty_font_texture2);
    SDL_DestroyTexture(obstacle1_texture);
    SDL_DestroyTexture(obstacle2_texture);
    SDL_DestroyTexture(obstacle3_texture);
    SDL_DestroyTexture(obstacle4_texture);
    SDL_DestroyTexture(obstacle5_texture);
    SDL_DestroyTexture(obstacle6_texture);
    SDL_DestroyTexture(obstacle7_texture);
    SDL_DestroyTexture(lifeBar1_texture);
    SDL_DestroyTexture(lifeBar2_texture);
    SDL_DestroyTexture(lifeBar3_texture);
    SDL_DestroyTexture(lifeBar4_texture);
    SDL_DestroyTexture(lanaBar_texture);
    SDL_DestroyTexture(lanaFont_texture);
    SDL_DestroyTexture(reward1_texture);
    SDL_DestroyTexture(reward2_texture);
    SDL_DestroyTexture(bullet_texture1);
    SDL_DestroyTexture(bullet_texture2);
    SDL_DestroyTexture(bullet_texture3);
    SDL_DestroyTexture(scoreFontTexture);

    SDL_DestroyRenderer(render1);
    SDL_DestroyWindow(window);

    Mix_HaltMusic();Mix_FreeMusic(mainMusic);
    Mix_FreeChunk(peppaDeathScream);Mix_FreeChunk(peppaHonk);

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
    Mix_Quit();
}