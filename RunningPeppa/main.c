#include "header.h"
#include "global.h"
int main(int argc, char *argv[])
{
    if(initiation()!=0)printf("%s",SDL_GetError()); // initiation

    srand(time(NULL));

    homepage();
    //initiating homepage

    //running
    SDL_Event click;
    while(running)
    {
        //event processing
        while(SDL_PollEvent(&click)!=0)
        {
            if(click.type==SDL_QUIT)running=false; // end the program

            else if (click.type == SDL_KEYDOWN)
            {
                if (click.key.keysym.sym == SDLK_UP || click.key.keysym.sym == SDLK_DOWN||click.key.keysym.sym == SDLK_SPACE)
                {
                    pigpeppa(&rect_peppa, &click);
                }
                else
                {
                    SDL_Keycode keyCode = click.key.keysym.sym;
                    const char* keyName = SDL_GetKeyName(keyCode);
                    printf("invalid click :%s\n",SDL_GetKeyName(keyCode));
                }
            }

            else if (click.type == SDL_MOUSEBUTTONDOWN)
            {
                printf("(%d,%d)",click.button.x,click.button.y);
                pigpeppa(&rect_peppa_shoot, &click);
            }

            SDL_FlushEvent(SDL_KEYDOWN); // avoid any possible bug
            break;
        }

        if(running){ // moving background
            SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
            SDL_RenderCopy(render1, texture2, NULL, &rect_background2);

            if (!peppaHurt) {
                if (lr <= lrNum / 2 && !peppaHurt) {
                    SDL_RenderCopy(render1, peppa_left_texture, NULL, &rect_peppa_left);
                } else if (lr >= lrNum / 2 && !peppaHurt) {
                    SDL_RenderCopy(render1, peppa_right_texture, NULL, &rect_peppa_right);
                }
                lr++;
                if (lr == lrNum) {
                    lr = 0;
                }//moving peppa
            }

            if (peppaHurt) {
                if (lr <= lrNum / 2 && isHurt % 2 == 0) {
                    SDL_RenderCopy(render1, peppa_left_texture, NULL, &rect_peppa_left);
                } else if (lr > lrNum / 2 && isHurt % 2 == 0) {
                    SDL_RenderCopy(render1, peppa_right_texture, NULL, &rect_peppa_right);
                }
                lr++;
                isHurt++;
                if (lr == lrNum) {
                    lr = 0;
                }
                if (isHurt == 500) {
                    isHurt = 0;
                    peppaHurt = 0;
                }
            }
            if(isInvincible)
            {
                isInvincible++;
                if(isInvincible==vincibleTime)
                {
                    isInvincible=0;
                }
                SDL_RenderCopy(render1,shield_texture,NULL,&rect_shield);
            }
            //moving peppa

            obstacleMove(); // obstacle

            statusDisplay();// status bar

            attackMove();// bullet fly

            scoreDisplay();// display score

            SDL_RenderPresent(render1);
            SDL_RenderClear(render1);

            rect_background1.x -= speed;
            rect_background2.x -= speed;
            if (rect_background1.x <= -edge)rect_background1.x = edge;
            if (rect_background2.x <= -edge)rect_background2.x = edge;

            SDL_Delay(2);
        }

    }

    shutdown(); //shutdown the program

}
