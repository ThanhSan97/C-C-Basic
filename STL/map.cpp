#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string name;
        int point;

        int choice;
        cin >> choice;
        
        if (choice == 1)
        {
            cin >> name >> point;
            m[name] += point;
        }
        else if (choice == 2)
        {
            cin >> name;
            m.erase(name);
        }
        else
        {
            cin >> name;
            cout << m[name] << endl;
        }
    }
    return 0;
}
