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
    string pid, name;
    int yearOfBirth;

public:
    Human()
    {
        pid = "";
        name = "";
        yearOfBirth = 0;
    }

    Human(string _pid, string _name, int _year)
    {
        pid = _pid;
        name = _name;
        yearOfBirth = _year;
    }

    string getName()
    {
        return name;
    }

    void input()
    {
        cout <<"Nhap CMND: "; getline(cin, pid);
        cout <<"Nhap ho va ten: "; getline(cin, name); mtoUpper(name);
        cout <<"Nhap nam sinh: "; cin >> yearOfBirth; cin.ignore();
    }

    void output()
    {
        cout <<"CMND: " << pid << endl;
        cout <<"Ho va ten: " << name << endl;
        cout <<"Nam sinh: " << yearOfBirth << endl;
    }

};


class Room
{
private:
    int roomNumber, type, price, numOfDays;

public:
    Room()
    {
        roomNumber = 0;
        type = 0;
        price = 0;
        numOfDays = 0;
    }

    Room(int _roomNumber, int _type, int _num){
        roomNumber = _roomNumber;
        type = _type;
        numOfDays = _num;
        price = getPrice(type);
    };

    int getPrice(int type)
    {
        switch (type)
        {
        case 1:
            return 500000;
            break;
        case 2:
            return 700000;
            break;
        case 3:
            return 1200000;
            break;
        
        default:
            return 0;
            break;
        }
    }

    string getType(int type)
    {
        switch (type)
        {
        case 1:
            return "Standard";
            break;
        case 2:
            return "Deluxe";
            break;
        case 3:
            return "Suite";
            break;
        
        default:
            return "None";
            break;
        }
    }

    int getRoomNumber()
    {
        return roomNumber;
    }

    void input()
    {
        cout <<"Nhap so phong: "; cin >> roomNumber;
        cout <<"Nhap loai phong (1: Standard, 2: Deluxe, 3: Suite): "; cin >> type;
        cout <<"Nhap so ngay thue: "; cin >> numOfDays;
        cin.ignore();

        //Tinh gia phong
        price = getPrice(type);

    }

    void output()
    {
        cout <<"So phong: " << roomNumber << endl;
        cout <<"Loai phong: " << type << " (" << getType(type) <<")"<< endl;
        cout <<"Gia phong: " << price << endl;
        cout <<"So ngay thue: " << numOfDays << endl;
    }

    void payment()
    {
        output();
        int pay = numOfDays * price;
        cout << "Tong tien: " << pay << endl;
    }

};

class Hotel
{
private:
    int numOfRoomer;
    Human *roomer;
    Room *room;

public:

    Hotel()
    {
        numOfRoomer = 0;
        roomer = nullptr;
        room = nullptr;
    };

    void input()
    {
        cout << "Nhap so khach thue phong: "; cin >> numOfRoomer; cin.ignore();
        roomer = new Human[numOfRoomer];
        room = new Room[numOfRoomer];
    
        for(int i = 0; i < numOfRoomer; i++)
        {
            cout << "Nhap thong tin khach hang thu " << i + 1 << endl;
            roomer[i].input();
            room[i].input();
            cout << "-----------------------------------\n";
            
        }
    }

    void output()
    {
        cout << "===== Danh sach thue phong =====\n";
    
        for(int i = 0; i < numOfRoomer; i++)
        {
            cout << "Thong tin khach hang thu " << i + 1 << endl;
            roomer[i].output();
            room[i].output();
            cout << "-----------------------------------\n";
        }
    }

    void showPayment()
    {
        cout << "Nhap so phong can thanh toan: "; int num; cin >> num;
        int flag = 0;
        for(int i = 0; i < numOfRoomer; i++)
        {
            if(room[i].getRoomNumber() == num)
            {
                room[i].payment();
                flag = 1;
            }
        }
        if(flag == 0)
        {
            cout << "So phong can thanh toan khong ton tai\n";
        }
    }

    void findByRoomer(string _name)
    {
        string n = _name;
        mtoUpper(_name);
        int flag = 0;
        for(int i = 0; i < numOfRoomer; i++)
        {
            if(roomer[i].getName() == _name)
            {
                cout << "Thong tin khach hang co ten: " << _name << endl;
                roomer[i].output();
                room[i].output();
                flag = 1;
            }
        }

        if(flag == 0)
        {
            cout << "Khong tim thay khach hang co ten " << _name << endl;
        }
    }

};

int main()
{
    Hotel ht;
    ht.input();
    ht.output();
    ht.showPayment();
    ht.findByRoomer("Thanh SAN");
    return 0;
}