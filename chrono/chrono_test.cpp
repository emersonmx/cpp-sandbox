#include <iostream>
#include <chrono>

using namespace std;

int64_t getCurrentTime() {
    auto now = chrono::high_resolution_clock::now();
    auto d = now.time_since_epoch();
    return chrono::duration_cast<chrono::microseconds>(d).count();
}

int main() {
    std::cout << getCurrentTime() << std::endl;
    std::cout << getCurrentTime() << std::endl;
    return 0;
}
