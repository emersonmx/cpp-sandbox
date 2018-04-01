#ifndef MXG_COLOR_HPP_
#define MXG_COLOR_HPP_

#include <cstdint>

namespace mxg {

class Color {
public:
    Color()
        : Color(0, 0, 0, 255) {}
    Color(const uint8_t aRed,
          const uint8_t aGreen,
          const uint8_t aBlue)
        : Color(aRed, aGreen, aBlue, 255) {}
    Color(const uint8_t aRed,
          const uint8_t aGreen,
          const uint8_t aBlue,
          const uint8_t aAlpha)
        : red{aRed}, green{aGreen}, blue{aBlue}, alpha{aAlpha} {}

    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

} /* namespace mxg */
#endif /* MXG_COLOR_HPP_ */
