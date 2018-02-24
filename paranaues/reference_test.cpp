#include <iostream>

using namespace std;

class A {
public:
    virtual void hello() {
        std::cout << "Hello world from A()" << std::endl;
    }
};

class B : public A {
public:
    void hello() override {
        std::cout << "Hello world from B()" << std::endl;
    }
};

int main() {
    A a;
    B b;
    A& klass = b;
    a.hello();
    klass.hello();
    return 0;
}
