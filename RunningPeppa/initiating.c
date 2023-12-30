//
// Created by 26711 on 2023/12/20.
//

#include "initiating.h"

int initiation ()
{

    // initiating window
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError()); return 1;
    }

    else
    {
        IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG);
        TTF_Init();
        window= SDL_CreateWindow("RUNNING_PEPPA",
                                 SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                 1200,610,SDL_WINDOW_SHOWN);

        if(window==NULL)printf("SDL_CreateWindow Error: %s\n", SDL_GetError());

        else
        {
            render1= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED); // initiating renderer

            //initiating map
            backGround1 =IMG_Load("./resource/dino-game-cover.1 - 2.png");
            backGround2 =IMG_Load("./resource/dino-game-cover.1 - 2.png");
            if(backGround1==NULL||backGround2==NULL)printf("Image loading failed: %s\n",SDL_GetError());

            //initiating start button
            Start_button = IMG_Load("./resource/Start-Button-Vector-PNG -1.png");
            Start_button_on=IMG_Load("./resource/Start-Button-Vector-PNG -1 -on.png");

            // initiating peppa
            peppa=IMG_Load("./resource/walkingpeppa.png");
            peppa_left= IMG_Load("./resource/walkingpeppa - left.png");
            peppa_right= IMG_Load("./resource/walkingpeppa - right.png");
            peppa_shoot= IMG_Load("./resource/walkingpeppa - shooting.png");
            peppa_kneel= IMG_Load("./resource/walkingpeppa - kneel.png");

            // initiating font
            font= TTF_OpenFont("./resource/LLPixelFun-Regular.ttf",49);
            if(!font){
                printf("error %s",SDL_GetError());
            }
            name_font =TTF_RenderText_Blended(font,"Running Peppa Pig",font_color1);
            name_font_texture= SDL_CreateTextureFromSurface(render1,name_font);
            difficulty_font= TTF_RenderText_Blended(font,"easy",font_color1);
            difficulty_font_texture1= SDL_CreateTextureFromSurface(render1,difficulty_font);
            difficulty_font= TTF_RenderText_Blended(font,"hard",font_color1);
            difficulty_font_texture2= SDL_CreateTextureFromSurface(render1,difficulty_font);

            //initiating map
            texture1= SDL_CreateTextureFromSurface(render1,backGround1);
            texture2= SDL_CreateTextureFromSurface(render1,backGround2);

            //initiating start button
            Start_button_texture = SDL_CreateTextureFromSurface(render1, Start_button);
            Start_button_on_texture=SDL_CreateTextureFromSurface(render1, Start_button_on);

            // initiating peppa
            peppa_texture=SDL_CreateTextureFromSurface(render1, peppa);
            peppa_left_texture=SDL_CreateTextureFromSurface(render1, peppa_left);
            peppa_right_texture=SDL_CreateTextureFromSurface(render1, peppa_right);
            peppa_shoot_texture=SDL_CreateTextureFromSurface(render1, peppa_shoot);
            peppa_kneel_texture=SDL_CreateTextureFromSurface(render1, peppa_kneel);

            SDL_FreeSurface(backGround1);
            SDL_FreeSurface(backGround2);
            SDL_FreeSurface(Start_button);
            SDL_FreeSurface(Start_button_on);
            SDL_FreeSurface(peppa);
            SDL_FreeSurface(peppa_left);
            SDL_FreeSurface(peppa_right);
            SDL_FreeSurface(peppa_shoot);
            SDL_FreeSurface(peppa_kneel);
            SDL_FreeSurface(name_font);
            SDL_FreeSurface(difficulty_font);

        }
    }  // initiating
    return 0;
}
