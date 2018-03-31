#ifndef MXG_WINDOW_HPP_
#define MXG_WINDOW_HPP_

#include <memory>
#include <string>

#include <mxg/defs.hpp>

namespace mxg {

class Window {
public:
    bool isOpen() const;

    void create(const std::string& title, const Size& size);
    void close();
};

} /* namespace mxg */
#endif /* MXG_WINDOW_HPP_ */
