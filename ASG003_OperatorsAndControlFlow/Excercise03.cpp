#include <stdio.h>
#include <math.h>

bool checkEven(int n)
{
    if( n % 2 == 0)
        return true;
    else
        return false;
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d",&n);

    if(checkEven(n))
    {
        printf("%d la so chan\n",n);
    }
    else
    {
        printf("%d la so le\n", n);
    }

    return 0;
}