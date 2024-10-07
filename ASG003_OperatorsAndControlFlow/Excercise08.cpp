#include <stdio.h>
#include <math.h>

int GCD(int a, int b)
{
    for (int i = a; i > 0; i--)
    {
        if(a % i == 0)
        {
            if(b % i == 0)
            {
                return i;
            }
        }
    }
    return 1;
}

int LCM(int a, int b)
{
    if(a > b)
    {
        for(long long i = a; i < a*b; i++)
        {
            if(i % a == 0)
            {
                if(i % b == 0)
                {
                    return i;
                }
            }
        }
    }

    return a * b;
}

int main()
{
    int a, b;
    do
    {
        printf("Nhap a (a >= 1): ");
        scanf("%d", &a);
        if (a < 1)
        {
            printf("a = %d < 1. Vui long nhap lai!\n", a);
        }
    } while (a < 1);

    do
    {
        printf("Nhap b (b >= 1): ");
        scanf("%d", &b);
        if (b < 1)
        {
            printf("b = %d < 1. Vui long nhap lai!\n", b);
        }
    } while (b < 1);

    printf("GCD(%d, %d) = %d\n", a, b, GCD(a,b));
    printf("LCM(%d, %d) = %d\n", a, b, LCM(a,b));



    return 0;
}