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

    background = new Sprite(renderer, "background.png");
    knight = new Actor(renderer, "knight.png");

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
        default:
            break;
        }
    }
}

void CApp::OnRender() {

    if ((tick - lastTick) > 150) {
        lastTick = tick;

        //Clear screen
        SDL_RenderClear( renderer );

        background->Render();
        knight->Render();

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
