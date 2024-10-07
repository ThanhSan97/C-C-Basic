#include <stdio.h>



int main()
{
    int* p = new int;
    *p = 10;
    printf("Dia chi cua p: %p\n", p);
    printf("Gia tri cua p: %d\n", *p);

    int *q;
    q = p;

    printf("Luc chua giai phong p!\n");
    printf("Dia chi cua q: %p\n", q);
    printf("Gia tri cua q: %d\n", *q);

    delete(p);

    printf("Luc da giai phong p!\n");

    printf("Dia chi cua q: %p\n", q);
    printf("Gia tri cua q: %d\n", *q);

    if(*p == NULL)
    {
        printf("NULL");
    }
    else
    {
        printf("Khac NULL");
    }

    return 0;
}