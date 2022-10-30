// Code in cpp to tell if there exists a pair in array whose
// sum results in x.
#include <iostream>
using namespace std;
 
// Function to print pairs
void printPairs(int a[], int n, int x)
{
    int i;
    int rem[x];
    // initializing the rem values with 0's.
    for (i = 0; i < x; i++)
        rem[i] = 0;
    // Perform the remainder operation only if the element
    // is x, as numbers greater than x can't be used to get
    // a sum x. Updating the count of remainders.
    for (i = 0; i < n; i++)
        if (a[i] < x)
            rem[a[i] % x]++;
 
    // Traversing the remainder list from start to middle to
    // find pairs
    for (i = 1; i < x / 2; i++) {
        if (rem[i] > 0 && rem[x - i] > 0) {
            // The elements with remainders i and x-i will
            // result to a sum of x. Once we get two
            // elements which add up to x , we print x and
            // break.
            cout << "Yes\n";
            break;
        }
    }
 
    // Once we reach middle of remainder array, we have to
    // do operations based on x.
    if (i >= x / 2) {
        if (x % 2 == 0) {
            // if x is even and we have more than 1 elements
            // with remainder x/2, then we will have two
            // distinct elements which add up to x. if we
            // dont have more than 1 element, print "No".
            if (rem[x / 2] > 1)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else {
            // When x is odd we continue the same process
            // which we did in previous loop.
            if (rem[x / 2] > 0 && rem[x - x / 2] > 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}
 

int main()
{
    int A[] = { 1, 4, 45, 6, 10, 8 };
    int n = 16;
    int arr_size = sizeof(A) / sizeof(A[0]);
 
    // Function calling
    printPairs(A, arr_size, n);
 
    return 0;
}
//Time Complexity== O(N+X);
//Auxiliary Space: O(X)
