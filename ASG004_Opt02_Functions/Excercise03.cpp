#include <stdio.h>

bool isPerfect(int n)
{
    int sum = 0;
    for(int i = 1; i < n; i++)
    {
        if(n % i == 0)
        {
            sum += i;
        }
    }

    if(sum == n)
        return true;
    return false;
}

int main()
{
    int n = 6;
    if(isPerfect(n))
        printf("%d la so hoan hao!\n", n);
    else
        printf("%d khong phai la so hoan hao!", n);

    return 0;
}