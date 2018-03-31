#include <mxg/sdl/Window.hpp>

#include <sstream>

#include <mxg/Exception.hpp>

namespace mxg {
namespace sdl {

Window::~Window() {
    close();
}

bool Window::isOpen() const {
    return window_ != nullptr;
}
std::string Window::getTitle() const {
    return SDL_GetWindowTitle(window_);
}

Size Window::getSize() const {
    int width{}, height{};
    SDL_GetWindowSize(window_, &width, &height);
    return Size{static_cast<float>(width), static_cast<float>(height)};
}

void Window::create(const std::string& title, const Size& size) {
    window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        size.width, size.height, SDL_WINDOW_SHOWN);
    if (window_ == nullptr) {
        std::ostringstream message{};
        message << "Couldn't create window\n";
        message << "    Error: " << SDL_GetError() << '\n';
        throw Exception(message.str());
    }
}

void Window::close() {
    SDL_DestroyWindow(window_);
    window_ = nullptr;
}

} /* namespace sdl */
} /* namespace mxg */
