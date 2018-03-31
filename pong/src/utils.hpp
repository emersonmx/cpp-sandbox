#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace pong {

bool initSystems() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Couldn't start SDL" << std::endl;
        std::cout << "    Error: " << SDL_GetError() << std::endl;
        return false;
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if ((IMG_Init(imgFlags) & imgFlags) == 0) {
        std::cout << "Couldn't start SDL Image" << std::endl;
        std::cout << "    Error: " << IMG_GetError() << std::endl;
        return false;
    }

    if (TTF_Init() < 0) {
        std::cout << "Couldn't start SDL TTF" << std::endl;
        std::cout << "    Error: " << TTF_GetError() << std::endl;
        return false;
    }

    return true;
}

void quitSystems() {
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& path, SDL_Rect& offset) {
    SDL_Texture* texture{};

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Unable to load image " << path << std::endl;
        std::cout << "    IMG Error: " << IMG_GetError() << std::endl;
    } else {
        offset.w = loadedSurface->w;
        offset.h = loadedSurface->h;

        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (texture == nullptr) {
            std::cout << "Unable to create texture " << path << std::endl;
            std::cout << "    IMG Error: " << IMG_GetError() << std::endl;
        }
        SDL_FreeSurface(loadedSurface);
    }

    return texture;
}

void render(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect& offset) {
    SDL_Rect newOffset{offset};
    newOffset.x = -offset.w / 2;
    newOffset.y = -offset.h / 2;
    SDL_RenderCopy(renderer, texture, nullptr, &newOffset);
}

} /* namespace pong */
#endif /* UTILS_HPP_ */
