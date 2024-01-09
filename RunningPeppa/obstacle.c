//
// Created by 26711 on 2024/1/5.
//

#include "obstacle.h"

/*int min(int a, int b) {
    return a < b ? a : b;
}

Uint32 getPixel(SDL_Surface* surface, int x, int y) {
    int bpp = surface->format->BytesPerPixel;
    Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

    switch (bpp) {
        case 1:
            return *p;
        case 2:
            return *(Uint16*)p;
        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
                return p[0] << 16 | p[1] << 8 | p[2];
            else
                return p[0] | p[1] << 8 | p[2] << 16;
        case 4:
            return *(Uint32*)p;
        default:
            return 0;
    }
}

int checkPixelCollision(SDL_Rect a, SDL_Texture* textureA, SDL_Rect b, SDL_Texture* textureB, SDL_Renderer* renderer) {
    // Create surfaces from textures
    SDL_Surface* surfaceA = SDL_CreateRGBSurface(0, a.w, a.h, 32, 0, 0, 0, 0);
    SDL_Surface* surfaceB = SDL_CreateRGBSurface(0, b.w, b.h, 32, 0, 0, 0, 0);

    SDL_RenderReadPixels(renderer, &a, surfaceA->format->format, surfaceA->pixels, surfaceA->pitch);
    SDL_RenderReadPixels(renderer, &b, surfaceB->format->format, surfaceB->pixels, surfaceB->pitch);

    int y, x;
    for (y = 0; y < min(a.h, b.h); y++) {
        for (x = 0; x < min(a.w, b.w); x++) {
            Uint32 pixelA = getPixel(surfaceA, x, y);
            Uint32 pixelB = getPixel(surfaceB, x, y);

            if (pixelA != SDL_MapRGB(surfaceA->format, 0, 0, 0) && pixelB != SDL_MapRGB(surfaceB->format, 0, 0, 0)) {
                // Collision detected
                SDL_FreeSurface(surfaceA);
                SDL_FreeSurface(surfaceB);
                return 1;
            }
        }
    }

    SDL_FreeSurface(surfaceA);
    SDL_FreeSurface(surfaceB);
    return 0;
}*/

void obstacle1Init(SDL_Rect *obstacleArgue)
{
    obstacleArgue->x-=speed;
    if (obstacleArgue->x <= 280 &&
        ((rect_peppa.y + rect_peppa.h >= obstacleArgue->y) &&
         (obstacleArgue->x + obstacleArgue->w >= rect_peppa.x) &&
         (rect_peppa.y <= obstacleArgue->y + obstacleArgue->h)))
    {
        isObstacle1=0;for(int i=0;i<3;i++)SDL_Delay(1000);
        obstacleArgue->x=1200;
        life--;
    }
    if(obstacleArgue->x<=-200)
    {
        isObstacle1=0;
        obstacleArgue->x=1200;
    }
}

void obstacle2Init(SDL_Rect *obstacleArgue)
{
    obstacleArgue->x-=speed;
    if (obstacleArgue->x <= 280&&
        ((rect_peppa.y + rect_peppa.h >= obstacleArgue->y) &&
         (obstacleArgue->x + obstacleArgue->w >= rect_peppa.x) &&
         (rect_peppa.y <= obstacleArgue->y + obstacleArgue->h)))
    {
        isObstacle2=0;for(int i=0;i<3;i++)SDL_Delay(1000);
        obstacleArgue->x=1200;
        life--;
    }
    if(obstacleArgue->x<=-200)
    {
        isObstacle2=0;
        obstacleArgue->x=1200;
    }
}

void obstacle3Init(SDL_Rect *obstacleArgue)
{
    obstacleArgue->x-=speed;
    if (obstacleArgue->x <= 280 &&
        ((rect_peppa.y + rect_peppa.h >= obstacleArgue->y) &&
         (obstacleArgue->x + obstacleArgue->w >= rect_peppa.x) &&
         (rect_peppa.y <= obstacleArgue->y + obstacleArgue->h)))
    {
        isObstacle3=0;for(int i=0;i<3;i++)SDL_Delay(1000);
        obstacleArgue->x=1200;
        life--;
    }
    if(obstacleArgue->x<=-200)
    {
        isObstacle3=0;
        obstacleArgue->x=1200;
    }
}

void obstacle4Init(SDL_Rect *obstacleArgue)
{
    obstacleArgue->x-=speed;
    if (obstacleArgue->x <= 280 &&
        ((rect_peppa.y + rect_peppa.h >= obstacleArgue->y) &&
         (obstacleArgue->x + obstacleArgue->w >= rect_peppa.x) &&
         (rect_peppa.y <= obstacleArgue->y + obstacleArgue->h)))
    {
        isObstacle4=0;for(int i=0;i<3;i++)SDL_Delay(1000);
        obstacleArgue->x=1200;
        life--;
    }
    if(obstacleArgue->x<=-200)
    {
        isObstacle4=0;
        obstacleArgue->x=1200;
    }
}

void obstacle5Init(SDL_Rect *obstacleArgue)
{
    obstacleArgue->x-=speed;
    if (obstacleArgue->x <= 280 &&
        ((rect_peppa.y + rect_peppa.h >= obstacleArgue->y) &&
         (obstacleArgue->x + obstacleArgue->w >= rect_peppa.x) &&
         (rect_peppa.y <= obstacleArgue->y + obstacleArgue->h)))
    {
        isObstacle5=0;for(int i=0;i<3;i++)SDL_Delay(1000);
        obstacleArgue->x=1200;
        life--;
    }
    if(obstacleArgue->x<=-600)
    {
        isObstacle5=0;
        obstacleArgue->x=1200;
    }
}

void obstacle6Init(SDL_Rect *obstacleArgue)
{
    obstacleArgue->x-=speed;
    if (obstacleArgue->x <= 280 &&
        ((rect_peppa.y + rect_peppa.h >= obstacleArgue->y) &&
         (obstacleArgue->x + obstacleArgue->w >= rect_peppa.x) &&
         (rect_peppa.y <= obstacleArgue->y + obstacleArgue->h)))
    {
        isObstacle6=0;for(int i=0;i<3;i++)SDL_Delay(1000);
        obstacleArgue->x=1200;
        life--;
    }
    if(obstacleArgue->x<=-200)
    {
        isObstacle6=0;
        obstacleArgue->x=1200;
    }
}

void obstacle7Init(SDL_Rect *obstacleArgue)
{
    obstacleArgue->x-=speed;
    if (obstacleArgue->x <= 280 &&
        ((rect_peppa.y + rect_peppa.h >= obstacleArgue->y) &&
         (obstacleArgue->x + obstacleArgue->w >= rect_peppa.x) &&
         (rect_peppa.y <= obstacleArgue->y + obstacleArgue->h)))
    {
        isObstacle7=0;for(int i=0;i<3;i++)SDL_Delay(1000);
        obstacleArgue->x=1200;
        life--;
    }
    if(obstacleArgue->x<=-200)
    {
        isObstacle7=0;
        obstacleArgue->x=1200;
    }
}

