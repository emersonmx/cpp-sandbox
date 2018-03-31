#include <mxg/Size.hpp>

#include <cassert>

namespace mxg {

Size::Size(real_t aWidth, real_t aHeight) {
    assert(aWidth >= 0);
    assert(aHeight >= 0);

    width = aWidth;
    height = aHeight;
}

} /* namespace mxg */
