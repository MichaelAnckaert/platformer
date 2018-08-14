#ifndef CAPP_H
#define CAPP_H

#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include <iostream>

#include "sprite.h"
#include "actor.h"

class CApp {
private:
    bool running;
    SDL_Window* window;
    SDL_Surface* display;
    SDL_Renderer* renderer;

    Sprite* background;
    Actor* knight;

    int index = 1;

    Uint32 lastTick = 0;
    Uint32 tick = 0;

    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 768;

public:
    CApp();
    int OnExecute();
    bool OnInit();
    void OnEvent(SDL_Event* event);
    void OnLoop();
    void OnRender();
    void OnCleanup();
};

#endif
