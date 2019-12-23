#include <iostream>
#include <memory>

class Texture {
public:
    Texture() {
        std::cout << "Texture()" << std::endl;
    }

    virtual ~Texture() {
        std::cout << "~Texture()" << std::endl;
    }

    void draw() {
        std::cout << "Draw texture!" << std::endl;
    }
};

template<typename T>
class Loader {
public:
    virtual ~Loader() = default;

    virtual std::unique_ptr<T> load(const std::string& filepath) = 0;
};

class TextureLoader : public Loader<Texture> {
public:
    virtual std::unique_ptr<Texture> load(const std::string& filepath) {
        std::cout << "Loading " << filepath << std::endl;
        return std::make_unique<Texture>();
    }
};

int main() {
    TextureLoader loader;
    auto texture = loader.load("example.ext");
    texture->draw();
    return 0;
}
