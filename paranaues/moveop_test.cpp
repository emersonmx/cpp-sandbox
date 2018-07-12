#include <iostream>
#include <memory>

class B {
public:
    void hello() {
        std::cout << "hello" << std::endl;
    }
};

class A {
public:
    A(const B& aB) : b{aB} {
        std::cout << "A()" << std::endl;
    }
    ~A() {
        std::cout << "~A()" << std::endl;
    }

    void hello() {
        b.hello();
    }

    B b;
};

int main() {
    std::unique_ptr<B> b{std::make_unique<B>()};
    std::unique_ptr<A> a{std::make_unique<A>(*b)};
    a->hello();
    return 0;
}
