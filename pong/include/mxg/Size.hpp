#ifndef MXG_SIZE_HPP_
#define MXG_SIZE_HPP_

#include <mxg/defs.hpp>

namespace mxg {

class Size {
public:
    Size() = default;
    Size(real_t aWidth, real_t aHeight);

    real_t width;
    real_t height;
};

} /* namespace mxg */
#endif /* MXG_SIZE_HPP_ */
