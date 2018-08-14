#include "actor.h"

Actor::Actor(SDL_Renderer* renderer, const std::string spritePath): Sprite(renderer, spritePath) {
}

void Actor::Render() {
    std::cout << "Rendering actor with index " << index << std::endl;
    int w = 428;
    int x = w * index - w;

    SDL_Rect* r = new SDL_Rect { x, 0+0, w, 430+0 }; // add 440 to use run animation
    SDL_Rect* d = new SDL_Rect { 100, 100, 150, 150 };   // Width and Height in the destination rect are ignored

    SDL_RenderCopy(renderer, sprite, r, d);

    if (index < 10) {
        index += 1;
    } else {
        index = 1;
    }
}
