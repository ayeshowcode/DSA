#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void combSort(int A[], int n)
{
    bool swapped = true;
    for (float gap = n / 1.3; gap > 1 || swapped == true; gap /= 1.3)
    {
        swapped = false;
        if (gap < 1)
            gap = 1;
        int igap = int(gap);
        for (int i = 0; i + igap < n; i++)
        {
            if (A[i] > A[i + igap])
            {
                int temp = A[i];
                A[i] = A[i + igap];
                A[i + igap] = temp;
                swapped = true;
            }
        }
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    combSort(A, n);
    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
