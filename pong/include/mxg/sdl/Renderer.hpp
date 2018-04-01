#ifndef MXG_SDL_RENDERER_HPP_
#define MXG_SDL_RENDERER_HPP_

#include <SDL_render.h>

#include <mxg/Color.hpp>

namespace mxg {
namespace sdl {

class Renderer {
public:
    Renderer() = default;
    Renderer(SDL_Window* window);

    void create(SDL_Window* window);

    Color getClearColor() const;
    void setClearColor(const Color& color);

    void clear();
    void clear(const Color& color);
    void present();

    operator SDL_Renderer*() const { return renderer_; }

private:
    SDL_Renderer* renderer_{};
};

} /* namespace sdl */
} /* namespace mxg */
#endif /* MXG_SDL_RENDERER_HPP_ */
