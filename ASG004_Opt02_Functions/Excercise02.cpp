#include <stdio.h>

unsigned int reverse(unsigned int n)
{
    unsigned int num = 0;
    do
    {
        num = num * 10 + n%10;
        n /= 10;
    }
    while(n > 0);
    return num;
}

int main()
{
    int n = 123;
    printf("Reverse of %d is %d\n", n, reverse(n));

}