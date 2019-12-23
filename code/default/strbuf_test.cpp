#include <iostream>
#include <sstream>

int main() {
    std::ostringstream message{};
    message << "Teste Lol";
    std::cout << message.str() << std::endl;
    return 0;
}
