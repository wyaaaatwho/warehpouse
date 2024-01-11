//
// Created by 26711 on 2023/12/21.
//

#include "peppa.h"
#include "status.h"

void pigpeppa(SDL_Rect *peppaArgue,SDL_Event *peppaMove)
{
    if((*peppaMove).key.keysym.sym==SDLK_UP||(*peppaMove).key.keysym.sym==SDLK_SPACE) // jump
    {
        for(int y=0;y<=100;y++)
        {
            (*peppaArgue).y-=(2+y/100);
            SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
            SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
            if(peppaHurt)
            {
                if(isHurt%2==0)
                    SDL_RenderCopy(render1,peppa_texture,NULL,peppaArgue);
                isHurt++;
                if(isHurt==500)
                {
                    isHurt=0;
                    peppaHurt=0;
                }
            }
            else SDL_RenderCopy(render1,peppa_texture,NULL,peppaArgue);

            obstacleMove();
            statusDisplay();// status bar
            attackMove();

            SDL_RenderPresent(render1);
            SDL_RenderClear(render1);

            rect_background1.x-=speed;
            rect_background2.x-=speed;
            if(rect_background1.x<=-1200)rect_background1.x=1200;
            if(rect_background2.x<=-1200)rect_background2.x=1200;
            SDL_Delay(2);
        }
        for(int t=0;t<10;t++) // floating for 10ms
        {
            SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
            SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
            if(peppaHurt)
            {
                if(isHurt%2==0)
                    SDL_RenderCopy(render1,peppa_texture,NULL,peppaArgue);
                isHurt++;if(isHurt==500)
                {
                    isHurt=0;
                    peppaHurt=0;
                }
            }
            else SDL_RenderCopy(render1,peppa_texture,NULL,peppaArgue);

            obstacleMove(); //obstacle
            statusDisplay();// status bar
            attackMove();

            SDL_RenderPresent(render1);
            SDL_RenderClear(render1);

            rect_background1.x-=speed;
            rect_background2.x-=speed;
            if(rect_background1.x<=-1200)rect_background1.x=1200;
            if(rect_background2.x<=-1200)rect_background2.x=1200;
            SDL_Delay(2);
        }
        for(int y=100;y>=0;y--)
        {
            (*peppaArgue).y+=(2+y/100);
            SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
            SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
            if(peppaHurt)
            {
                if(isHurt%2==0)
                    SDL_RenderCopy(render1,peppa_texture,NULL,peppaArgue);
                isHurt++;if(isHurt==500)
                {
                    isHurt=0;
                    peppaHurt=0;
                }
            }
            else SDL_RenderCopy(render1,peppa_texture,NULL,peppaArgue);

            obstacleMove();
            statusDisplay();// status bar
            attackMove();

            SDL_RenderPresent(render1);
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
            isPeppaKneel=1;
            SDL_PollEvent(peppaMove);
            if((*peppaMove).type==SDL_KEYUP)
            {
                SDL_FlushEvent(SDL_KEYUP);
                up=false;
            }

            SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
            SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
            if(peppaHurt)
            {
                if(isHurt%2==0)
                    SDL_RenderCopy(render1,peppa_kneel_texture,NULL,&rect_peppa_kneel);
                isHurt++;if(isHurt==500)
                {
                    isHurt=0;
                    peppaHurt=0;
                }
            }
            else SDL_RenderCopy(render1,peppa_kneel_texture,NULL,&rect_peppa_kneel);

            obstacleMove();
            statusDisplay();// status bar
            attackMove();

            SDL_RenderPresent(render1);
            SDL_RenderClear(render1);

            rect_background1.x-=speed;
            rect_background2.x-=speed;
            if(rect_background1.x<=-1200)rect_background1.x=1200;
            if(rect_background2.x<=-1200)rect_background2.x=1200;
            SDL_Delay(2);
        }

        isPeppaKneel=0;
    }

    else if((*peppaMove).type==SDL_MOUSEBUTTONDOWN) // shoot
    {
        if(lana>0){
            if (!bullet1out) {
                bullet1out = 1;
                lana--;
            }
            else {
                if (!bullet2out) {
                    bullet2out = 1;
                    lana--;
                }
                else {
                    if (!bullet3out) {
                        bullet3out = 1;
                        lana--;
                    }
                }
            }
        }

        for(int t=0;t<=100;t++)
        {
            SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
            SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
            if(peppaHurt)
            {
                if(isHurt%2==0)
                    SDL_RenderCopy(render1,peppa_shoot_texture,NULL,peppaArgue);
                isHurt++;if(isHurt==500)
                {
                    isHurt=0;
                    peppaHurt=0;
                }
            }
            else SDL_RenderCopy(render1,peppa_shoot_texture,NULL,peppaArgue);

            obstacleMove();
            statusDisplay();// status bar
            attackMove();

            SDL_RenderPresent(render1);
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
