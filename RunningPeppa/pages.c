//
// Created by 26711 on 2023/12/21.
//

#include "pages.h"
#include "global.h"
void moveBackground()
{
    SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
    SDL_RenderCopy(render1, texture2, NULL, &rect_background2);
    rect_background1.x -= speed;
    rect_background2.x -= speed;
    if (rect_background1.x <= -edge)rect_background1.x = edge;
    if (rect_background2.x <= -edge)rect_background2.x = edge;
}
void homepage ()
{
    SDL_Rect Rec_Start_button={.y=200};
    SDL_Rect Rec_Start_button_on={.y=200};
    SDL_Rect Rec_name_font={.y=100};
    SDL_Rect Rec_font1={.y=414};
    SDL_Rect Rec_font2={.y=414};
    rect_help.y=350; //locating

    SDL_QueryTexture(Start_button_texture,NULL,NULL,&Rec_Start_button.w,&Rec_Start_button.h);
    SDL_QueryTexture(Start_button_on_texture,NULL,NULL,&Rec_Start_button_on.w,&Rec_Start_button_on.h);
    SDL_QueryTexture(name_font_texture,NULL,NULL,&Rec_name_font.w,&Rec_name_font.h);
    SDL_QueryTexture(difficulty_font_texture1,NULL,NULL,&Rec_font1.w,&Rec_font1.h);
    SDL_QueryTexture(difficulty_font_texture2,NULL,NULL,&Rec_font2.w,&Rec_font2.h);
    SDL_QueryTexture(helpFontTexture,NULL,NULL,&rect_help.w,&rect_help.h);

    Rec_Start_button.x=edge/2-(Rec_Start_button.w/2);
    Rec_Start_button_on.x=edge/2-(Rec_Start_button_on.w/2);
    Rec_name_font.x=edge/2-(Rec_name_font.w/2);
    Rec_font1.x=edge/2-(Rec_font1.w/2)+2;
    Rec_font2.x=edge/2-(Rec_font2.w/2)+2;
    rect_help.x=edge/2-(rect_help.w/2)+2; // decide location

    SDL_Event start;
    whetherstart=false;
    bool on=false;
    while(!whetherstart)
    {
            SDL_RenderClear(render1);
            moveBackground();
            if(on)
                SDL_RenderCopy(render1,  Start_button_on_texture, NULL, &Rec_Start_button_on);
            else
                SDL_RenderCopy(render1,  Start_button_texture, NULL, &Rec_Start_button);
            if(speed==speed1)
                SDL_RenderCopy(render1, difficulty_font_texture1, NULL, &Rec_font1);
            else
                SDL_RenderCopy(render1, difficulty_font_texture2, NULL, &Rec_font2);
            SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
            SDL_RenderCopy(render1, helpFontTexture, NULL, &rect_help);

            SDL_RenderPresent(render1);
            SDL_Delay(DELAY_TIME);

        while(SDL_PollEvent(&start)!=0)
        {
            if(start.type==SDL_QUIT)
            {
                whetherstart=true;
                gameRunning=0;
                running=false;
                currentGameStatus=gameOver;
                // end the program
            }
            // start button
            else if(start.button.x>=Rec_Start_button.x&&start.button.x<=Rec_Start_button.x+Rec_Start_button.w&&start.button.y>=Rec_Start_button.y&&start.button.y<=338)
            {
                on =true;

                if(start.type==SDL_MOUSEBUTTONDOWN)
                {
                    whetherstart=true;
                    currentGameStatus=gaming;
                    Initiate();
                    break;
                }
            }
            // choose difficulty
            else if (((start.button.x>=462&&start.button.x<=534)||(start.button.x>=670&&start.button.x<=742))&&(start.button.y>=440&&start.button.y<=490))
            {
                on =false;

                if(start.type==SDL_MOUSEBUTTONDOWN)
                {
                    if(hardness==1)
                    {
                        speed=speed2;
                        hardness=2;
                    }
                    else
                    {
                        speed=speed1;
                        hardness=1;
                    }
                }
            }
            // help page
            else if(start.button.x>=rect_help.x&&start.button.x<=rect_help.x+rect_help.w&&start.button.y>=rect_help.y&&start.button.y<=rect_help.y+rect_help.h)
            {
                on =false;

                if(start.type==SDL_MOUSEBUTTONDOWN)
                {
                    helpPage();
                }
            }

            else{
                on =false;
            }
        }
    }

}
void helpPage()
{
    bool helping=true;
    bool on=false;
    SDL_RenderClear(render1);
    SDL_QueryTexture(help_page1_texture,NULL,NULL,&rect_helppage.w,&rect_helppage.h);
    SDL_RenderCopy(render1,help_page1_texture,NULL,&rect_helppage);
    SDL_RenderPresent(render1);
    SDL_Event mouse;

    while(helping)
    {
        while(SDL_PollEvent(&mouse)!=0)
        {
            if(mouse.type==SDL_QUIT)
            {
                helping=false;
                whetherstart=true;
                running=false;
                // end the program
            }
            if(mouse.button.x<=276&&mouse.button.x>=30&&mouse.button.y>=478&&mouse.button.y<=600)
            {
                on=true;
                if(mouse.type==SDL_MOUSEBUTTONDOWN)
                {
                    helping=false;
                    break;
                }
                else
                {
                    SDL_RenderClear(render1);
                    SDL_QueryTexture(help_page2_texture,NULL,NULL,&rect_helppage.w,&rect_helppage.h);
                    SDL_RenderCopy(render1,help_page2_texture,NULL,&rect_helppage);
                }
            }
            else
            {
                SDL_RenderClear(render1);
                SDL_QueryTexture(help_page1_texture,NULL,NULL,&rect_helppage.w,&rect_helppage.h);
                SDL_RenderCopy(render1,help_page1_texture,NULL,&rect_helppage);

            }
            SDL_RenderPresent(render1);
        }
    }
}
void restartPage()
{
    SDL_Event whetherRestart;
    bool restartNow=false;
    bool on=false;

    while(!restartNow)
    {
        SDL_RenderClear(render1);
        moveBackground();
        if(!on) {
            SDL_QueryTexture(restart1_texture, NULL, NULL, &rect_restart.w, &rect_restart.h);
            SDL_RenderCopy(render1, restart1_texture, NULL, &rect_restart);
        }
        else {
            SDL_QueryTexture(restart2_texture, NULL, NULL, &rect_restart.w, &rect_restart.h);
            SDL_RenderCopy(render1, restart2_texture, NULL, &rect_restart);
        }

        while(SDL_PollEvent(&whetherRestart)!=0)
        {
            if(whetherRestart.type==SDL_QUIT)
            {
                restartNow=true;
                gameRunning=0;
                running=false;
                currentGameStatus=gameOver;

                // end the program
            }

            //restart
            else if(whetherRestart.button.x<=rect_restart.x+rect_restart.w
            &&whetherRestart.button.x>=rect_restart.x&&whetherRestart.button.y>=rect_restart.y
            &&whetherRestart.button.y<=rect_restart.y+116)
            {
                on=true;
                if(whetherRestart.type==SDL_MOUSEBUTTONDOWN)
                {
                    whetherstart=true;
                    currentGameStatus=gaming;
                    Initiate();
                    return;
                }
            }

            //homepage
            else if(whetherRestart.button.x<=700
                    &&whetherRestart.button.x>=490&&whetherRestart.button.y>=350
                    &&whetherRestart.button.y<=400)
            {
                on=false;
                if(whetherRestart.type==SDL_MOUSEBUTTONDOWN)
                {
                    whetherstart=true;
                    currentGameStatus=goHomepage;
                    return;
                }
            }
            else{
                on=false;
            }
        }

        SDL_Delay(2);
        SDL_RenderPresent(render1);
    }
}

void Initiate()
{
    running=true;life=Max_Life;lana=Max_lana;isPeppaKneel=0;peppaHurt=0;
    isHurt=0;isObstacle1=0;isObstacle2=0;isObstacle3=0;isObstacle4=0;
    isObstacle5=0;isObstacle6=0;isObstacle7=0;generate=0;
    generateReward1=0;generateReward2=0;generateReward3=0;generateRewardFrequency=0;
    bullet1out=0;bullet2out=0;bullet3out=0;isInvincible=0;
    history=history>score?history:score;score=0;
    rect_obstacle1.x=edge;rect_obstacle2.x=edge;rect_obstacle3.x=edge;
    rect_obstacle4.x=edge;rect_obstacle5.x=edge;rect_obstacle6.x=edge;
    rect_obstacle7.x=edge;rect_reward1.x=edge;rect_reward2.x=edge;rect_reward3.x=edge;
    rect_bullet1.x=240;rect_bullet2.x=240;rect_bullet3.x=240;

}