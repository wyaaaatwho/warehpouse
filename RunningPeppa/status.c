//
// Created by 26711 on 2024/1/11.
//

#include "status.h"
#include "global.h"

void statusDisplay()
{
    if(life>=Max_Life)
    {
        SDL_RenderCopy(render1,lifeBar1_texture,NULL,&rect_lifeBar);
    }
    else if(life==2)
    {
        SDL_RenderCopy(render1,lifeBar2_texture,NULL,&rect_lifeBar);
    }
    else if(life==1)
    {
        SDL_RenderCopy(render1,lifeBar3_texture,NULL,&rect_lifeBar);
    }
    else if(life<=0)
    {
        SDL_RenderCopy(render1,lifeBar4_texture,NULL,&rect_lifeBar);
    }
    sprintf(buffer1, "X %d", lana);
    lanaFont= TTF_RenderText_Blended(font1, buffer1, font_color1);
    lanaFont_texture= SDL_CreateTextureFromSurface(render1,lanaFont);
    SDL_RenderCopy(render1,lanaBar_texture,NULL,&rect_lanaBar);
    SDL_RenderCopy(render1,lanaFont_texture,NULL,&rect_lanaBar_font);
}

void scoreDisplay()
{
    score_frequency++;
    if(score_frequency==scoreNum/speed)
    {
        score_frequency=0;
        score++;
    }
    sprintf(buffer2, "History %05d Current %05d", history,score);
    scoreFont= TTF_RenderText_Blended(font2, buffer2, font_color1);
    scoreFontTexture= SDL_CreateTextureFromSurface(render1,scoreFont);
    SDL_RenderCopy(render1,scoreFontTexture,NULL,&rect_score);
}
