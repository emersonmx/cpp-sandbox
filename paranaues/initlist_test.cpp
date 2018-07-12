#include <iostream>

class Color {
public:
    Color() 
        : r{0}, g{0}, b{0}, a{255} {}
    Color(const uint8_t ar, const uint8_t ag, const uint8_t ab)
        : r{ar}, g{ag}, b{ab}, a{255} {}
    Color(const uint8_t ar, const uint8_t ag, const uint8_t ab, const uint8_t aa)
        : r{ar}, g{ag}, b{ab}, a{aa} {}

    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

void print(const Color& c) {
    std::cout << int(c.r) << ", " << int(c.g) << ", " << int(c.b) << ", " << int(c.a) << std::endl;
}

int main() {
    Color c;
    print({0, 0, 0});
    return 0;
}
