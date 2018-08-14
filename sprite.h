#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

class Sprite
{
public:
    Sprite(SDL_Renderer* renderer, std::string spritePath);
    void Render();

protected:
    SDL_Renderer* renderer;
    SDL_Texture* sprite;

private:
    SDL_Texture* LoadTexture(std::string path);
};

#endif // SPRITE_H
