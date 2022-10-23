/*
LeetCode Problem:409
PROBLEM STATEMENT:
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
Constraints:
1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(string &s){
    unordered_map<char,int> mp;
    //count frequency of each character in string
    for(int i=0;i<s.length();i++) mp[s[i]]++;
    int count=0;
    for(auto it:mp){
        //count the odd frequencies
        if(it.second%2!=0) count++;
    }
    //Remove one char which appears for odd number of times
    if(count>1)
        return s.length()-count+1;
    return s.length();
}

int main(){
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
    return 0;
}