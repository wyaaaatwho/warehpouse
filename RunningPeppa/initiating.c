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

            //initiating obstacle
            obstacle1=IMG_Load("./resource/monster_1.png");
            obstacle1_texture= SDL_CreateTextureFromSurface(render1,obstacle1);
            obstacle2=IMG_Load("./resource/monster_2.png");
            obstacle2_texture= SDL_CreateTextureFromSurface(render1,obstacle2);
            obstacle3=IMG_Load("./resource/flying_eye.png");
            obstacle3_texture= SDL_CreateTextureFromSurface(render1,obstacle3);
            obstacle4=IMG_Load("./resource/monster_3.png");
            obstacle4_texture= SDL_CreateTextureFromSurface(render1,obstacle4);
            obstacle5=IMG_Load("./resource/monster_5.png");
            obstacle5_texture= SDL_CreateTextureFromSurface(render1,obstacle5);
            obstacle6=IMG_Load("./resource/monster_6.png");
            obstacle6_texture= SDL_CreateTextureFromSurface(render1,obstacle6);
            obstacle7=IMG_Load("./resource/monster_7.png");
            obstacle7_texture= SDL_CreateTextureFromSurface(render1,obstacle7);

            //loading obstacle
            SDL_QueryTexture(obstacle1_texture, NULL, NULL, &rect_obstacle1.w, &rect_obstacle1.h);
            SDL_QueryTexture(obstacle2_texture, NULL, NULL, &rect_obstacle2.w, &rect_obstacle2.h);
            SDL_QueryTexture(obstacle3_texture, NULL, NULL, &rect_obstacle3.w, &rect_obstacle3.h);
            SDL_QueryTexture(obstacle4_texture, NULL, NULL, &rect_obstacle4.w, &rect_obstacle4.h);
            SDL_QueryTexture(obstacle5_texture, NULL, NULL, &rect_obstacle5.w, &rect_obstacle5.h);
            SDL_QueryTexture(obstacle6_texture, NULL, NULL, &rect_obstacle6.w, &rect_obstacle6.h);
            SDL_QueryTexture(obstacle7_texture, NULL, NULL, &rect_obstacle7.w, &rect_obstacle7.h);


            //initiating status bar
            lifeBar= IMG_Load("./resource/hearts_3.png");
            lifeBar1_texture= SDL_CreateTextureFromSurface(render1,lifeBar);
            lifeBar= IMG_Load("./resource/hearts_2.png");
            lifeBar2_texture= SDL_CreateTextureFromSurface(render1,lifeBar);
            lifeBar= IMG_Load("./resource/hearts_1.png");
            lifeBar3_texture= SDL_CreateTextureFromSurface(render1,lifeBar);
            lifeBar= IMG_Load("./resource/hearts_0.png");
            lifeBar4_texture= SDL_CreateTextureFromSurface(render1,lifeBar);
            lanaBar= IMG_Load("./resource/lana.png");
            lanaBar_texture= SDL_CreateTextureFromSurface(render1,lanaBar);

            sprintf(buffer, "X %d", lana);
            lanaFont= TTF_RenderText_Blended(font, buffer, font_color1);
            lanaFont_texture= SDL_CreateTextureFromSurface(render1,difficulty_font);

            // loading status bar
            SDL_QueryTexture(lifeBar1_texture,NULL,NULL,&rect_lifeBar.w,&rect_lifeBar.h);
            SDL_QueryTexture(lanaBar_texture,NULL,NULL,&rect_lanaBar.w,&rect_lanaBar.h);
            SDL_QueryTexture(lanaFont_texture,NULL,NULL,&rect_lanaBar_font.w,&rect_lanaBar_font.h);

            // initiating rewards
            reward1 = IMG_Load("./resource/heart.png");
            reward2 = IMG_Load("./resource/lana.png");
            reward1_texture= SDL_CreateTextureFromSurface(render1,reward1);
            reward2_texture= SDL_CreateTextureFromSurface(render1,reward2);
            SDL_QueryTexture(reward1_texture,NULL,NULL,&rect_reward1.w,&rect_reward1.h);
            SDL_QueryTexture(reward2_texture,NULL,NULL,&rect_reward2.w,&rect_reward2.h);

            // initiating bullet
            bullet = IMG_Load("./resource/flying_bullet1.png");
            bullet_texture1=SDL_CreateTextureFromSurface(render1,bullet);
            bullet_texture2=SDL_CreateTextureFromSurface(render1,bullet);
            bullet_texture3=SDL_CreateTextureFromSurface(render1,bullet);
            SDL_QueryTexture(bullet_texture1,NULL,NULL,&rect_bullet1.w,&rect_bullet1.h);
            SDL_QueryTexture(bullet_texture2,NULL,NULL,&rect_bullet2.w,&rect_bullet2.h);
            SDL_QueryTexture(bullet_texture3,NULL,NULL,&rect_bullet3.w,&rect_bullet3.h);
        }

    }  // initiating
    return 0;
}
