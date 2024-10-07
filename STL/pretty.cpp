#include <iostream>
#include <deque> 
#include <vector>
using namespace std;
void printKMax(int arr[], int n, int k){
    deque<int> de;
    for(int i = 0; i < n; i++)  
    {
       if(!de.empty() && de.front() == i - k)
        {
            de.pop_front();
        }
        while(!de.empty() && arr[de.back()] <= arr[i])
        {
            de.pop_back();
        }
        de.push_back(i);
        if(i >= k - 1)
        {
            cout << arr[de.front()] << " ";
        }
    }
    cout << endl;  
}

int main()
{
    int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
    return 0;
}