#include <iostream>
#include <string>
#include <ctype.h>


bool checkValid(std::string s)
{
    if(s.size() > 100)
        return false;

    for(int i = 0; i < s.size(); i ++)
    {
        if(isdigit(s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

void compareString()
{
    std::string s1, s2;
    while(1)
    {
        std::cout<<"Nhap chuoi 1: "; std::getline(std::cin, s1); 
        std::cout<<"Nhap chuoi 2: "; std::getline(std::cin, s2);

        bool b1 = checkValid(s1);
        bool b2 = checkValid(s2);
        std::cout<< "Check:" << b1 << "-" << b2 << std::endl;

        if(!b1 || !b2)
        {
            std::cout<<"Chuoi nhap vao khong hop le!\n";
            break;
        } 
        else
        {
            if(s1.compare(s2) >= 0)
            {
                std::cout<<"Chuoi can tim la: " << s1 << std::endl;
            } 
            else
            {
                std::cout<<"Chuoi can tim la: " << s2 << std::endl;
            }
        }
    }
}

int main()
{
    compareString();
    return 0;
}