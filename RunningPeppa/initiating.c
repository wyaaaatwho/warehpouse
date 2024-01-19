//
// Created by 26711 on 2023/12/20.
//

#include "initiating.h"

int initiation ()
{

    // initiating window
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError()); return -1;
    }
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return -1;
    }

    else
    {
        IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG);
        TTF_Init();
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        window= SDL_CreateWindow("RUNNING_PEPPA",
                                 SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                 edge,sky,SDL_WINDOW_SHOWN);

        if(window==NULL)printf("SDL_CreateWindow Error: %s\n", SDL_GetError());

        else
        {
            render1= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED); // initiating renderer

            // initiating history
            history_p=fopen("./resource/history.txt","a+");
            fgets(history_buffer,sizeof(history_buffer),history_p);
            if(history_buffer[0]!='\0')history=atoi(history_buffer);

            //initiating map
            backGround1 =IMG_Load("./resource/dino-game-cover.1 - 2.png");
            backGround2 =IMG_Load("./resource/dino-game-cover.1 - 2.png");
            if(backGround1==NULL||backGround2==NULL)printf("Image loading failed: %s\n",SDL_GetError());

            // loading map
            texture1= SDL_CreateTextureFromSurface(render1,backGround1);
            texture2= SDL_CreateTextureFromSurface(render1,backGround2);
            SDL_QueryTexture(texture1, NULL, NULL, &rect_background1.w, &rect_background1.h);
            SDL_QueryTexture(texture2, NULL, NULL, &rect_background2.w, &rect_background2.h);

            //initiating help page
            backGround1 =IMG_Load("./resource/helppage1.png");
            backGround2 =IMG_Load("./resource/helppage2.png");
            help_page1_texture= SDL_CreateTextureFromSurface(render1,backGround1);
            help_page2_texture= SDL_CreateTextureFromSurface(render1,backGround2);

            //initiating start button
            Start_button = IMG_Load("./resource/Start-Button-Vector-PNG -1.png");
            Start_button_on=IMG_Load("./resource/Start-Button-Vector-PNG -1 -on.png");

            // initiating peppa
            peppa=IMG_Load("./resource/walkingpeppa.png");
            peppa_left= IMG_Load("./resource/walkingpeppa - left.png");
            peppa_right= IMG_Load("./resource/walkingpeppa - right.png");
            peppa_shoot= IMG_Load("./resource/walkingpeppa - shooting.png");
            peppa_kneel= IMG_Load("./resource/walkingpeppa - kneel.png");
            pork= IMG_Load("./resource/pork.png");

            //loading peppa
            peppa_texture=SDL_CreateTextureFromSurface(render1, peppa);
            peppa_left_texture=SDL_CreateTextureFromSurface(render1, peppa_left);
            peppa_right_texture=SDL_CreateTextureFromSurface(render1, peppa_right);
            peppa_shoot_texture=SDL_CreateTextureFromSurface(render1, peppa_shoot);
            peppa_kneel_texture=SDL_CreateTextureFromSurface(render1, peppa_kneel);
            pork_texture=SDL_CreateTextureFromSurface(render1, pork);
            SDL_QueryTexture(peppa_texture, NULL, NULL, &rect_peppa.w, &rect_peppa.h);
            SDL_QueryTexture(peppa_kneel_texture, NULL, NULL, &rect_peppa_kneel.w, &rect_peppa_kneel.h);
            SDL_QueryTexture(peppa_left_texture, NULL, NULL, &rect_peppa_left.w, &rect_peppa_left.h);
            SDL_QueryTexture(peppa_right_texture, NULL, NULL, &rect_peppa_right.w, &rect_peppa_right.h);
            SDL_QueryTexture(peppa_shoot_texture, NULL, NULL, &rect_peppa_shoot.w, &rect_peppa_shoot.h);

            // initiating font
            font1= TTF_OpenFont("./resource/LLPixelFun-Regular.ttf",49);
            if(!font1){
                printf("error %s",SDL_GetError());
            }
            name_font =TTF_RenderText_Blended(font1,"Running Peppa Pig",font_color1);
            name_font_texture= SDL_CreateTextureFromSurface(render1,name_font);
            difficulty_font= TTF_RenderText_Blended(font1,"easy",font_color1);
            difficulty_font_texture1= SDL_CreateTextureFromSurface(render1,difficulty_font);
            difficulty_font= TTF_RenderText_Blended(font1,"hard",font_color1);
            difficulty_font_texture2= SDL_CreateTextureFromSurface(render1,difficulty_font);
            helpFont=TTF_RenderText_Blended(font1,"HELP",font_color1);
            helpFontTexture=SDL_CreateTextureFromSurface(render1,helpFont);


            //initiating start button
            Start_button_texture = SDL_CreateTextureFromSurface(render1, Start_button);
            Start_button_on_texture=SDL_CreateTextureFromSurface(render1, Start_button_on);

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

            sprintf(buffer1, "X %d", lana);
            lanaFont= TTF_RenderText_Blended(font1, buffer1, font_color1);
            lanaFont_texture= SDL_CreateTextureFromSurface(render1,lanaFont);

            // loading status bar
            SDL_QueryTexture(lifeBar1_texture,NULL,NULL,&rect_lifeBar.w,&rect_lifeBar.h);
            SDL_QueryTexture(lanaBar_texture,NULL,NULL,&rect_lanaBar.w,&rect_lanaBar.h);
            SDL_QueryTexture(lanaFont_texture,NULL,NULL,&rect_lanaBar_font.w,&rect_lanaBar_font.h);

            // initiating score
            font2= TTF_OpenFont("./resource/LLPixelFun-Regular.ttf",30);
            if(!font2){
                printf("error %s",SDL_GetError());
            }
            sprintf(buffer2, "History %d Current %d", history,score);
            scoreFont= TTF_RenderText_Blended(font2, buffer2, font_color1);
            scoreFontTexture= SDL_CreateTextureFromSurface(render1,scoreFont);

            // loading score
            SDL_QueryTexture(scoreFontTexture,NULL,NULL,&rect_score.w,&rect_score.h);

            // initiating rewards
            reward1 = IMG_Load("./resource/heart.png");
            reward2 = IMG_Load("./resource/lana.png");
            reward1_texture= SDL_CreateTextureFromSurface(render1,reward1);
            reward2_texture= SDL_CreateTextureFromSurface(render1,reward2);
            SDL_QueryTexture(reward1_texture,NULL,NULL,&rect_reward1.w,&rect_reward1.h);
            SDL_QueryTexture(reward2_texture,NULL,NULL,&rect_reward2.w,&rect_reward2.h);
            reward1 = IMG_Load("./resource/hamburger.png");
            reward3_texture= SDL_CreateTextureFromSurface(render1,reward1);
            SDL_QueryTexture(reward3_texture,NULL,NULL,&rect_reward3.w,&rect_reward3.h);
            reward1 = IMG_Load("./resource/shield.png");
            shield_texture=SDL_CreateTextureFromSurface(render1,reward1);
            SDL_QueryTexture(shield_texture,NULL,NULL,&rect_shield.w,&rect_shield.h);
            rect_shield.y=rect_peppa.y+rect_peppa.h-rect_shield.h+20;
            rect_shield.x=rect_peppa.x+rect_peppa.w/2-rect_shield.w/2;

            // initiating bullet
            bullet = IMG_Load("./resource/flying_bullet1.png");
            bullet_texture1=SDL_CreateTextureFromSurface(render1,bullet);
            bullet_texture2=SDL_CreateTextureFromSurface(render1,bullet);
            bullet_texture3=SDL_CreateTextureFromSurface(render1,bullet);
            SDL_QueryTexture(bullet_texture1,NULL,NULL,&rect_bullet1.w,&rect_bullet1.h);
            SDL_QueryTexture(bullet_texture2,NULL,NULL,&rect_bullet2.w,&rect_bullet2.h);
            SDL_QueryTexture(bullet_texture3,NULL,NULL,&rect_bullet3.w,&rect_bullet3.h);

            // initiating restart
            restart=IMG_Load("./resource/restart1.png");
            restart1_texture= SDL_CreateTextureFromSurface(render1,restart);
            restart=IMG_Load("./resource/restart2.png");
            restart2_texture= SDL_CreateTextureFromSurface(render1,restart);
            SDL_QueryTexture(restart1_texture,NULL,NULL,&rect_restart.w,&rect_restart.h);
            rect_restart.x=edge/2-rect_restart.w/2;
            rect_restart.y=sky/2-rect_restart.h/2;

            // loading music
            mainMusic = Mix_LoadMUS("./resource/Children_s-Choir-Peppa-Pig.mp3");
            peppaHonk=Mix_LoadWAV("./resource/peppaHonk.mp3");
            peppaDeathScream=Mix_LoadWAV("./resource/peppaDeathScream.mp3");
            if (mainMusic == NULL||peppaHonk==NULL||peppaDeathScream==NULL) {
                printf("music loading failed: %s\n", Mix_GetError());
            }
            Mix_AllocateChannels(2);
        }

        SDL_FreeSurface(backGround1);
        SDL_FreeSurface(backGround2);
        SDL_FreeSurface(peppa);
        SDL_FreeSurface(peppa_left);
        SDL_FreeSurface(peppa_right);
        SDL_FreeSurface(peppa_shoot);
        SDL_FreeSurface(peppa_kneel);
        SDL_FreeSurface(Start_button);
        SDL_FreeSurface(Start_button_on);
        SDL_FreeSurface(difficulty_font);
        SDL_FreeSurface(name_font);
        SDL_FreeSurface(obstacle1);
        SDL_FreeSurface(obstacle2);
        SDL_FreeSurface(obstacle3);
        SDL_FreeSurface(obstacle4);
        SDL_FreeSurface(obstacle5);
        SDL_FreeSurface(obstacle6);
        SDL_FreeSurface(obstacle7);
        SDL_FreeSurface(lifeBar);
        SDL_FreeSurface(lanaBar);
        SDL_FreeSurface(lanaFont);
        SDL_FreeSurface(reward1);
        SDL_FreeSurface(reward2);
        SDL_FreeSurface(bullet);
        SDL_FreeSurface(scoreFont);
        SDL_FreeSurface(restart);

    }  // initiating
    return 0;
}
