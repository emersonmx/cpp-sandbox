#include <mxg/Renderer.hpp>

#if defined(USE_SDL_BACKEND)
#include <mxg/sdl/Window.hpp>
#include <mxg/sdl/Renderer.hpp>
#endif

namespace mxg {

Renderer::Renderer(const Window& window)
    : pimpl_{new Impl{window.pimpl_->getBackendWindow()}} {}
Renderer::~Renderer() = default;
Renderer& Renderer::operator=(Renderer&&) = default;

Color Renderer::getClearColor() const {
    return pimpl_->getClearColor();
}

void Renderer::clear() {
    pimpl_->clear();
}

void Renderer::clear(const Color& color) {
    pimpl_->clear(color);
}

void Renderer::present() {
    pimpl_->present();
}

} /* namespace mxg */
