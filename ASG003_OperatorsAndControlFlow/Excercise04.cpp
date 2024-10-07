#include <stdio.h>
#include <math.h>

void changeValue(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    printf("Nhap a: ");
    scanf("%d",&a);
    printf("Nhap b: ");
    scanf("%d",&b);

    printf("Gia tri ban dau: a = %d, b = %d\n", a, b);
    changeValue(&a, &b);

    printf("Gia tri sau khi thay doi: a = %d, b = %d\n", a, b);


    return 0;
}