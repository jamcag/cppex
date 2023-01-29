#include <chrono>
#include <iostream>
#include <thread>

int main() {
    using namespace std::chrono_literals;
    std::cout << "Loading..." << std::flush;
    std::this_thread::sleep_for(2500ms);
    std::cout << "\r";
    std::cout << "Loading done\n";
}
