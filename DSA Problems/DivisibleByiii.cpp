// Divisible by i Problem Code: DIVBYISolvedSubmit
// You are given an integer N.

// Construct a permutation P of length N such that

// For all i (1≤i≤N−1), i divides abs(Pi+1−Pi).
// Recall that a permutation of length N is an array where every integer from 1 to N occurs exactly once.

// It can be proven that for the given constraints at least one such P always exists.

// Input Format
// The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follow.
// The only line of each test case contains an integer N - the length of the array to be constructed.
// Output Format
// For each test case, output a single line containing N space-separated integers P1,P2,…,PN, denoting the elements of the array P.

// If there exist multiple such arrays, print any.

// Constraints
// 1≤T≤5⋅104
// 2≤N≤105
// The sum of N over all test cases does not exceed 105.
// Sample Input 1 
// 2
// 2
// 3
// Sample Output 1 
// 1 2
// 2 1 3
// Explanation
// Test case 1: A possible array satisfying all the conditions is [1,2]:

// For i=1: abs(A2−A1)=abs(2−1)=1 is divisible by 1.
// Test case 2: A possible array satisfying all the conditions is [2,1,3]:

// For i=1: abs(A2−A1)=abs(1−2)=1 is divisible by 1.
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%2==1)
        {
            for(int i=n/2+1,j=n/2;j>0;j--,i++)
            {
                cout<<i<<" "<<j<<" ";
            }
            cout<<n<<endl;
        }
        else
        {
            for(int i=n/2,j=n/2+1;j<=n;j++,i--)
            {
                cout<<i<<" "<<j<<" ";
            }
            cout<<endl;
        }
    }
	// your code goes here
	return 0;
}

