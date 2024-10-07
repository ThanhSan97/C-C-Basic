#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx;

void task_with_unique_lock(int id) {
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock); // Tạo unique_lock nhưng không khóa ngay

    std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));

    if (lock.try_lock()) { // Thử khóa mutex (không chờ)
        std::cout << "Task " << id << " acquired the lock" << std::endl;
    } else {
        std::cout << "Task " << id << " could not acquire the lock" << std::endl;
    }
}

int main() {
    std::thread t1(task_with_unique_lock, 1);
    std::thread t2(task_with_unique_lock, 2);

    t1.join();
    t2.join();

    return 0;
}
