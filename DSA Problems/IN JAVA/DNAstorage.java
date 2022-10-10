// Problem
// For encoding an even-length binary string into a sequence of A, T, C, and G, we iterate from left to right and replace the characters as follows:

// 00 is replaced with A
// 01 is replaced with T
// 10 is replaced with C
// 11 is replaced with G
// Given a binary string SS of length NN (NN is even), find the encoded sequence.

// Input Format
// First line will contain TT, number of test cases. Then the test cases follow.
// Each test case contains two lines of input.
// First line contains a single integer NN, the length of the sequence.
// Second line contains binary string SS of length NN.
// Output Format
// For each test case, output in a single line the encoded sequence.

// Note: Output is case-sensitive.

// Constraints
// 1 \leq T \leq 1001≤T≤100
// 2 \leq N \leq 10^32≤N≤10 
// 3
 
// NN is even.
// Sum of NN over all test cases is at most 10^310 
// 3
//  .
// SS contains only characters 0 and 1.
// Sample 1:
// Input
// Output
// 4
// 2
// 00
// 4
// 0011
// 6
// 101010
// 4
// 1001
// A
// AG
// CCC
// CT
// Explanation:
// Test case 11: Based on the rules 00 is replaced with A.

// Test case 22: Based on the rules 00 is replaced with A. Similarly, 11 is replaced with G. Thus, the encoded sequence is AG.

// Test case 33: The first two characters are 10 which is encoded as C. Similarly, the next two characters 10 are encoded as C and the last two characters 10 are encoded as C. Thus, the encoded string is CCC.

// Test case 44: The first two characters are 10 which is encoded as C. Similarly, the next two characters 01 are encoded as T. Thus, the encoded string is CT.
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class DNAstorage
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner  s = new Scanner(System.in);
	    int t=s.nextInt();
	    while(t-->0)
	    {
	        int n=s.nextInt();
	        String str=s.next();
	        String ans="";
	        for(int i=0;i<n;i+=2)
	        {
	            if(str.charAt(i)=='0' && str.charAt(i+1)=='0'){
	                ans+='A';
	            }
	            else if(str.charAt(i)=='0' && str.charAt(i+1)=='1'){
	                ans+='T';
	            }
	            else if(str.charAt(i)=='1' && str.charAt(i+1)=='0'){
	                ans+='C';
	            }
	            else{
	                ans+='G';
	            }
	        }
	        System.out.println(ans);
	    }
		// your code goes here
	}
}
