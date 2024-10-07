#include <stdio.h>

unsigned int sumDigit(unsigned int n)
{
    unsigned int sum = 0;
    do
    {
        sum += n % 10;
        n /= 10;
    }
    while(n > 0);
    return sum;
}

int main()
{
    int n = 1992;
    printf("Sum digit of %d is %d\n", n, sumDigit(n));

}