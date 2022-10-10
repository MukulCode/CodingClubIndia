// Alternate Additions Problem Code: ALTERADDSolvedSubmit
// Chef has 2 numbers A and B (A<B).

// Chef will perform some operations on A.

// In the ith operation:

// Chef will add 1 to A if i is odd.
// Chef will add 2 to A if i is even.
// Chef can stop at any instant. Can Chef make A equal to B?

// Input Format
// The first line contains a single integer T — the number of test cases. Then the test cases follow.
// The first and only line of each test case contains two space separated integers A and B.
// Output Format
// For each test case, output YES if Chef can make A and B equal, NO otherwise.

// Note that the checker is case-insensitive. So, YES, Yes, yEs are all considered same.

// Constraints
// 1≤T≤1000
// 1≤A<B≤109
// Sample Input 1 
// 4
// 1 2
// 3 6
// 4 9
// 10 20
// Sample Output 1 
// YES
// YES
// NO
// YES
// Explanation
// Test case 1: Chef may perform one operation to make A equal to B: 1−→+12
// Test case 2: 3−→+14−→+26
// Test case 3: It can be shown that it is impossible to make A and B equal.

// Test case 4:  10−→+111−→+213−→+114−→+216−→+117−→+219−→+120
#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if((y-x)%3==0)
        cout<<"YES"<<endl;
        else if((y-x)%3!=0 and (y-x)%3==1)
             cout<<"YES"<<endl;
             else
             cout<<"NO"<<endl;
    }

	// your code goes here
	return 0;
}
