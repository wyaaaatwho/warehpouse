//
// Created by 26711 on 2024/1/11.
//

#include "status.h"

void statusDisplay()
{
    if(life>=3)
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
    sprintf(buffer, "X %d", lana);
    lanaFont= TTF_RenderText_Blended(font, buffer, font_color1);
    lanaFont_texture= SDL_CreateTextureFromSurface(render1,lanaFont);
    SDL_RenderCopy(render1,lanaBar_texture,NULL,&rect_lanaBar);
    SDL_RenderCopy(render1,lanaFont_texture,NULL,&rect_lanaBar_font);
}

void scoreCount()
{

}
