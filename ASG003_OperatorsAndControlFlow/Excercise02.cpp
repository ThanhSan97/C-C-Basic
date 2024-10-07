#include <stdio.h>
#include <math.h>

bool checkPrime(int n)
{
    if(n <= 1)
    {
        return true;
    }
    for(int i = 2; i < sqrt(n); i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);

    if(checkPrime(n))
    {
        printf("%d la so nguyen to\n",n);
    }
    else
    {
        printf("%d khong phai la so nguyen to\n", n);
    }

    return 0;
}