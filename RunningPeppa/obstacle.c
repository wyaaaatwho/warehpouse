//
// Created by 26711 on 2024/1/5.
//

#include "obstacle.h"
#include "global.h"

bool collide(SDL_Rect *rect1) {

    if (isPeppaKneel) {
        return (
                rect1->x < rect_peppa_kneel.x + rect_peppa_kneel.w &&
                rect1->x + rect1->w > rect_peppa_kneel.x &&
                rect1->y < rect_peppa_kneel.y + rect_peppa_kneel.h &&
                rect1->y + rect1->h > rect_peppa_kneel.y &&
                (rect1->x + rect1->w - errorMargin) > rect_peppa_kneel.x &&
                (rect_peppa_kneel.x + rect_peppa_kneel.w - errorMargin) > rect1->x &&
                (rect1->y + rect1->h - errorMargin) > rect_peppa_kneel.y &&
                (rect_peppa_kneel.y + rect_peppa_kneel.h - errorMargin) > rect1->y
        );
    } else {
        return (
                rect1->x < rect_peppa.x + rect_peppa.w &&
                rect1->x + rect1->w > rect_peppa.x &&
                rect1->y < rect_peppa.y + rect_peppa.h &&
                rect1->y + rect1->h > rect_peppa.y &&
                (rect1->x + rect1->w - errorMargin) > rect_peppa.x &&
                (rect_peppa.x + rect_peppa.w - errorMargin) > rect1->x &&
                (rect1->y + rect1->h - errorMargin) > rect_peppa.y &&
                (rect_peppa.y + rect_peppa.h - errorMargin) > rect1->y
        );
    }
}

void obstacleInit(SDL_Rect *obstacleArgue,int *num,int index)
{
    obstacleArgue->x-=speed;
    if((index==1||index==2||index==5||index==6)&&destroyObstacle(obstacleArgue))
    {
        *num = 0;
        score+=scoreNum;
        obstacleArgue->x = edge;
    }
    if (collide(obstacleArgue)&&!isInvincible)
    {
        Mix_PlayChannel(1, peppaDeathScream, 0);

            *num = 0;
            peppaHurt = 1;
            isHurt = 0;
            obstacleArgue->x = edge;
            life--;
            if (score <= scoreNum)
                score -= score;
            else score -= scoreNum;
    }
    if(isInvincible&&obstacleArgue->x<=rect_shield.x+rect_shield.w)
    {
        *num=0;
        score+=100;
        obstacleArgue->x=edge;
    }
    if(obstacleArgue->x<=-obstacleArgue->w)
    {
        *num=0;
        obstacleArgue->x=edge;
    }
}

void rewardInit(SDL_Rect *rewardArgue,int *num,int index)
{
    rewardArgue->x-=speed;
    if (collide(rewardArgue))
    {
        *num = 0;
        if(index==1)
        {
            if(life<3)life++;
        }
        else if(index==2)
        {
            lana+=2;
        }
        else if(index==3)
        {
            isInvincible=1;
        }
        rewardArgue->x = edge;
    }
    if(rewardArgue->x<=-rewardArgue->w)
    {
        *num=0;
        rewardArgue->x=edge;
    }
}

void obstacleMove()
{
    if(isObstacle1)
    {
        obstacleInit(&rect_obstacle1,&isObstacle1,1);
    }
    if(isObstacle2)
    {
        obstacleInit(&rect_obstacle2,&isObstacle2,2);
    }
    if(isObstacle3)
    {
        obstacleInit(&rect_obstacle3,&isObstacle3,3);
    }
    if(isObstacle4)
    {
        obstacleInit(&rect_obstacle4,&isObstacle4,4);
    }
    if(isObstacle5)
    {
        obstacleInit(&rect_obstacle5,&isObstacle5,5);
    }
    if(isObstacle6)
    {
        obstacleInit(&rect_obstacle6,&isObstacle6,6);
    }
    if(isObstacle7)
    {
        obstacleInit(&rect_obstacle7,&isObstacle7,7);
    }
    if(generateReward1)
    {
        rewardInit(&rect_reward1,&generateReward1,1);
    }
    if(generateReward2)
    {
        rewardInit(&rect_reward2,&generateReward2,2);
    }
    if(generateReward3)
    {
        rewardInit(&rect_reward3,&generateReward3,3);
    }
    SDL_RenderCopy(render1,obstacle1_texture,NULL,&rect_obstacle1);
    SDL_RenderCopy(render1,obstacle2_texture,NULL,&rect_obstacle2);
    SDL_RenderCopy(render1,obstacle3_texture,NULL,&rect_obstacle3);
    SDL_RenderCopy(render1,obstacle4_texture,NULL,&rect_obstacle4);
    SDL_RenderCopy(render1,obstacle5_texture,NULL,&rect_obstacle5);
    SDL_RenderCopy(render1,obstacle6_texture,NULL,&rect_obstacle6);
    SDL_RenderCopy(render1,obstacle7_texture,NULL,&rect_obstacle7);
    SDL_RenderCopy(render1,reward1_texture,NULL,&rect_reward1);
    SDL_RenderCopy(render1,reward2_texture,NULL,&rect_reward2);
    SDL_RenderCopy(render1,reward3_texture,NULL,&rect_reward3);

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
        if(generateRewardFrequency==0)
        {
            if (generate_obstacle==8&&!generateReward1) generateReward1= 1;
            if (generate_obstacle==9&&!generateReward2) generateReward2= 1;
            if (generate_obstacle==10&&!generateReward3) generateReward3= 1;
        }
    }
    generate++;
    if(generate==obstacleGenerateNum/(hardness)){
        generate=0;
    }

    generateRewardFrequency++;
    if(generateRewardFrequency==rewardGenerateNum){
        generateRewardFrequency=0;
    }
}

void attackMove()
{
    if(bullet1out)
    {
        rect_bullet1.x+=bulletSpeed;
        SDL_RenderCopy(render1,bullet_texture1,NULL,&rect_bullet1);
        if(rect_bullet1.x>=edge)
        {
            rect_bullet1.x=gunXray;
            bullet1out=0;
        }
    }
    if(bullet2out)
    {
        rect_bullet2.x+=bulletSpeed;
        SDL_RenderCopy(render1,bullet_texture2,NULL,&rect_bullet2);
        if(rect_bullet2.x>=edge)
        {
            rect_bullet2.x=gunXray;
            bullet2out=0;
        }
    }
    if(bullet3out)
    {
        rect_bullet3.x+=bulletSpeed;
        SDL_RenderCopy(render1,bullet_texture3,NULL,&rect_bullet3);
        if(rect_bullet3.x>=edge)
        {
            rect_bullet3.x=gunXray;
            bullet3out=0;
        }
    }
}

bool destroyObstacle(SDL_Rect *rect1)
{
    if(bullet1out)
    {
        if(rect_bullet1.x+rect_bullet1.w>=rect1->x)
        {
            bullet1out=0;
            rect_bullet1.x=gunXray;
            return true;
        }
    }
    if(bullet2out)
    {
        if(rect_bullet2.x+rect_bullet2.w>=rect1->x)
        {
            bullet2out=0;
            rect_bullet2.x=gunXray;
            return true;
        }
    }
    if(bullet3out)
    {
        if(rect_bullet3.x+rect_bullet3.w>=rect1->x)
        {
            bullet3out=0;
            rect_bullet3.x=gunXray;
            return true;
        }
    }
    return false;
}
