// Himanshu Mohanty
// 2105719
// CSE36
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, max, min;
    int secMax, secMin;
    printf("Enter the number of element in the array:");
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    printf("Enter the element of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    max = ptr[0];
    secMax = ptr[0];
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] > max)
        {
            secMax = max;
            max = ptr[i];
        }
        else if (ptr[i] > secMax)
        {
            secMax = ptr[i];
        }
    }
    min = ptr[0];
    secMin = ptr[1];
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] < min)
        {
            secMin = min;
            min = ptr[i];
        }
    }
    printf("\nSecMax:%d\n", secMax);
    printf("\nSecMin:%d\n", secMin);
    return 0;
}
