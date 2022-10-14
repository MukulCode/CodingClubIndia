/*

Given an array ‘pages’ of integer numbers, where ‘pages[i]’ represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students, and the task is to allocate all the books to their students.

Allocate books in a way such that:

1. Each student gets at least one book.

2. Each book should be allocated to a student.

3. Book allocation should be in a contiguous manner.

You have to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is minimum.


*/
#include <bits/stdc++.h>
using namespace std;
bool isPossible(int arr[], int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
            pageSum += arr[i];
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}
int findPages(int arr[], int n, int m)
{
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int s = 0, e = sum;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 2;
    cout << findPages(arr, n, m);
    return 0;
}