// build: make vec_test

#include <iostream>

using namespace std;

class Vector2 {
public:
    float x;
    float y;
};

Vector2 operator+(const Vector2& a, const Vector2& b) {
    return Vector2{a.x + b.x, a.y + b.y};
}

Vector2 operator-(const Vector2& a, const Vector2& b) {
    return Vector2{a.x - b.x, a.y - b.y};
}

Vector2 operator*(const Vector2& v, const float scalar) {
    return Vector2{v.x * scalar, v.y * scalar};
}

Vector2 operator/(const Vector2& v, const float scalar) {
    return Vector2{v.x / scalar, v.y / scalar};
}

int main() {
    Vector2 a{1, 1};
    Vector2 b{2, 2};
    Vector2 v = a / 2;
    std::cout << v.x << ", " << v.y << std::endl;
    return 0;
}
