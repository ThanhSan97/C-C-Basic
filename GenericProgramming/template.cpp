#include <iostream>
#include <string>

using namespace std;

template <typename T>
T findMax(T a, T b)
{
    return (a > b)? a : b;
}

int main()
{
    int a = findMax(2, 10);
    cout << a << endl;

    double b = findMax(2.2, -4.3);
    cout << b << endl;

    string s = findMax("abcad", "aaaaa");
    cout << s << endl;

}