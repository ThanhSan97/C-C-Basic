#include <iostream>

using namespace std;


class MyString
{
private:
    char *str;
    int length;

public:

    MyString()
    {
        str = nullptr;
        length = 0;
    }

    //Constructor
    MyString(char *str1) //char s[10] = "xasjda"; MyString str(s);
    {
        length = 0;
        while ( str1[length] != '\0')
        {
            length++;
        }

        str = new char[length + 1];
        for(int i = 0; i < length; i++)
        {
            str[i] = str1[i];
        }
        str[length] = '\0';        
    }

    //Copy constructor
    MyString(MyString &str1) //MyString str1; .... MyString str2(str1);
    {
        length = str1.length;

        str = new char[length + 1];
        for(int i = 0; i < length; i++)
        {
            str[i] = str1.str[i];
        }
        str[length] = '\0';    
    }

    // ~MyString() {
    //     delete[] str;
    // }

    void input()
    {
        char temp[1000];

        cout << "Nhap chuoi: ";
        cin.getline(temp, 1000);

        length = 0;
        while ( temp[length] != '\0')
        {
            length++;
        }

        str = new char[length + 1];
        for(int i = 0; i < length; i++)
        {
            str[i] = temp[i];
        }
        str[length] = '\0';      
    }

    void showString()
    {
        if(str)
        {
            cout << str << endl;
        } 
        else
        {
            cout << "Chuoi rong!" << endl;
        }
    }

    void clear()
    {
        delete[] str;
        str = nullptr;
        length = 0;
    }

    MyString operator+(const MyString& other)
    {
        MyString newString;
        int newLength = length + other.length + 1; //Tinh them dau space giua 2 chuoi

        newString.length = newLength;
        newString.str = new char[ newString.length + 1];

        //ghep chuoi goc
        for(int i = 0; i < length; i++)
        {
            newString.str[i] = str[i];
        }

        int index = length;
        newString.str[index] = ' ';  

        for(int i = 0; i < other.length; i++)
        {
            newString.str[index + i + 1] = other.str[i];
        }

        newString.str[newLength] = '\0';
        return newString;
    }

    bool operator==(MyString &other)
    { 
        if(length != other.length)
        {
            return false;
        } 

        for(int i = 0; i < length; i++)
        {
            if(str[i] != other.str[i])
            {
                return false;
            }
        } 

        return true;

    }

    void reverse()
    {
        for(int i = 0; i < length / 2; i++)
        {
            char temp = str[i];
            str[i] = str[length - i - 1];
            str[length - i - 1] = temp;
        }
    }

    int size()
    {
        return length;
    }

};

int main()
{
    // char s[10] = "xin chao";
    MyString str1, str2;
    //Nhap chuoi 1
    str1.input();
    str1.showString();

    // Dao chuoi 1
    // str1.reverse();

    //Nhap chuoi 2
    str2.input();
    str2.showString();

    //So sanh 2 chuoi
    cout << "So sanh chuoi: " << ((str1 == str2)? "Hai chuoi bang nhau" : "Hai chuoi khac nhau") << endl;

    //ghep chuoi
    cout << "Ghep 2 chuoi 1 va chuoi 2." << endl;
    MyString str3;
    str3 = str1 + str2;
    cout << "Chuoi ghep: ";
    str3.showString();    

    cout<< "Dao chuoi: ";
    str3.reverse();    
    str3.showString();    
    cout << str3.size();

}