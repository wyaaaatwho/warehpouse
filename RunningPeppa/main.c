#include "header.h"
#include "global.h"
void handleEvents(SDL_Event event)
{
    if (event.type == SDL_QUIT) {
        running = false;
        currentGameStatus=gameOver;
        gameRunning=0;
    }
    else if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN ||event.key.keysym.sym == SDLK_SPACE)
        {
            pigpeppa(&rect_peppa, &event);
        }
    }
    else if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        pigpeppa(&rect_peppa_shoot, &event);
    }
    else if(event.key.keysym.sym ==SDLK_ESCAPE)
    {
        running = false;
        currentGameStatus=goHomepage;
    }
}
void gameLoop()
{
    //running
    srand(time(NULL));
    SDL_Event click;
    while (running)
    {//event processing
        while (SDL_PollEvent(&click) != 0)
        {
            handleEvents( click);
        }

        moveBackground();// moving background
        peppaNormalDisplay();//moving peppa
        obstacleMove(); // obstacle
        statusDisplay();// status bar
        attackMove();// bullet fly
        scoreDisplay();// display score

        SDL_RenderPresent(render1);
        SDL_RenderClear(render1);

        if (life <= 0) {
            running = false;
            currentGameStatus=goRestart;
            Mix_PlayChannel(1, peppaDeathScream, 0);
            peppaDeathDisplay();
            SDL_Delay(DELAY_TIME*1500);
        }

        SDL_Delay(DELAY_TIME);
    }
}

int main(int argc, char *argv[])
{
    if(initiation()!=0)printf("%s",SDL_GetError()); // initiation

    gameRunning=1;

    currentGameStatus = goHomepage;

    Mix_PlayMusic(mainMusic, -1);

    while(gameRunning)
    {
        switch(currentGameStatus)
        {
            case goHomepage:
                homepage();
                break;
            case gaming:
                gameLoop();
                break;
            case goRestart:
                restartPage();
                break;
            case gameOver:
                shutdown();
                break;
        }

    }

}
