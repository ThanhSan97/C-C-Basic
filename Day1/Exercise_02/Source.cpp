#include <stdio.h>

int main()
{
	int a = 5;
	int b = 10;
	int t = a;
	
	printf("Before\na = %d\nb = %d\n", a, b);
	a = b; b = t;
	printf("After\na = %d\nb = %d\n", a, b);

}