#include <mxg/Window.hpp>

#include <mxg/Renderer.hpp>

#if defined(USE_SDL_BACKEND)
#include <mxg/sdl/Window.hpp>
#endif

namespace mxg {

Window::Window() : pimpl_{std::make_unique<Impl>()} {}
Window::~Window() = default;
Window& Window::operator=(Window&&) = default;

bool Window::isOpen() const {
    return pimpl_->isOpen();
}

std::string Window::getTitle() const {
    return pimpl_->getTitle();
}

Size Window::getSize() const {
    return pimpl_->getSize();
}

void Window::create(const std::string& title, const Size& size) {
    pimpl_->create(title, size);
}

void Window::close() {
    pimpl_->close();
}

} /* namespace mxg */
