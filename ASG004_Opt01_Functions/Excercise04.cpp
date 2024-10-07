#include <stdio.h>
#include <math.h>

void secondOderEquation(float a, float b, float c)
{
    float d = b * b - 4*a*c;

    if( d < 0)
    {
        printf("Phuong trinh vo nghiem\n");
    } 
    else if( d == 0)
    {
        printf("Phuong trinh chi co 1 nghiem la: x = %.3f\n", (-b / (2*a)));
    } 
    else
    {
        float x1 = (-b + sqrt(d)) / (2 * a);
        float x2 = (-b - sqrt(d)) / (2 * a);
        printf("Phuong trinh co 2 nghiem phan biet la: x1 = %.3f, x2 = %.3f\n", x1, x2);
    }
}

int main()
{
    while (1)
    {
        float a, b, c;
        printf("---- GIAI PHUONG TRINH BAC 2: ax^2 + bx + c = 0 ----\n");
        printf("-- Nhap a = 0, b = 0, c = 0 de thoat chuong trinh --\n");

        printf("Nhap he so a(a != 0): ");
        scanf("%f",&a);
        printf("Nhap he so b : ");
        scanf("%f",&b);
        printf("Nhap he so c: ");
        scanf("%f",&c);

        if(a == 0 && b == 0 && c == 0)
            break;
        secondOderEquation(a, b, c);
    }
    
    return 0;
}