#ifndef ACTOR_H
#define ACTOR_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "sprite.h"

class Actor : public Sprite
{
public:
    Actor(SDL_Renderer* renderer, const std::string spritePath, std::vector<Sprite*>* map);
    void Render();

    void MoveLeft();
    void MoveRight();
    void Jump();

    bool movingLeft = false;
    bool movingRight = false;

private:
    bool canFall();

    std::vector<Sprite*>* map;
    int index = 1;

    int x = 0;
    int y = 0;
    int jumpPower = 0;
};

#endif // ACTOR_H
