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

    SDL_FreeSurface(backGround1);
    SDL_FreeSurface(backGround2);
    SDL_FreeSurface(peppa);
    SDL_FreeSurface(peppa_left);
    SDL_FreeSurface(peppa_right);
    SDL_FreeSurface(peppa_shoot);
    SDL_FreeSurface(peppa_kneel);
    SDL_FreeSurface(Start_button);
    SDL_FreeSurface(Start_button_on);
    SDL_FreeSurface(difficulty_font);
    SDL_FreeSurface(name_font);
    SDL_FreeSurface(obstacle1);
    SDL_FreeSurface(obstacle2);
    SDL_FreeSurface(obstacle3);
    SDL_FreeSurface(obstacle4);
    SDL_FreeSurface(obstacle5);
    SDL_FreeSurface(obstacle6);
    SDL_FreeSurface(obstacle7);
    SDL_FreeSurface(lifeBar);
    SDL_FreeSurface(lanaBar);
    SDL_FreeSurface(lanaFont);
    SDL_FreeSurface(reward1);
    SDL_FreeSurface(reward2);
    SDL_FreeSurface(bullet);
    SDL_FreeSurface(scoreFont);

    SDL_DestroyRenderer(render1);
    SDL_DestroyWindow(window);

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}