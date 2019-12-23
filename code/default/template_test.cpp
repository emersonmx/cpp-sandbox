#include <iostream>
#include <string>

class A {
public:
    A(const std::string& s) : s_(s) {}
    void hello() { std::cout << "Hello from A - " << s_ << std::endl; }

private:
    std::string s_;
};

class B {
public:
    B(const std::string& s) : s_(s) {}
    void ola() { std::cout << "Olá do B - " << s_ << std::endl; }

private:
    std::string s_;
};

class C {
public:
    C(const std::string& s) : s_(s) {}
    void hola() { std::cout << "Hola do C - " << s_ << std::endl; }

private:
    std::string s_;
};

template <class T>
T load(const char* filename);

template <>
A load(const char* filename) {
    return A(filename);
}

template <>
B load(const char* filename) {
    return B(filename);
}

template <>
C load(const char* filename) {
    return C(filename);
}

int main() {
    A a = load<A>("Haduken");
    a.hello();
    B b = load<B>("HARUKEN!");
    b.ola();
    C c = load<C>("Yahuken");
    c.hola();
    return 0;
}
