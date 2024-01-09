#include "header.h"

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
    SDL_QueryTexture(peppa_left_texture, NULL, NULL, &rect_peppa_left.w, &rect_peppa_left.h);
    SDL_QueryTexture(peppa_right_texture, NULL, NULL, &rect_peppa_right.w, &rect_peppa_right.h);
    SDL_QueryTexture(peppa_shoot_texture, NULL, NULL, &rect_peppa_shoot.w, &rect_peppa_shoot.h);

    //loading obstacle

    SDL_QueryTexture(obstacle1_texture, NULL, NULL, &rect_obstacle1.w, &rect_obstacle1.h);
    SDL_QueryTexture(obstacle2_texture, NULL, NULL, &rect_obstacle2.w, &rect_obstacle2.h);
    SDL_QueryTexture(obstacle3_texture, NULL, NULL, &rect_obstacle3.w, &rect_obstacle3.h);
    SDL_QueryTexture(obstacle4_texture, NULL, NULL, &rect_obstacle4.w, &rect_obstacle4.h);
    SDL_QueryTexture(obstacle5_texture, NULL, NULL, &rect_obstacle5.w, &rect_obstacle5.h);
    SDL_QueryTexture(obstacle6_texture, NULL, NULL, &rect_obstacle6.w, &rect_obstacle6.h);
    SDL_QueryTexture(obstacle7_texture, NULL, NULL, &rect_obstacle7.w, &rect_obstacle7.h);

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

        if(lr<=30)
        {
            SDL_RenderCopy(render1,peppa_left_texture,NULL,&rect_peppa_left);
        }
        else
        {
            SDL_RenderCopy(render1,peppa_right_texture,NULL,&rect_peppa_right);

        }
        lr++;
        if(lr==60)lr=0;//moving peppa

        if(isObstacle1)
        {
            obstacle1Init(&rect_obstacle1);
        }
        if(isObstacle2)
        {
            obstacle2Init(&rect_obstacle2);
        }
        if(isObstacle3)
        {
            obstacle3Init(&rect_obstacle3);
        }
        if(isObstacle4)
        {
            obstacle4Init(&rect_obstacle4);
        }
        if(isObstacle5)
        {
            obstacle5Init(&rect_obstacle5);
        }
        if(isObstacle6)
        {
            obstacle6Init(&rect_obstacle6);
        }
        if(isObstacle7)
        {
            obstacle7Init(&rect_obstacle7);
        }

        SDL_RenderCopy(render1,obstacle1_texture,NULL,&rect_obstacle1);
        SDL_RenderCopy(render1,obstacle2_texture,NULL,&rect_obstacle2);
        SDL_RenderCopy(render1,obstacle3_texture,NULL,&rect_obstacle3);
        SDL_RenderCopy(render1,obstacle4_texture,NULL,&rect_obstacle4);
        SDL_RenderCopy(render1,obstacle5_texture,NULL,&rect_obstacle5);
        SDL_RenderCopy(render1,obstacle6_texture,NULL,&rect_obstacle6);
        SDL_RenderCopy(render1,obstacle7_texture,NULL,&rect_obstacle7);


        SDL_RenderPresent(render1);
        SDL_RenderClear(render1);

        rect_background1.x-=speed;
        rect_background2.x-=speed;
        if(rect_background1.x<=-1200)rect_background1.x=1200;
        if(rect_background2.x<=-1200)rect_background2.x=1200;

        if(generate==0)
        {
            int generate_obstacle = rand()%10+1;
            if (generate_obstacle==1 && !isObstacle1 ) isObstacle1 = 1;
            if (generate_obstacle==2 && !isObstacle2 ) isObstacle2 = 1;
            if (generate_obstacle==3 && !isObstacle3 ) isObstacle3 = 1;
            if (generate_obstacle==4 && !isObstacle4 ) isObstacle4 = 1;
            if (generate_obstacle==5 && !isObstacle5 ) isObstacle5 = 1;
            if (generate_obstacle==6 && !isObstacle6 ) isObstacle6 = 1;
            if (generate_obstacle==7 && !isObstacle7 ) isObstacle7 = 1;
        }
        generate++;
        if(generate==500/hardness){
            generate=0;
        }
        // decide obstacles

        SDL_Delay(2);

    }

    shutdown(); //shutdown the program

}
