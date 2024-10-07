#include <iostream>
#include <string>
using namespace std;

class ThiSinh
{
public:
    struct HovaTen
    {
        char ho[10];
        char tendem[20];
        char ten[10];
    };
    
    struct QueQuan
    {
        char xa[20];
        char huyen[20];
        char tinh[20];
    };

    struct DiemThi
    {
        float toan, ly, hoa;
    };

    HovaTen ht;
    QueQuan qq;
    char truong[20];
    int tuoi;
    char sbd[5];
    DiemThi dt;
    
    void input()
    {
        fflush(stdin);
        cout << "Nhap ho: "; cin.getline(ht.ho, 10);
        cout << "Nhap ten dem: "; cin.getline(ht.tendem, 20);
        cout << "Nhap ten: "; cin.getline(ht.ten, 10);

        cout << "Nhap truong: "; cin.getline(truong, 20);
        cout << "Nhap tuoi: "; cin>>tuoi;
        fflush(stdin);
        cout << "Nhap SBD: "; cin.getline(sbd, 5);

        cout << "Nhap xa: "; cin.getline(qq.xa, 20);
        cout << "Nhap huyen: ";  cin.getline(qq.huyen, 20);
        cout << "Nhap tinh: ";  cin.getline(qq.tinh, 20);

        cout << "Nhap diem toan: "; cin >> dt.toan;
        cout << "Nhap diem ly: "; cin >> dt.ly;
        cout << "Nhap diem hoa: "; cin >> dt.hoa;
    }

    void output()
    {
        cout << "Ho va ten: " << ht.ho << " " << ht.tendem << " " << ht.ten << endl;
        cout << "Que quan: Xa " << qq.xa << " - Huyen " << qq.huyen << " - Tinh " << qq.tinh << endl;
        cout << "So bao danh: " << sbd << endl;
        cout << "Diem toan: " << dt.toan << endl;
        cout << "Diem ly: " << dt.ly << endl;
        cout << "Diem diem hoa: " << dt.hoa << endl;
    }
    
};

void nhapDanhSachThiSinh(ThiSinh *ts, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<"Nhap thong tin cho thi sinh thu " << i + 1 << ":" << endl;
        ts[i].input();
    }
}

void xuatDanhSachThiSinh(ThiSinh *ts, int n)
{
    cout <<"------- Danh sach thi sinh --------" << endl;
    for(int i = 0; i < n; i++)
    {
        cout<<"Thong tin cho thi sinh thu " << i + 1 << ":" << endl;
        ts[i].output();
    }
}

void lonHon15(ThiSinh *ts, int n)
{   
    cout <<"------- Danh sach thi sinh co tong diem > 15--------" << endl;
    for(int i = 0; i < n; i++)
    {
        if( (ts[i].dt.toan + ts[i].dt.ly + ts[i].dt.hoa) > 15)
        {
            ts[i].output();
        }
    }
}

void swap(ThiSinh *a, ThiSinh *b)
{
    ThiSinh temp = *a;
    *a = *b;
    *b = temp;
}
void sapxep(ThiSinh *dsts, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        float sum1 = dsts[minIndex].dt.toan + dsts[minIndex].dt.ly + dsts[minIndex].dt.hoa;
            for (int j = i + 1; j < n; j++) {
                float sum2 = dsts[j].dt.toan + dsts[j].dt.ly + dsts[j].dt.hoa;
                if (sum2 > sum1) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(dsts[i], dsts[minIndex]);
            }
    }

    xuatDanhSachThiSinh(ts, n);
}

int main()
{
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;

    ThiSinh* danhSachThisinh = new ThiSinh[n];
    
    nhapDanhSachThiSinh(danhSachThisinh, n);
    lonHon15(danhSachThisinh, n);
    sapxep(danhSachThisinh, n);
    
    return 0;
}