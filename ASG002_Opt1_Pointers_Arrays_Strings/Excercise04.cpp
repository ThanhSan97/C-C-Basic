#include <iostream>

void deleteK(int *arr, int &n, int k) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }
}


int minOdd(int arr1[], int arr2[], int &m, int &n)
{
    int minO = INT_MAX;
    int numArr = 1;
    for(int i = 0; i < m; i++)
    {
        if(arr1[i] % 2 != 0)
            if(arr1[i] < minO)
            {
                minO = arr1[i];
                numArr = 1;
            }
    }
     
    for(int i = 0; i < n; i++)
    {
        if(arr2[i] % 2 != 0)
            if(arr2[i] < minO)
            {
                minO = arr2[i];
                numArr = 2;
            }
    }
    if(numArr == 1)
    {
        deleteK(arr1, m, minO);
    } 
    else
    {
        deleteK(arr2, n, minO);
    }

    return minO;
}

int minEven(int arr1[], int arr2[], int &m, int &n)
{
    int minE = INT_MAX;
    int numArr = 1;
    for(int i = 0; i < m; i++)
    {
        if(arr1[i] % 2 == 0)
            if(arr1[i] < minE)
            {
                minE= arr1[i];
                numArr = 1;
            }
                
    }
     
    for(int i = 0; i < n; i++)
    {
        if(arr2[i] % 2 == 0)
            if(arr2[i] < minE)
            {
                minE = arr2[i];
                numArr = 2;
            }
    }

    if(numArr == 1)
    {
        deleteK(arr1, m, minE);
    } 
    else
    {
        deleteK(arr2, n, minE);
    }

    return minE;
}

int countOdd(int arr1[], int arr2[], int m, int n)
{
    int count = 0;
    for(int i = 0; i < m; i++)
    {
        if(arr1[i] % 2 != 0)
            count++;
    }
    for(int i = 0; i < n; i++)
    {
        if(arr2[i] % 2 != 0)
            count++;
    }
    return count;
}

int countEven(int arr1[], int arr2[], int m, int n)
{
    int count = 0;
    for(int i = 0; i < m; i++)
    {
        if(arr1[i] % 2 == 0)
            count++;
    }
    for(int i = 0; i < n; i++)
    {
        if(arr2[i] % 2 == 0)
            count++;
    }
    return count;
}



void mergeArray()
{
    int arr1[2021], arr2[2021];
    int m, n;

    while (1)
    {
        std::cout << "Nhap m: "; std::cin >> m; std::cout<<std::endl;
        std::cout << "Nhap n: "; std::cin >> n; std::cout<<std::endl;

        if(m == 0 && n == 0)
        {
            std::cout<<"STOP";
            break;
        }
        std::cout<<"Nhap mang 1 co " << m << " phan tu:";
        for(int i = 0; i < m; i++)
        {
            std::cin>> arr1[i];
        }

        std::cout<< std::endl;

        std::cout<<"Nhap mang 2 co " << n << " phan tu";
        for(int i = 0; i < n; i++)
        {
            std::cin>> arr2[i];
        }

        int numEven = countEven(arr1, arr2, m, n);
        int numOdd  = countOdd(arr1, arr2, m, n);

        int subEvenOdd = abs(numEven - numOdd);
        
        int arr[4041];
        int index;

        
        //Merge Odd - Even
        for(index = 0; index < subEvenOdd; index++)
        {
            if((index+1) % 2 != 0)
            {
                arr[index] = minOdd(arr1, arr2, m, n);
            }
            else
            {
                arr[index] = minEven(arr1, arr2, m, n);
            }
        }

        //Add num-left
        for(int i = 0; i < m; i++)
        {
            arr[index] = arr1[i];
            index++;
        }
        for(int i = 0; i < n; i++)
        {
            arr[index] = arr2[i];
            index++;
        }

        //Output
        std::cout<<"Output: \n";
        for(int i = 0; i < index; i++)
        {
            std::cout<< arr[i] << " ";
        }
        std::cout<<std::endl;

    }
}

int main()
{
    mergeArray();
    return 0;
}