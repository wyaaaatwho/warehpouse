//
// Created by 26711 on 2023/12/21.
//

#include "peppa.h"
#include "global.h"
void peppaDisplay(SDL_Rect *pigRect,SDL_Texture *pigTexture)
{
    moveBackground();

    if(peppaHurt)
    {
        if(isHurt%2==0)
            SDL_RenderCopy(render1,pigTexture,NULL,pigRect);
        isHurt++;
        if(isHurt==hurtTime )
        {
            isHurt=0;
            peppaHurt=0;
        }
    }
    else SDL_RenderCopy(render1,pigTexture,NULL,pigRect);

    if(isInvincible)
    {
        isInvincible++;
        if(isInvincible==vincibleTime)
        {
            isInvincible=0;
        }
        SDL_RenderCopy(render1,shield_texture,NULL,&rect_shield);
    }

    obstacleMove();
    statusDisplay();// status bar
    attackMove();
    scoreDisplay();
}
void pigpeppa(SDL_Rect *peppaArgue,SDL_Event *peppaMove)
{
    if((*peppaMove).key.keysym.sym==SDLK_UP||(*peppaMove).key.keysym.sym==SDLK_SPACE) // jump
    {
        Mix_PlayChannel(0, peppaHonk, 0);

        for(int y=0;y<=100;y++)
        {
            (*peppaArgue).y-=(2+y/100);
            rect_shield.y-=(2+y/100);
            peppaDisplay(peppaArgue,peppa_texture);
            SDL_RenderPresent(render1);
            SDL_RenderClear(render1);
            SDL_Delay(DELAY_TIME);
        }
        for(int t=0;t<10;t++) // floating for 10ms
        {
            peppaDisplay(peppaArgue,peppa_texture);
            SDL_RenderPresent(render1);
            SDL_RenderClear(render1);
            SDL_Delay(DELAY_TIME);
        }
        for(int y=100;y>=0;y--)
        {
            (*peppaArgue).y+=(2+y/100);
            rect_shield.y+=(2+y/100);
            peppaDisplay(peppaArgue,peppa_texture);
            SDL_RenderPresent(render1);
            SDL_RenderClear(render1);
            SDL_Delay(DELAY_TIME);
        }

        SDL_FlushEvent(SDL_KEYDOWN);
    }

    else if((*peppaMove).key.keysym.sym==SDLK_DOWN) // kneel
    {
        Mix_PlayChannel(0, peppaHonk, 0);

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

            peppaDisplay(&rect_peppa_kneel,peppa_kneel_texture);
            SDL_RenderPresent(render1);
            SDL_RenderClear(render1);
            SDL_Delay(DELAY_TIME);
        }

        isPeppaKneel=0;
    }

    else if((*peppaMove).type==SDL_MOUSEBUTTONDOWN) // shoot
    {
        Mix_PlayChannel(0, peppaHonk, 0);

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
            peppaDisplay(peppaArgue,peppa_shoot_texture);

            SDL_RenderPresent(render1);
            SDL_RenderClear(render1);
            SDL_Delay(DELAY_TIME);
        }

        SDL_FlushEvent(SDL_MOUSEBUTTONDOWN);
    }
}

void peppaNormalDisplay()
{
    if (!peppaHurt || (peppaHurt && isHurt % 2 == 0)) {
        if (lr <= lrNum / 2) {
            SDL_RenderCopy(render1, peppa_left_texture, NULL, &rect_peppa_left);
        } else {
            SDL_RenderCopy(render1, peppa_right_texture, NULL, &rect_peppa_right);
        }

        lr++;
        if (lr == lrNum) {
            lr = 0;
        }
    }

    if (peppaHurt) {
        isHurt++;
        if (isHurt == hurtTime) {
            isHurt = 0;
            peppaHurt = 0;
        }
    }

    if (isInvincible)
    {
        isInvincible++;
        if (isInvincible == vincibleTime)
        {
            isInvincible = 0;
        }
        SDL_RenderCopy(render1, shield_texture, NULL, &rect_shield);
    }
}

void peppaDeathDisplay()
{

    for(rect_pork.y = rect_peppa.y;rect_pork.y+rect_pork.h<ground;rect_pork.y+=1)
    {
        SDL_RenderClear(render1);

        moveBackground();// moving background
        obstacleMove(); // obstacle
        statusDisplay();// status bar
        attackMove();// bullet fly
        scoreDisplay();// display score

        SDL_QueryTexture(pork_texture, NULL, NULL, &rect_pork.w, &rect_pork.h);
        rect_pork.x = rect_peppa.x;
        SDL_RenderCopy(render1, pork_texture, NULL, &rect_pork);
        SDL_RenderPresent(render1);
        SDL_Delay(DELAY_TIME);
    }

}