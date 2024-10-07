#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    std::string name;
    int id;

    Student() : name(""), id(0) {}
    Student(std::string name, int id) : name(name), id(id) {}

    void display() const {
        std::cout << "Student Name: " << name << ", ID: " << id << std::endl;
    }
};


template <typename T>
class QUEUE 
{
private:
    T *arr;
    int head, tail;
    int capacity;
public:
   QUEUE(int size = 10) {
        arr = new T[size];
        capacity = size;
        head = 0;
        tail = 0;
    }

    void Enqueue(const T& data) {
        if (isFull()) {
            cout << "Queue is full. Can not push data." << endl;
            return;
        }
        arr[tail++] = data;
    }

    T Dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Can not pop data." << endl;
            return T(); // Trả về giá trị mặc định của T
        }
        return arr[head++];
    }

    T peek() const {
        if (isEmpty()) {
            cout << "Queue is empty. Can not peek data." << endl;
            return T();
        }
        return arr[head];
    }

    bool isEmpty() const {
        return head == tail;
    }

    bool isFull() const {
        return tail == capacity;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        for (int i = head; i < tail; ++i) {
            arr[i].display(); 
        }
    }

};


int main()
{
    QUEUE<Student> student(5); 
    student.Enqueue(Student("Daxua", 101)); //
    student.Enqueue(Student("Nat-su", 175));
    student.Enqueue(Student("Yone", 200));
    student.Enqueue(Student("Bard",345));
    student.Enqueue(Student("Zoe", 222)); // -> Full

    student.display();

    //Peek
    Student s = student.peek();
    s.display();

    // //Pop
    Student s1 = student.Dequeue();
    s1.display();

    Student s2 = student.Dequeue();
    s2.display();

    return 0;
}