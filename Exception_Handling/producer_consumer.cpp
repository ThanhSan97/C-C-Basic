#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

mutex mtx;
condition_variable cv_producer, cv_consumer;
queue<int> buffer;
const unsigned int MAX_BUFFER_SIZE = 5;

void producer(int id)
{
    int product = 0;
    while(1)
    {
        //Mutex lock tai nguyen
        unique_lock<mutex> lock(mtx);

        //Cho den khi buffer con cho trong
        cv_producer.wait(lock, []{return buffer.size() < MAX_BUFFER_SIZE;});

        //san xuat
        product++;
        buffer.push(product);
        cout << "Producer " << id << " produced " << product << endl;

        //Thong bao cho consumer
        cv_producer.notify_all();
        lock.unlock();
    }
}

void consumer(int id)
{
    while (1)
    {
        //lock
        unique_lock<mutex> lock(mtx);

        //wait
        cv_consumer.wait(lock, []{return !buffer.empty();});
        int product = buffer.front();
        buffer.pop();
        cout << "Consumer " << id << " comsumed " << product << endl;
        //thong baos
        cv_consumer.notify_all();

        lock.unlock();
    }
    
}

int main()
{
    thread producer1(producer, 1);
    thread producer2(producer, 2);
    thread consumer1(consumer, 1);
    thread consumer2(consumer, 2);

    producer1.join();
    producer2.join();
    consumer1.join();
    consumer2.join();

    return 0;
}

