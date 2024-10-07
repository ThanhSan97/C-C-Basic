#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int q; cin >> q; 
    set<int>s;
    
    for(int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        if(x == 1)
        {
            s.insert(y);
        }
        else if(x == 3)
        {
            if(s.count(y))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }   
    return 0;
}



