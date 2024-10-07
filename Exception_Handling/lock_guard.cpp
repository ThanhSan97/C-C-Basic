#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; 
void printEvenNumbers(int n) {
    for (int i = 0; i <= n; i += 2) {
        std::lock_guard<std::mutex> lock(mtx); 
        std::cout << "Even: " << i << std::endl;
   
    }
}

void printOddNumbers(int n) {
    for (int i = 1; i <= n; i += 2) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Odd: " << i << std::endl;
    }
}

int main() {
    std::thread t1(printEvenNumbers, 10);
    std::thread t2(printOddNumbers, 10);  

    t1.join();
    t2.join();
    return 0;
}
