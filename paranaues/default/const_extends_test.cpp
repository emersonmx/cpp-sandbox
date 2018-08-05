#include <iostream>

using namespace std;

class A {
public:
    const int NUMBER = 0;

    virtual ~A() {}

    virtual void print() {
        std::cout << "A NUMBER: " << NUMBER << std::endl;
    }
};

class B: public A {
public:
    const int NUMBER = 1;

    void print() override {
        std::cout << "B NUMBER: " << NUMBER << std::endl;
    }
};

int main() {
    A a;
    B b;
    A& c = b;
    a.print();
    b.print();
    c.print();
    return 0;
}
