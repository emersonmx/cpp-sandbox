#ifndef MXG_SDL_EXCEPTION_HPP_
#define MXG_SDL_EXCEPTION_HPP_

#include <stdexcept>

namespace mxg {
namespace sdl {

class Exception : public std::runtime_error {
public:
    Exception(const std::string& what)
        : std::runtime_error(what) {}
};

} /* namespace sdl */
} /* namespace mxg */
#endif /* MXG_SDL_EXCEPTION_HPP_ */
