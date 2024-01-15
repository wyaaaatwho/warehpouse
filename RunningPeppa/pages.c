//
// Created by 26711 on 2023/12/21.
//

#include "pages.h"
#include "global.h"
void homepage ()
{
    SDL_Rect Rec_Start_button={.y=200};
    SDL_Rect Rec_Start_button_on={.y=200};
    SDL_Rect Rec_name_font={.y=100};
    SDL_Rect Rec_font1={.y=414};
    SDL_Rect Rec_font2={.y=414};
    rect_help.y=350;
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
    rect_help.x=edge/2-(rect_help.w/2)+2;

    SDL_RenderCopy(render1,  Start_button_texture, NULL, &Rec_Start_button);
    SDL_RenderCopy(render1, difficulty_font_texture1, NULL, &Rec_font1);
    SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
    SDL_RenderCopy(render1, helpFontTexture, NULL, &rect_help);
    SDL_RenderPresent(render1);

    SDL_Event start;
    whetherstart=false;
    bool on=false;
    while(!whetherstart)
    {
            SDL_RenderClear(render1);
            SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
            SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
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

            rect_background1.x-=1;
            rect_background2.x-=1;
            if(rect_background1.x<=-edge)rect_background1.x=edge;
            if(rect_background2.x<=-edge)rect_background2.x=edge;
            SDL_RenderPresent(render1);
            SDL_Delay(3);

        while(SDL_PollEvent(&start)!=0)
        {
            if(start.type==SDL_QUIT)
            {
                whetherstart=true;
                running=false;
                // end the program
            }
            // start button
            else if(start.button.x>=Rec_Start_button.x&&start.button.x<=Rec_Start_button.x+Rec_Start_button.w&&start.button.y>=Rec_Start_button.y&&start.button.y<=338)
            {
                on =true;

                SDL_RenderClear(render1);
                SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
                SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
                rect_background1.x-=1;
                rect_background2.x-=1;
                if(rect_background1.x<=-edge)rect_background1.x=edge;
                if(rect_background2.x<=-edge)rect_background2.x=edge;

                if(start.type==SDL_MOUSEBUTTONDOWN)
                {
                    whetherstart=true;
                    break;
                }
                else
                {
                    if(speed==speed1)
                    {
                        SDL_RenderCopy(render1, Start_button_on_texture, NULL, &Rec_Start_button_on);
                        SDL_RenderCopy(render1, difficulty_font_texture1, NULL, &Rec_font1);
                        SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
                        SDL_RenderCopy(render1, helpFontTexture, NULL, &rect_help);
                        SDL_RenderPresent(render1);
                        SDL_Delay(3);
                    }
                    else
                    {
                        SDL_RenderCopy(render1,  Start_button_on_texture, NULL, &Rec_Start_button_on);
                        SDL_RenderCopy(render1, difficulty_font_texture2, NULL, &Rec_font1);
                        SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
                        SDL_RenderCopy(render1, helpFontTexture, NULL, &rect_help);
                        SDL_RenderPresent(render1);
                        SDL_Delay(3);
                    }
                }
            }
            // choose difficulty
            else if (((start.button.x>=462&&start.button.x<=534)||(start.button.x>=670&&start.button.x<=742))&&(start.button.y>=440&&start.button.y<=490))
            {
                SDL_RenderClear(render1);
                SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
                SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
                if(rect_background2.x<=-edge)rect_background2.x=edge;
                if(start.type==SDL_MOUSEBUTTONDOWN)
                {
                    if(hardness==1)
                    {
                        SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
                        SDL_RenderCopy(render1,  Start_button_texture, NULL, &Rec_Start_button);
                        SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
                        SDL_RenderCopy(render1, difficulty_font_texture2, NULL, &Rec_font1);
                        SDL_RenderCopy(render1, helpFontTexture, NULL, &rect_help);
                        SDL_RenderPresent(render1);
                        speed=speed2;
                        hardness=2;
                    }
                    else
                    {
                        SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
                        SDL_RenderCopy(render1,  Start_button_texture, NULL, &Rec_Start_button);
                        SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
                        SDL_RenderCopy(render1, difficulty_font_texture1, NULL, &Rec_font1);
                        SDL_RenderCopy(render1, helpFontTexture, NULL, &rect_help);
                        SDL_RenderPresent(render1);
                        speed=speed1;
                        hardness=1;
                    }
                }
            }
            // help page
            else if(start.button.x>=rect_help.x&&start.button.x<=rect_help.x+rect_help.w&&start.button.y>=rect_help.y&&start.button.y<=rect_help.y+rect_help.h)
            {
                SDL_RenderClear(render1);
                SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
                SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
                if(rect_background2.x<=-edge)rect_background2.x=edge;
                if(start.type==SDL_MOUSEBUTTONDOWN)
                {
                    helpPage();
                }
                else
                {
                    if(hardness==1)
                    {
                        SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
                        SDL_RenderCopy(render1,  Start_button_texture, NULL, &Rec_Start_button);
                        SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
                        SDL_RenderCopy(render1, difficulty_font_texture2, NULL, &Rec_font1);
                        SDL_RenderCopy(render1, helpFontTexture, NULL, &rect_help);
                        SDL_RenderPresent(render1);
                    }
                    else
                    {
                        SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
                        SDL_RenderCopy(render1,  Start_button_texture, NULL, &Rec_Start_button);
                        SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
                        SDL_RenderCopy(render1, difficulty_font_texture1, NULL, &Rec_font1);
                        SDL_RenderCopy(render1, helpFontTexture, NULL, &rect_help);
                        SDL_RenderPresent(render1);
                    }
                }
            }
            else
            {
                on=false;

                SDL_RenderClear(render1);
                SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
                SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
                rect_background1.x-=1;
                rect_background2.x-=1;
                if(rect_background1.x<=-edge)rect_background1.x=edge;
                if(rect_background2.x<=-edge)rect_background2.x=edge;

                if(hardness==1)
                {

                    SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
                    SDL_RenderCopy(render1,  Start_button_texture, NULL, &Rec_Start_button);
                    SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
                    SDL_RenderCopy(render1, difficulty_font_texture1, NULL, &Rec_font1);
                    SDL_RenderCopy(render1, helpFontTexture, NULL, &rect_help);
                    SDL_RenderPresent(render1);
                    SDL_Delay(3);
                }
                else
                {

                    SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
                    SDL_RenderCopy(render1,  Start_button_texture, NULL, &Rec_Start_button);
                    SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
                    SDL_RenderCopy(render1, difficulty_font_texture2, NULL, &Rec_font2);
                    SDL_RenderCopy(render1, helpFontTexture, NULL, &rect_help);
                    SDL_RenderPresent(render1);
                    SDL_Delay(3);
                }
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
    while(helping)
    {
        SDL_Event mouse;
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
                    SDL_RenderPresent(render1);
                }
            }
            else
            {
                SDL_RenderClear(render1);
                SDL_QueryTexture(help_page1_texture,NULL,NULL,&rect_helppage.w,&rect_helppage.h);
                SDL_RenderCopy(render1,help_page1_texture,NULL,&rect_helppage);
                SDL_RenderPresent(render1);

            }
        }
    }
}