#include <iostream>
#include <string>

void compareString(std::string a, std::string b)
{
    if(a.size() > b.size())
        std::cout << "String 1: " << a << std::endl;
    else if (a.size() == b.size())
    {
        std::cout << "Equal length!";
    } 
    else
    {
        std::cout << "String 2: " << b << std::endl;
    }

}

int main()
{

    std::string a, b;
    std::cout<<"Nhap chuoi 1:";
    std::cin>> a;
    std::cout << std::endl;

   std::cout<<"Nhap chuoi 2:";
    std::cin>> b;
    std::cout << std::endl;

    compareString(a,b);

    return 0;
}