// Build: LDFLAGS="-lSDL2" make smartptr_test

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

#include "smart_ptr.hpp"

void Init() {
    std::cout << "Init()" << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);
}

void Quit() {
    SDL_Quit();
    std::cout << "Quit()" << std::endl;
}

int main() {
    atexit(Quit);
    Init();

    bool running = true;

    std::cout << "SDL_CreateWindow()" << std::endl;
    sdl2::WindowPtr window(
        SDL_CreateWindow(
            "SDL2 SmartPtr Test",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            800, 600,
            SDL_WINDOW_SHOWN
        )
    );

    std::cout << "SDL_CreateRenderer()" << std::endl;
    sdl2::RendererPtr renderer(
        SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED)
    );

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0xff);
        SDL_RenderClear(renderer.get());
        SDL_RenderPresent(renderer.get());
    }

    return 0;
}
