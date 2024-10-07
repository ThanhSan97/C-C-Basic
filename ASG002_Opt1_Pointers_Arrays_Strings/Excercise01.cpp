#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d/n", &N);

    int *arr = (int *)malloc(N * sizeof(int));

    if (arr == NULL)
        printf("Cap phat khong thanh cong! \n");
    else
    {
        for (int i = 0; i < N; i++)
        {
            printf("Nhap phan tu thu %d: ", i+1);
            scanf("%d:/n", &arr[i]);
        }

        printf("Mang vua nhap:");
        for (int i = 0; i < N; i++)
        {
            printf("%d ", *(arr + i));
        }
        printf("\nGiai phong bo nho");
        free(arr);
    }
    
    return 0;
}