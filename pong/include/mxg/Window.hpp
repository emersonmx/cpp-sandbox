#ifndef MXG_WINDOW_HPP_
#define MXG_WINDOW_HPP_

#include <memory>
#include <string>

#include <mxg/Size.hpp>

namespace mxg {

class Renderer;

class Window {
public:
    Window();
    ~Window();
    Window(Window&&) = default;
    Window(const Window&&) = delete;
    Window& operator=(Window&&);
    Window& operator=(const Window&&) = delete;

    bool isOpen() const;
    std::string getTitle() const;
    Size getSize() const;

    void create(const std::string& title, const Size& size);
    void close();

private:
    friend Renderer;

    class Impl;
    std::unique_ptr<Impl> pimpl_;
};

} /* namespace mxg */
#endif /* MXG_WINDOW_HPP_ */
