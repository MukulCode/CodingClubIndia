// Equal Strings Problem Code: EQUALSTRINGSolvedSubmit
// Given a string A of length N consisting of lowercase English alphabet letters.

// You are allowed to perform the following operation on the string A any number of times:

// Select a non-empty subsequence S of the array [1,2,3,…,N] and any lowercase English alphabet α;
// Change Ai to α for all i∈S.
// Find the minimum number of operations required to convert A into a given string B of length N consisting of lowercase English alphabet letters.

// Input Format
// The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follow.
// The first line of each test case contains an integer N - the length of the string A and B.
// The second line of each test case contains the string A.
// The third line of each test case contains the string B.
// Output Format
// For each test case, output the minimum number of operations required to convert string A into string B.

// Constraints
// 1≤T≤104
// 1≤N≤105
// Sum of N over all test cases does not exceed 105.
// Sample Input 1 
// 3
// 2
// ab
// cd
// 3
// aaa
// bab
// 4
// abcd
// aaab
// Sample Output 1 
// 2
// 1
// 2
// Explanation
// Test case 1:

// In the first operation, we can choose S={1} and α= c. After this operation, A will become cb.
// In the second operation, we can choose S={2} and α= d. After this operation, A will become cd.
// Test case 2:

// In the first operation, we can choose S={1,3} and α= b. After this operation, A will become bab.
// Test case 3:

// In the first operation, we can choose S={2,3} and α= a. After this operation, A will become aaad.
// In the second operation, we can choose S={4} and α= b. After this operation, A will become aaab.
#include <iostream>
#include <set>
using namespace std;

int main() 
{
    int test;
    cin>>test;
    
    while(test--)
    {
        int num;
        cin>>num;
        
        char str1[num];
        char str2[num];
        
        cin>>str1;
        cin>>str2;
        
        set<char> ss;
        
        for(int i=0;i<num;i++)
        {
            if(str1[i]!=str2[i])
            {
                ss.insert(str2[i]);
            }
        }
        
        cout<<ss.size()<<endl;
    }
	// your code goes here
	return 0;
}
