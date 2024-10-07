#include <iostream>
#include <thread>
#include <mutex>
std::mutex mtx;
int count = 0;
void increaseCount()
{
    std::cout << "Thread " << std::this_thread::get_id() << " is in function." << std::endl;
    for(int i = 0; i < 5; i++)
    {
        if(mtx.try_lock())
        {
            std::cout << "Thread " << std::this_thread::get_id() << " is incrementing count." << std::endl;
            ++count;
            mtx.unlock();
        }
    }
}
int main()
{
    std::thread t1(increaseCount);
    std::thread t2(increaseCount);

    t1.join();
    t2.join();

    std::cout << count << std::endl;
    std::cout << "Thread " << std::this_thread::get_id() << " is end." << std::endl;
    return 0;
}

