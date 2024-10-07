#include <iostream>
#include <string>

using namespace std;

class maytinh
{
    private: 
        int *data;
    public:
        maytinh(int value){
            data = new int;
            *data = value;
            cout << "Constructor: Cap phat bo nho cho data va gan gia tri cho data = " << *data << endl;
        }
        ~maytinh(){
            cout<< "Giet data = " << *data << endl;
            delete(data);
        }
        void display(){
            cout << "Gia tri cua data: " << *data << endl;
        }
};

int main()
{
    maytinh mt1(10);
    mt1.display();
    {
        maytinh mt2(20);
        mt2.display();
    }
    return 0;
}