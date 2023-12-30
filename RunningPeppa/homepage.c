//
// Created by 26711 on 2023/12/21.
//

#include "homepage.h"

void homepage ()
{

    SDL_Rect Rec_Start_button={.x=438,.y=200};
    SDL_Rect Rec_Start_button_on={.x=438,.y=200};
    SDL_Rect Rec_name_font={.x=360,.y=0};
    SDL_Rect Rec_font1={.x=536,.y=430};
    SDL_Rect Rec_font2={.x=536,.y=430};
    SDL_QueryTexture(Start_button_texture,NULL,NULL,&Rec_Start_button.w,&Rec_Start_button.h);
    SDL_QueryTexture(Start_button_on_texture,NULL,NULL,&Rec_Start_button_on.w,&Rec_Start_button_on.h);
    SDL_QueryTexture(name_font_texture,NULL,NULL,&Rec_name_font.w,&Rec_name_font.h);
    SDL_QueryTexture(difficulty_font_texture1,NULL,NULL,&Rec_font1.w,&Rec_font1.h);
    SDL_QueryTexture(difficulty_font_texture2,NULL,NULL,&Rec_font2.w,&Rec_font2.h);

    SDL_RenderCopy(render1,  Start_button_texture, NULL, &Rec_Start_button);
    SDL_RenderCopy(render1, difficulty_font_texture1, NULL, &Rec_font1);
    SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
    SDL_RenderPresent(render1);

    SDL_Event start;
    bool whetherstart=false;
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
            if(speed==2)
                SDL_RenderCopy(render1, difficulty_font_texture1, NULL, &Rec_font1);
            else
                SDL_RenderCopy(render1, difficulty_font_texture2, NULL, &Rec_font2);
            SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
            rect_background1.x-=1;
            rect_background2.x-=1;
            if(rect_background1.x<=-1200)rect_background1.x=1200;
            if(rect_background2.x<=-1200)rect_background2.x=1200;
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
            else if(start.button.x>=438&&start.button.x<=762&&start.button.y>=200&&start.button.y<=356)
            {
                on =true;

                SDL_RenderClear(render1);
                SDL_RenderCopy(render1,texture1,NULL,&rect_background1);
                SDL_RenderCopy(render1,texture2,NULL,&rect_background2);
                rect_background1.x-=1;
                rect_background2.x-=1;
                if(rect_background1.x<=-1200)rect_background1.x=1200;
                if(rect_background2.x<=-1200)rect_background2.x=1200;

                if(start.type==SDL_MOUSEBUTTONDOWN)
                {
                    whetherstart=true;
                    break;
                }
                else
                {
                    if(speed==2)
                    {
                        SDL_RenderCopy(render1,  Start_button_on_texture, NULL, &Rec_Start_button_on);
                        SDL_RenderCopy(render1, difficulty_font_texture1, NULL, &Rec_font1);
                        SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
                        SDL_RenderPresent(render1);
                        SDL_Delay(3);
                    }
                    else
                    {
                        SDL_RenderCopy(render1,  Start_button_on_texture, NULL, &Rec_Start_button_on);
                        SDL_RenderCopy(render1, difficulty_font_texture2, NULL, &Rec_font1);
                        SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
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
                if(rect_background1.x<=-1200)rect_background1.x=1200;
                if(rect_background2.x<=-1200)rect_background2.x=1200;
                if(start.type==SDL_MOUSEBUTTONDOWN)
                {
                    if(speed==2)
                    {
                        //SDL_RenderClear(render1);
                        SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
                        SDL_RenderCopy(render1,  Start_button_texture, NULL, &Rec_Start_button);
                        SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
                        SDL_RenderCopy(render1, difficulty_font_texture2, NULL, &Rec_font1);
                        SDL_RenderPresent(render1);
                        speed=5;
                    }
                    else
                    {
                       // SDL_RenderClear(render1);
                        SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
                        SDL_RenderCopy(render1,  Start_button_texture, NULL, &Rec_Start_button);
                        SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
                        SDL_RenderCopy(render1, difficulty_font_texture1, NULL, &Rec_font1);
                        SDL_RenderPresent(render1);
                        speed=2;
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
                if(rect_background1.x<=-1200)rect_background1.x=1200;
                if(rect_background2.x<=-1200)rect_background2.x=1200;

                if(speed==2)
                {
                    //SDL_RenderClear(render1);
                    SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
                    SDL_RenderCopy(render1,  Start_button_texture, NULL, &Rec_Start_button);
                    SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
                    SDL_RenderCopy(render1, difficulty_font_texture1, NULL, &Rec_font1);
                    SDL_RenderPresent(render1);
                    SDL_Delay(3);
                }
                else
                {
                    //SDL_RenderClear(render1);
                    SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
                    SDL_RenderCopy(render1,  Start_button_texture, NULL, &Rec_Start_button);
                    SDL_RenderCopy(render1, name_font_texture, NULL, &Rec_name_font);
                    SDL_RenderCopy(render1, difficulty_font_texture2, NULL, &Rec_font2);
                    SDL_RenderPresent(render1);
                    SDL_Delay(3);
                }
            }
        }
    }

    SDL_DestroyTexture(Start_button_texture);
    SDL_DestroyTexture(Start_button_on_texture);
    SDL_DestroyTexture(name_font_texture);
    SDL_DestroyTexture(difficulty_font_texture1);
    SDL_DestroyTexture(difficulty_font_texture2);
}
