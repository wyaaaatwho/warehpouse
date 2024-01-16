#include "header.h"
#include "global.h"

void gameLoop()
{
    //running
    srand(time(NULL));
    SDL_Event click;
    while (running)
    {//event processing
        while (SDL_PollEvent(&click) != 0)
        {
            if (click.type == SDL_QUIT){running = false;again=false;} // end the program

            else if (click.type == SDL_KEYDOWN) {
                if (click.key.keysym.sym == SDLK_UP || click.key.keysym.sym == SDLK_DOWN ||
                click.key.keysym.sym == SDLK_SPACE) {
                    pigpeppa(&rect_peppa, &click);
                } else {
                    SDL_Keycode keyCode = click.key.keysym.sym;
                }
            } else if (click.type == SDL_MOUSEBUTTONDOWN) {
                pigpeppa(&rect_peppa_shoot, &click);
            }
            SDL_FlushEvent(SDL_KEYDOWN); // avoid any possible bug
            //break
        }
        // moving background
        SDL_RenderCopy(render1, texture1, NULL, &rect_background1);
        SDL_RenderCopy(render1, texture2, NULL, &rect_background2);

            peppaStatus();//moving peppa
            obstacleMove(); // obstacle
            statusDisplay();// status bar
            attackMove();// bullet fly
            scoreDisplay();// display score

            SDL_RenderPresent(render1);
            SDL_RenderClear(render1);

            rect_background1.x -= speed;
            rect_background2.x -= speed;
            if (rect_background1.x <= -edge)rect_background1.x = edge;
            if (rect_background2.x <= -edge)rect_background2.x = edge;

            if (life <= 0) {
                running = 0;
            }
            SDL_Delay(2);
        }
    SDL_Delay(2000);
}

int main(int argc, char *argv[])
{
    if(initiation()!=0)printf("%s",SDL_GetError()); // initiation
    loop1:homepage();
    //initiating homepage
    loop2:gameLoop();
    if(again){
        switch (restartPage()) {
            case 1:
                goto loop1;
            case 2:
                goto loop2;
        }
    }
    shutdown(); //shutdown the program

}
