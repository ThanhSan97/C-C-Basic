#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>


std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void showMessage()
{
    std::unique_lock<std::mutex> lock(mtx);

    cv.wait(lock, []{return ready;});
    std::cout << std::this_thread::get_id() << " is running!" << std::endl;
}

void setReady()
{
    std::unique_lock<std::mutex> lock(mtx);
    ready = true;
    std::cout << std::this_thread::get_id() << " is set ready!" << std::endl;
    cv.notify_one();
}

int main()
{
    std::thread t1(showMessage);
    std::thread t2(setReady);

    t1.join();
    t2.join();

    return 0;
}