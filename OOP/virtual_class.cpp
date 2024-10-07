#include <iostream>

class A {
public:
    int value;

    A() : value(10) {}

    void print() {
        std::cout << "A::value = " << value << std::endl;
    }
};

class B : virtual public A {
public:
    B() {
        value = 20;
    }
};

class C : virtual public A {
public:
    C() {
        value = 30;
    }
};

class D : public B, public C {};

int main() {
    D obj;
    obj.print();
    return 0;
}