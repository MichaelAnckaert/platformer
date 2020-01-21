#include "capp.h"

CApp::CApp() {
    window = nullptr;
    running = true;
}

int CApp::OnExecute() {
    if (OnInit() == false) {
        return -1;
    }

    SDL_Event event;

    while(running) {
        while(SDL_PollEvent(&event)) {
            OnEvent(&event);
        }

        tick = SDL_GetTicks();

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

bool CApp::OnInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    window = SDL_CreateWindow("Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

    if (renderer == nullptr) {
        std::cerr << "Could not initialize renderer: " << SDL_GetError() << std::endl;
        return false;
    } else {
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
            std::cerr << "SDL_image could not initialize! SDL_image Error: %s\n" <<  IMG_GetError() << std::endl;
            return false;
        }
    }

    display = SDL_GetWindowSurface(window);

    map = new std::vector<Sprite*>();
    for(int i = 0; i <= 20; i++) {
        map->push_back(new Sprite(renderer, "brick.png", 50*i, 600, 50, 50));
    }

    background = new Sprite(renderer, "background.png");
    knight = new Actor(renderer, "knight.png", map);

    return true;
}

void CApp::OnEvent(SDL_Event* event) {
    if (event->type == SDL_QUIT) {
        running = false;
    }
    else if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
        case SDLK_ESCAPE:
            running = false;
            break;
        case SDLK_LEFT:
            knight->movingLeft = true;
            break;
        case SDLK_RIGHT:
            knight->movingRight = true;
            break;
        case SDLK_SPACE:
            knight->Jump();
            break;
        default:
            break;
        }
    } else if (event->type == SDL_KEYUP) {
        switch (event->key.keysym.sym) {
        case SDLK_LEFT:
            knight->movingLeft = false;
            break;
        case SDLK_RIGHT:
            knight->movingRight = false;
            break;
        }
    }
}

void CApp::OnRender() {

    if ((tick - lastTick) > 150) {
        lastTick = tick;

        //Clear screen
        //SDL_RenderClear( renderer );  We don't need to clear the screen?

        background->Render();
        knight->Render();

        for (Sprite* sprite : *map)
            sprite->Render();

        SDL_RenderPresent(renderer);
    }
}

void CApp::OnLoop() {
}

void CApp::OnCleanup() {
    SDL_Quit();
}

int main(int argc, char *argv[]) {
    CApp app;
    return app.OnExecute();
}
