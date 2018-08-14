#ifndef ACTOR_H
#define ACTOR_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "sprite.h"

class Actor : public Sprite
{
public:
    Actor(SDL_Renderer* renderer, const std::string spritePath);
    void Render();

private:
    int index = 1;
};

#endif // ACTOR_H
