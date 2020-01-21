#include "actor.h"

#define JUMP 20
#define JUMPPOWER 160
#define MOVE 20

Actor::Actor(SDL_Renderer* renderer, const std::string spritePath, std::vector<Sprite*>* map): Sprite(renderer, spritePath) {
    this->map = map;
}

void Actor::Render() {
    std::cout << "Rendering actor with index " << index << std::endl;
    std::cout << " jump-power " << jumpPower << std::endl;
    int w = 428;
    int s_x = w * index - w;

    if (jumpPower > 0) {
        y -= JUMP;
        jumpPower -= JUMP;
    } else if (y < 0 ){
        // We're no longer jumping, time to fall!
        y += JUMP;
    }

    if (movingLeft)
        x -= MOVE;
    if (movingRight)
        x += MOVE;

    SDL_Rect* r = new SDL_Rect { s_x, 0+0, w, 430+0 }; // add 440 to use run animation
    SDL_Rect* d = new SDL_Rect { 100+x, 400+y, 150, 150 };   // Width and Height in the destination rect are ignored

    SDL_RenderCopy(renderer, sprite, r, d);

    if (index < 10) {
        index += 1;
    } else {
        index = 1;
    }
}

void Actor::Jump() {
    if (y == 0)
        jumpPower += JUMPPOWER;
}


bool Actor::CanFall() {

}
