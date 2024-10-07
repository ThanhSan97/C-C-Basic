#include <iostream>
using namespace std;

class Customer
{

public:
    char hovaten[50];
    char masocontor[10];
    int sonha;

    virtual void input()
    {
        fflush(stdin);
        cout<< "Nhap ho va ten: "; cin.getline(hovaten, 50);
        cout<<"Nhap so nha: "; cin>>sonha;
        fflush(stdin);
        cout<<"Nhap ma so contor: "; cin.getline(masocontor, 10);
    }

    virtual void output()
    {
        cout<<"Ho va ten: " << hovaten << endl;
        cout<<"So nha: " << sonha << endl;
        cout<<"Ma so contor: " << masocontor << endl;
    }
};

class Receipt : public Customer
{

private:
    int chiSoCu, chiSoMoi;
    float soTien;

public:
    
    void input() override
    {
        Customer::input();
        cout<<"Nhap chi so cu: "; cin >> chiSoCu;
        cout<<"Nhap chi so moi: "; cin>> chiSoMoi;
        tinhTongTien();
    }

    void output() override
    {
        Customer::output();
        cout<<"Chi so cu: " << chiSoCu << endl;
        cout<<"Chi so moi: " << chiSoMoi << endl;
        cout<<"Tong tien: " << soTien << endl;
    }

    void tinhTongTien()
    {
        int soDien = chiSoMoi - chiSoCu;
        if(soDien < 50)
        {
            soTien = soDien * 1250;
        } 
        else if(50 <= soDien && soDien < 100)
        {
            soTien = soDien * 1500;
        } 
        else
        {
            soTien = soDien * 2000;
        }
    
    }

};

void nhapDanhSachBienLai(Receipt *rep, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"Nhap thong tin cho bien lai thu " << i + 1 << ":" << endl;
        rep[i].input();
    }
}

void xuatDanhSachBienLai(Receipt *rep, int n)
{
    cout <<"------- Danh sach bien lai --------" << endl;
    for(int i = 0; i < n; i++)
    {
        cout<<"Thong tin bien lai thu " << i + 1 << ":" << endl;
        rep[i].output();
    }
}

int main()
{
    int n;
    cout<<"Nhap n: "; cin>> n;

    Receipt *danhSachBienLai = new Receipt[n];
    nhapDanhSachBienLai(danhSachBienLai, n);
    xuatDanhSachBienLai(danhSachBienLai, n);

    return 0;
}