#include <iostream>
#include <string>

class A {
public:
    A(const std::string& s) : s(s) {}
    void hello() { std::cout << "Hello from A - " << s << std::endl; }

private:
    std::string s;
};

class B {
public:
    B(const std::string& s) : s(s) {}
    void ola() { std::cout << "Olá do B - " << s << std::endl; }

private:
    std::string s;
};

class C {
public:
    C(const std::string& s) : s(s) {}
    void hola() { std::cout << "Hola do C - " << s << std::endl; }

private:
    std::string s;
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
