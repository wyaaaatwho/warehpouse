//
// Created by 26711 on 2023/12/21.
//

#include "peppa.h"

void pigpeppa(SDL_Rect *peppaArgue,SDL_Event *peppaMove)
{
    if((*peppaMove).key.keysym.sym==SDLK_UP||(*peppaMove).key.keysym.sym==SDLK_SPACE) // jump
    {
        for(int y=0;y<=70;y++)
        {
            (*peppaArgue).y-=(2+y/70);
            SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
            SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
            SDL_RenderCopy(render1,peppa_texture,NULL,peppaArgue);

            SDL_RenderPresent(render1);
            SDL_RenderPresent(render1);

            SDL_RenderClear(render1);
            SDL_RenderClear(render1);

            rect_background1.x-=speed;
            rect_background2.x-=speed;
            if(rect_background1.x<=-1200)rect_background1.x=1200;
            if(rect_background2.x<=-1200)rect_background2.x=1200;
            SDL_Delay(2);
        }
        for(int t=0;t<15;t++) // floating for 10ms
        {
            SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
            SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
            SDL_RenderCopy(render1,peppa_texture,NULL,peppaArgue);

            SDL_RenderPresent(render1);
            SDL_RenderPresent(render1);

            SDL_RenderClear(render1);
            SDL_RenderClear(render1);

            rect_background1.x-=speed;
            rect_background2.x-=speed;
            if(rect_background1.x<=-1200)rect_background1.x=1200;
            if(rect_background2.x<=-1200)rect_background2.x=1200;
            SDL_Delay(2);
        }
        for(int y=70;y>=0;y--)
        {
            (*peppaArgue).y+=(2+y/70);
            SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
            SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
            SDL_RenderCopy(render1,peppa_texture,NULL,peppaArgue);

            SDL_RenderPresent(render1);
            SDL_RenderPresent(render1);

            SDL_RenderClear(render1);
            SDL_RenderClear(render1);

            rect_background1.x-=speed;
            rect_background2.x-=speed;
            if(rect_background1.x<=-1200)rect_background1.x=1200;
            if(rect_background2.x<=-1200)rect_background2.x=1200;
            SDL_Delay(2);
        }

        SDL_FlushEvent(SDL_KEYDOWN);
    }

    else if((*peppaMove).key.keysym.sym==SDLK_DOWN) // kneel
    {
        bool up=true;
        while(up)
        {

            SDL_PollEvent(peppaMove);
            if((*peppaMove).type==SDL_KEYUP)
            {
                SDL_FlushEvent(SDL_KEYUP);
                up=false;
            }

            SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
            SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
            SDL_RenderCopy(render1,peppa_kneel_texture,NULL,peppaArgue);

            SDL_RenderPresent(render1);
            SDL_RenderPresent(render1);

            SDL_RenderClear(render1);
            SDL_RenderClear(render1);

            rect_background1.x-=speed;
            rect_background2.x-=speed;
            if(rect_background1.x<=-1200)rect_background1.x=1200;
            if(rect_background2.x<=-1200)rect_background2.x=1200;
            SDL_Delay(2);
        }

    }

    else if((*peppaMove).type==SDL_MOUSEBUTTONDOWN) // shoot
    {
        for(int t=0;t<=100;t++)
        {
            SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
            SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
            SDL_RenderCopy(render1,peppa_shoot_texture,NULL,peppaArgue);

            SDL_RenderPresent(render1);
            SDL_RenderPresent(render1);

            SDL_RenderClear(render1);
            SDL_RenderClear(render1);

            rect_background1.x-=speed;
            rect_background2.x-=speed;
            if(rect_background1.x<=-1200)rect_background1.x=1200;
            if(rect_background2.x<=-1200)rect_background2.x=1200;
            SDL_Delay(2);
        }

        SDL_FlushEvent(SDL_MOUSEBUTTONDOWN);
    }

}
