#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>


using namespace std;


void mtoUpper(string &str)
{
    for (int i = 0; i < str.length(); ++i) {
        str[i] = std::toupper(str[i]);
    }
}


class Human
{
private:
    string pid, name, job;
    int age, yearOfBirth;

public:
    Human()
    {
        pid = "";
        name = "";
        age = 0;
        yearOfBirth = 0;
        job = "";
    }

    Human(string _pid, string _name, int _age, int _year, string _job)
    {
        pid = _pid;
        name = _name;
        age = _age;
        yearOfBirth = _year;
        job = _job;
    }

    string getName()
    {
        return name;
    }

    void input()
    {
        cout <<"Nhap CMND: "; getline(cin, pid);
        cout <<"Nhap ho va ten: "; getline(cin, name); mtoUpper(name);
        cout <<"Nhap tuoi: "; cin >> age; cin.ignore();
        cout <<"Nhap nam sinh: "; cin >> yearOfBirth; cin.ignore();
        cout <<"Nhap nghe nghiep: "; getline(cin, job);
        
    }

    void output()
    {
        cout <<"CMND: " << pid << endl;
        cout <<"Ho va ten: " << name << endl;
        cout <<"Tuoi: " << age << endl;
        cout <<"Nam sinh: " << yearOfBirth << endl;
        cout <<"Nghe nghiep: " << job << endl;
    }
};

class House
{
private:
    int numOfMember, houseNumber;
    Human * members;

public:
    House()
    {
        numOfMember = 0;
        houseNumber = 0;
        members = nullptr;
    }

    int getHouseNumer()
    {
        return houseNumber;
    }

    int getNumOfMember()
    {
        return numOfMember;
    }

    void input()
    {
        cout << "Nhap so nha: "; cin >> houseNumber;
        cout << "Nhap so thanh vien: "; cin >> numOfMember; cin.ignore();
        members = new Human[numOfMember];

        for(int i = 0; i < numOfMember; i++)
        {
            cout << "Nhap thong tin cho thanh vien thu " << i + 1 << endl;
            members[i].input();
        }
    }

    void showMember()
    {
        cout << "So nha: " << houseNumber << endl;
        for(int i = 0; i < numOfMember; i++)
        {
            cout << "Thong tin cua thanh vien thu " << i + 1 << endl;
            members[i].output();
        }
    }

    int findMember(string _name)
    {
        for(int i = 0; i < numOfMember; i++)
        {   
            if(members[i].getName() == _name)
            {
                return i;
            }
        }  
        return -1; 
    }
};

class Town 
{
private:
    int numOfHouse;
    House *houses;

public:
    Town()
    {
        numOfHouse = 0;
        houses = nullptr;
    }

    void createTown()
    {
        cout << "Nhap so ho dan: "; cin >> numOfHouse;
        houses = new House[numOfHouse];
        for(int i = 0; i < numOfHouse; i++)
        {
            cout << "Nhap thong tin ho dan thu " << i + 1 << endl;
            houses[i].input();
        }
    }

    void showTown()
    {
        cout << "THONG TIN TO DAN PHO" << endl;
        for(int i = 0; i < numOfHouse; i++)
        {
            cout << "Thong tin ho dan thu " << i + 1 << endl;
            houses[i].showMember();
        }
    }

    void findByHouseNumber(int num)
    {
        int i;
        for(i = 0; i < numOfHouse; i++)
        {
            if(houses[i].getHouseNumer() == num)
            {
                break;
            }
        }
        if(i < numOfHouse)
        {
            cout << "Thong tin ho dan co so nha: " << num << endl;;
            houses[i].showMember();
        } 
        else
        {
            cout << "Khong tim thay thong tin ho dan co so nha: " << num << endl;;
        }
    }

    void findByMemberName(string _name)
    {
        string n = _name;
        mtoUpper(_name);
        int i;
        for(i = 0; i < numOfHouse; i++)
        {
            if(houses[i].findMember(_name) != -1)
            {
                break;
            }
        }

        if(i < numOfHouse)
        {
            cout << "Thong tin ho dan co thanh vien co ten la: " << n << endl;;
            houses[i].showMember();
        } 
        else
        {
            cout << "Khong tim thay thong tin ho dan co thanh vien co ten: " << n << endl;;
        }
    }
};


int main()
{
    Town town;
    town.createTown();
    town.showTown();

    town.findByHouseNumber(125);

    town.findByMemberName("sAn");

    return 0;
}