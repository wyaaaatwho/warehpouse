#include "header.h"
#include "status.h"

int main(int argc, char *argv[])
{

    if(initiation()!=0)printf("%s",SDL_GetError()); // initiation

    srand(time(NULL));

    // loading texture
    SDL_QueryTexture(texture1, NULL, NULL, &rect_background1.w, &rect_background1.h);
    SDL_QueryTexture(texture2, NULL, NULL, &rect_background2.w, &rect_background2.h);

    SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
    SDL_RenderPresent(render1);  // background

    //loading peppa
    SDL_QueryTexture(peppa_texture, NULL, NULL, &rect_peppa.w, &rect_peppa.h);
    SDL_QueryTexture(peppa_kneel_texture, NULL, NULL, &rect_peppa_kneel.w, &rect_peppa_kneel.h);
    SDL_QueryTexture(peppa_left_texture, NULL, NULL, &rect_peppa_left.w, &rect_peppa_left.h);
    SDL_QueryTexture(peppa_right_texture, NULL, NULL, &rect_peppa_right.w, &rect_peppa_right.h);
    SDL_QueryTexture(peppa_shoot_texture, NULL, NULL, &rect_peppa_shoot.w, &rect_peppa_shoot.h);

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

        // moving background
        SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
        SDL_RenderCopy(render1,texture2,NULL,&rect_background2);

        if(!peppaHurt) {
            if (lr <= 30 && !peppaHurt) {
                SDL_RenderCopy(render1, peppa_left_texture, NULL, &rect_peppa_left);
            } else if (lr >= 30 && !peppaHurt) {
                SDL_RenderCopy(render1, peppa_right_texture, NULL, &rect_peppa_right);

            }
            lr++;
            if(lr==60)lr=0;//moving peppa
        }

        if(peppaHurt)
        {
            if(lr<=30&&isHurt%2==0)
            {
                SDL_RenderCopy(render1,peppa_left_texture,NULL,&rect_peppa_left);
            }
            else if(lr>30&&isHurt%2==0)
            {
                SDL_RenderCopy(render1,peppa_right_texture,NULL,&rect_peppa_right);
            }
            lr++;
            isHurt++;
            if(lr==60)lr=0;
            if(isHurt==500)
            {
                isHurt=0;
                peppaHurt=0;
            }
        } //moving peppa

        obstacleMove(); // obstacle

        statusDisplay();// status bar

        attackMove();// bullet fly

        SDL_RenderPresent(render1);
        SDL_RenderClear(render1);

        rect_background1.x-=speed;
        rect_background2.x-=speed;
        if(rect_background1.x<=-1200)rect_background1.x=1200;
        if(rect_background2.x<=-1200)rect_background2.x=1200;

        // decide obstacles

        SDL_Delay(2);

    }

    shutdown(); //shutdown the program

}
