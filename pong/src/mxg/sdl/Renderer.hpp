#ifndef MXG_SDL_RENDERER_HPP_
#define MXG_SDL_RENDERER_HPP_

#include <SDL.h>

#include <mxg/Color.hpp>
#include <mxg/Renderer.hpp>

#include <mxg/sdl/Window.hpp>

namespace mxg {
namespace sdl {

class Renderer {
public:
    Renderer(SDL_Window* window);

    Color getClearColor() const;

    void clear();
    void clear(const Color& color);
    void present();

private:
    SDL_Renderer* renderer_{};
};

} /* namespace sdl */

class Renderer::Impl : public sdl::Renderer {};

} /* namespace mxg */
#endif /* MXG_SDL_RENDERER_HPP_ */
