#include <stdio.h>
#include <math.h>

long long fibonacci(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
    {
        return fibonacci(n - 1) + fibonacci(n-2);
    }
}

int main()
{
    int n;

    do
    {
        printf("Nhap n (n > 0): ");
        scanf("%d",&n);
        if(n <= 0)
        {
            printf("n <= 0%d. Vui long nhap lai!\n", n);
        }
    } while (n <= 0);

    printf("---- Day FIBONACCI ----\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    return 0;
}