#include "utils.hpp"

using namespace pong;

int main() {
    constexpr const int WIDTH{640};
    constexpr const int HEIGHT{480};

    bool running = initSystems();

    SDL_Window* window{};
    SDL_Renderer* renderer{};

    window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Couldn't create window" << std::endl;
        std::cout << "    Error: " << SDL_GetError() << std::endl;
        running = false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "Couldn't create renderer" << std::endl;
        std::cout << "    Error: " << SDL_GetError() << std::endl;
        running = false;
    }

    SDL_Rect padRect{};
    SDL_Texture* padTexture = loadTexture(renderer, "assets/pad.png", padRect);
    padRect.w *= 4;
    padRect.h *= 4;

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        render(renderer, padTexture, padRect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(padTexture);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    quitSystems();

    return 0;
}
