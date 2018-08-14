#include "sprite.h"

Sprite::Sprite(SDL_Renderer* renderer, std::string spritePath) {
    this->renderer = renderer;
    sprite = LoadTexture(spritePath);
}

SDL_Texture* Sprite::LoadTexture(std::string path) {
    SDL_Texture* texture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image " << path << " SDL_image error: " << IMG_GetError() << std::endl;
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (texture == nullptr) {
            std::cerr << "Unable to create texture from " << path << " SDL error: " << SDL_GetError() << std::endl;
        }

        SDL_FreeSurface(loadedSurface);
    }

    return texture;
}


void Sprite::Render() {
    SDL_RenderCopy(renderer, sprite, nullptr, nullptr);
}
