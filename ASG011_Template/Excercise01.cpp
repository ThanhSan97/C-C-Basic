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
class STACK 
{
private:
    T *arr;
    int top;
    int capacity;
public:
   STACK(int size = 10) {
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    void push(const T& data) {
        if (isFull()) {
            std::cout << "Stack is full. Cannot push data." << std::endl;
            return;
        }
        arr[++top] = data;
    }

    T pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop data." << std::endl;
            return T(); // Trả về giá trị mặc định của T
        }
        return arr[top--];
    }

    T peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot peek data." << std::endl;
            return T();
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        for (int i = 0; i <= top; ++i) {
            arr[i].display(); 
        }
    }

};


int main()
{
    STACK<Student> student(5);
    student.push(Student("Daxua", 101));
    student.push(Student("Nat-su", 175));
    student.push(Student("Yone", 200));

    student.display();

    //Peek
    Student s = student.peek();
    s.display();

    //Pop
    Student s1 = student.pop();
    s1.display();

    Student s2 = student.pop();
    s2.display();

    return 0;
}