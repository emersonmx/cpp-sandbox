#include <mxg/sdl/Renderer.hpp>

#include <sstream>

#include <mxg/Exception.hpp>

namespace mxg {
namespace sdl {

Renderer::Renderer(SDL_Window* window) {
    renderer_ = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer_ == nullptr) {
        std::ostringstream message{};
        message << "Couldn't create renderer\n";
        message << "    Error: " << SDL_GetError() << '\n';
        throw Exception(message.str());
    }

    Color color{};
    SDL_SetRenderDrawColor(renderer_, color.red, color.green, color.blue, color.alpha);
}

Color Renderer::getClearColor() const {
    Color color;
    SDL_GetRenderDrawColor(renderer_, &color.red, &color.green, &color.blue, &color.alpha);
    return color;
}

void Renderer::clear() {
    clear({0, 0, 0, 255});
}

void Renderer::clear(const Color& color) {
    SDL_SetRenderDrawColor(renderer_, color.red, color.green, color.blue, color.alpha);
    SDL_RenderClear(renderer_);
}

void Renderer::present() {
    SDL_RenderPresent(renderer_);
}

} /* namespace sdl */
} /* namespace mxg */
