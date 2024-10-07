#include <iostream>
#include <string>
using namespace std;

class Goods
{
public:
    char gId[5];
    char gName[30];
    char gUnit[10];
    float gPrice, gValue;
    int numOfGoods;
    virtual void input()
    {
        cout << "Input code: ";
        cin >> this->gId;
        cout << "Input name: ";
        cin >> this->gName;
        cout << "Input unit: ";
        cin >> this->gUnit;
        cout << "Input price: ";
        cin >> this->gPrice;
        cout << "Input number of Goods: ";
        cin >> this->numOfGoods;
    }
    void payment()
    {
        gValue = gPrice * numOfGoods;
    }
    virtual void output()
    {
        cout <<"--- GOODS INFORMATION ---" << endl;
        cout << "Goods code: " << gId << endl;
        cout << "Goods name: " << gName << endl;
        cout << "Goods unit: " << gUnit << endl;
        cout << "Goods price: " << gPrice << "$" << endl;
        cout << "Goods number of Goods: " << numOfGoods << endl;
        cout<< "Paymet needed: " << gValue << "$" << endl;
    }

    
};

class newGoods : public Goods
{
public:
    void input() override
    {
        Goods::input();
        cout << "Input shipping Unit Price: ";
        cin >> this->shippingUnitPrice;
    }

    void transportationCosts()
    {
        transCost = shippingUnitPrice * numOfGoods;
    }

    void output() override
    {
        Goods::output();
        cout << "Shipping Unit Price: " << shippingUnitPrice << "$" << endl;
        cout << "Transportation cost: " << transCost << "$" << endl;
        cout <<"---------------------------" << endl;
        cout << "Total payment: " << transCost + gValue << "$" << endl;
    }

private:
    float shippingUnitPrice, transCost;
};

int main()
{
    newGoods ng;
    ng.input();
    ng.payment();
    ng.transportationCosts();
    ng.output();

    return 0;
}