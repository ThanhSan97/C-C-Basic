#include <stdio.h>
#include <math.h>

void firstOderEquation(int a, int b)
{
   printf("---- GIAI PHUONG TRINH BAC 1 ----\n");
   float x = -b / a;
   printf("Nghiem cua phuong trinh la: %.2f\n", x);
}

int main()
{
    int a, b;
    do
    {
        printf("Nhap he so a (ax + b = 0)(a != 0): ");
        scanf("%d",&a);
        if(a == 0)
        {
            printf("He so a = %d. Vui long nhap lai!\n", a);
        }
    } while (a == 0);
   
    printf("Nhap he so b (ax + b = 0): ");
    scanf("%d",&b);
    firstOderEquation(a, b);

    return 0;
}