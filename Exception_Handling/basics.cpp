#include <iostream>

using namespace std;

double devide(int a, int b)
{
    if(b == 0)
        throw "Division by zeros!";
    return a/b;
}   

int main()
{
    int a = 3, b = 0;
    double z = 0;

    try
    {
       z = devide(a, b);
       cout << z << endl;
    }
    catch(const char * msg)
    {
        cerr << msg<< endl;
    }
    
    return 0;
}