//
// Created by 26711 on 2023/12/21.
//

#include "peppa.h"

void pigpeppa(SDL_Rect *peppaArgue,SDL_Event *peppaMove)
{
    if((*peppaMove).key.keysym.sym==SDLK_UP||(*peppaMove).key.keysym.sym==SDLK_SPACE) // jump
    {
        for(int y=0;y<=100;y++)
        {
            (*peppaArgue).y-=(2+y/100);
            SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
            SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
            SDL_RenderCopy(render1,peppa_texture,NULL,peppaArgue);

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
            SDL_RenderCopy(render1,peppa_texture,NULL,peppaArgue);

            //obstacle
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
            SDL_RenderCopy(render1,peppa_texture,NULL,peppaArgue);

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

            SDL_PollEvent(peppaMove);
            if((*peppaMove).type==SDL_KEYUP)
            {
                SDL_FlushEvent(SDL_KEYUP);
                up=false;
            }

            SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
            SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
            SDL_RenderCopy(render1,peppa_kneel_texture,NULL,peppaArgue);

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
