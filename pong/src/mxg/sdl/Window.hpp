#ifndef MXG_SDL_WINDOW_HPP_
#define MXG_SDL_WINDOW_HPP_

#include <string>

#include <SDL_video.h>
#include <SDL_render.h>

#include <mxg/Size.hpp>
#include <mxg/Window.hpp>

namespace mxg {
namespace sdl {

class Window {
public:
    Window() = default;
    ~Window();

    bool isOpen() const;
    std::string getTitle() const;
    Size getSize() const;

    void create(const std::string& title, const Size& size);
    void close();

    SDL_Window* getBackendWindow() const { return window_; }

private:
    SDL_Window* window_{};
};

} /* namespace sdl */

class Window::Impl : public sdl::Window {};

} /* namespace mxg */
#endif /* MXG_SDL_WINDOW_HPP_ */
