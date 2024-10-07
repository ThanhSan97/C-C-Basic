#include <iostream>
#include "math_library.h" 

int main() {
    int a = 10, b = 5;

    std::cout << "Addition: " << add(a, b) << std::endl;
    std::cout << "Subtraction: " << subtract(a, b) << std::endl;
    std::cout << "Multiplication: " << multiply(a, b) << std::endl;

    try {
        std::cout << "Division: " << divide(a, b) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
