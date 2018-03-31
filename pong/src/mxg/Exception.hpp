#ifndef MXG_EXCEPTION_HPP_
#define MXG_EXCEPTION_HPP_

#include <stdexcept>

namespace mxg {

class Exception : public std::runtime_error {
public:
    Exception(const std::string& what)
        : std::runtime_error(what) {}
};

} /* namespace mxg */
#endif /* MXG_EXCEPTION_HPP_ */
