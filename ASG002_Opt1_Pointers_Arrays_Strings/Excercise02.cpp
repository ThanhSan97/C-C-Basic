#include <stdio.h>
#include <stdlib.h>
#include <cctype>

void inputArrayExtend(char **p, int *n)
{
    int maxSize = 2;
    *n = 0;
    *p = (char*)malloc(maxSize * sizeof(char));

    if(p == NULL)
        printf("Cap phat khong thanh cong!\n");
    else
    {   
        char c;
        while (1)
        {
            printf("Nhap x: ");
            scanf(" %c", &c);

            if(c == '@')
            {
                printf("@ -> Stop\n");
                break;
            } else
            {
                if(*n == maxSize)
                {
                    maxSize *= 2;
                    char *q = (char*)malloc(maxSize * sizeof(char));
                    if (q == NULL) 
                    {
                        printf("Cap phat bo nho that bai!\n");
                        free(*p);
                        return;
                    }

                    for(int i = 0; i < *n; i++)
                    {
                        q[i] = (*p)[i];
                    }

                    free(*p);
                    *p = q;
                }

                (*p)[*n] = c;
                (*n)++; 
            }
        }
    }

}

void printArray(char *p, int n) {
    printf("Day ky tu da nhap la: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", p[i]);
    }
}

int main()
{
    char * p = NULL;
    int n = 0;

    inputArrayExtend(&p, &n);
    printArray(p, n);
    free(p);

    return 0;
}