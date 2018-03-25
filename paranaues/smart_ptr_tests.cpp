#include <iostream>
#include <memory>

#include <boost/smart_ptr/make_shared.hpp>

using namespace std;

std::string global_from;

class A {
public:
    A() {
        from_ = global_from;
        std::cout << from_ << " - " << "A()" << std::endl;
    }
    virtual ~A() {
        std::cout << from_ << " - " << "~A()" << std::endl;
    }
private:
    std::string from_{};
};

int main() {
    global_from = "Unique";
    std::unique_ptr<A[]> auptr = std::make_unique<A[]>(5);

    global_from = "Shared";
    boost::shared_ptr<A[]> asptr = boost::make_shared<A[]>(5);

    return 0;
}
