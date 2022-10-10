#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n)
{
    // optimizing the bubble sort by stopping the algorithm if the inner loop didn’t cause any swap.
    // for this create a boolean variable as follows:
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        // initializing our boolean variable before swapping
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                // if there is no swapping set
                swapped = true;
            }
            
        }
        // now if swapped == false than
        // our array 'arr' is already sorted so,
        if (swapped == false)
        {
            break;
        }
    }
}
int main()
{
    int a[] = {3, 2, 5, 6, 4};
    int m = sizeof(a) / sizeof(a[0]);
    bubbleSort(a, m);
    for (int i = 0; i < m; i++)
    {
        cout << a[i] << " ";
    }
}
