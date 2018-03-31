#include <mxg/Window.hpp>

#if defined(USE_SDL_BACKEND)
#include <mxg/sdl/Window.hpp>
class mxg::Window::Impl : public mxg::sdl::Window {};
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
