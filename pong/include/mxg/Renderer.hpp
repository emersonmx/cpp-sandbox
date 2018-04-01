#ifndef MXG_RENDERER_HPP_
#define MXG_RENDERER_HPP_

#include <memory>

#include <mxg/Color.hpp>
#include <mxg/Window.hpp>

namespace mxg {

class Renderer {
public:
    Renderer() = delete;
    Renderer(const Window& window);
    ~Renderer();
    Renderer(Renderer&&) = default;
    Renderer(const Renderer&&) = delete;
    Renderer& operator=(Renderer&&);
    Renderer& operator=(const Renderer&&) = delete;

    Color getClearColor() const;

    void clear();
    void clear(const Color& color);
    void present();

private:
    class Impl;
    std::unique_ptr<Impl> pimpl_;
};

} /* namespace mxg */
#endif /* MXG_RENDERER_HPP_ */
