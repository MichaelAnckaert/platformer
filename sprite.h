#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

class Sprite
{
public:
    Sprite(SDL_Renderer* renderer, std::string spritePath, int x=0, int y=0, int w=0, int h=0);
    void Render();

protected:
    SDL_Renderer* renderer;
    SDL_Texture* sprite;

    int x, y, w, h;

private:
    SDL_Texture* LoadTexture(std::string path);
};

#endif // SPRITE_H
